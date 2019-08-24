#include "shape.h"
#include <iostream>
#include <fstream>

Shape::Shape(){}

Shape::Shape(char ch, unsigned char* spawn_shape, int w, int h, Vec3 col, int num_state){
	this->character = ch;
	this->width = w;
	this->height = h;
	this->color = col;
	this->num_state = num_state;
	this->current_state = 0;
	int i = 1;
	this->shapes = new unsigned char*[this->num_state];
	this->shapes[0] = spawn_shape;
	while(i < this->num_state){
		this->shapes[i] = this->gen_shape(this->shapes[i-1]);
		++i;
	}
}

Shape::~Shape(){}

unsigned char* Shape::gen_shape(unsigned char* spawn_shape){
	if(this->width != this->height || this->num_state < 2)
		return NULL;
	int i = 0;
	int j = 0;
	int n = this->height;
	unsigned char* shape = new unsigned char[n*n];
	while(i < n){
		j = 0;
		while(j < n){
			shape[j*n+n-i-1] = spawn_shape[i*n+j];
			++j;
		}
		++i;
	}
	return shape;
}

char Shape::get_character(){
	return this->character;
}

int Shape::get_width(){
	return this->width;
}

int Shape::get_height(){
	return this->height;
}

Vec3 Shape::get_color(){
	return this->color;
}

unsigned char* Shape::get_shape(){
	return this->shapes[current_state];
}

void Shape::change_state(int n){
	this->current_state += n;
	while(this->current_state < 0)
		this->current_state += this->num_state;
	this->current_state %= this->num_state;
}

int Shape::get_state(int n){
	int c_state = this->current_state;
	this->change_state(n);
	int ret = this->current_state;
	this->current_state = c_state;
	return ret;
}

int Shape::get_current_state(){
	return this->current_state;
}

void Shape::print(int state){
	int i = 0;
	int j = 0;
	while(i < this->height){
		j = 0;
		while(j < this->width){
			std::cout<<this->shapes[state][i*this->width+j];
			j++;
		}
		std::cout<<std::endl;
		i++;
	}
}
void Shape::print(){
	int i = 0;
	while(i < this->num_state){
		this->print(i);
		std::cout<<std::endl;
		++i;
	}
}

Shape* Shape::load_shape(char* filename){
	Shape* shapes;
	char ch;
	unsigned char* shape;
	int w, h, x, y, z;
	Vec3 col;
	int num_state;
	std::ifstream infile;
	infile.open(filename, std::ios::in);
	int n;
	infile>>n;
	shapes = new Shape[n];
	int i = 0, j = 0, k = 0;
	while(i < n){
		infile>>ch>>num_state>>w>>h;
		j = 0;
		shape = new unsigned char[w*h];
		while(j < h){
			k = 0;
			while(k < w){
				infile>>shape[j*w+k];
				++k;
			}
			++j;
		}
		infile>>x>>y>>z;
		col.set(x, y, z);
		Shape shp(ch, shape, w, h, col, num_state);
		shapes[0] = shp;
		++i;
	}
	infile.close();
	return shapes;
}
