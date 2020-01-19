#include "shape.h"
#include <iostream>
#include <fstream>

Shape::Shape(){}

Shape::Shape(char ch, unsigned char **states, int w, int h, Vec4 col, int num_state){
	this->character = ch;
	this->states = states;
	this->width = w;
	this->height = h;
	this->color = col;
	this->num_state = num_state;
	this->current_state = 0;
}

Shape& Shape::operator=(const Shape &shape){
	if (this == &shape)
		return *this;
	this->character = shape.get_character();
	this->states = shape.get_states();
	this->width = shape.get_width();
	this->height = shape.get_height();
	this->color = shape.get_color();
	this->num_state = shape.get_num_state();
	this->current_state = shape.get_current_state();
	return *this;
}

Shape& Shape::operator=(const Shape &&shape){
	if (this == &shape)
		return *this;
	this->character = shape.get_character();
	this->states = shape.get_states();
	this->width = shape.get_width();
	this->height = shape.get_height();
	this->color = shape.get_color();
	this->num_state = shape.get_num_state();
	this->current_state = shape.get_current_state();
	return *this;
}

Shape::~Shape(){
	if(this->states != NULL){
		for(int i = this->num_state-1; i > 0; ++i){
			if (this->states[i] != NULL)
				delete[] this->states[i];
		}
		delete[] this->states;
	}
}

void Shape::free(){
	this->character = ' ';
	this->states = NULL;
	this->width = this->height = 0;
	this->num_state = this->current_state = 0;
}

char Shape::get_character() const{
	return this->character;
}

int Shape::get_width() const{
	return this->width;
}

int Shape::get_height() const{
	return this->height;
}

Vec4 Shape::get_color() const{
	return this->color;
}

unsigned char *Shape::get_shape() const{
	return this->states[current_state];
}

int Shape::get_num_state() const{
	return this->num_state;
}

void Shape::change_state(int n){
	this->current_state += n;
	this->current_state %= this->num_state;
	if(this->current_state < 0)
		this->current_state += this->num_state;
}

unsigned char **Shape::get_states() const{
	return this->states;
}

int Shape::get_current_state() const{
	return this->current_state;
}

void Shape::print(int state_num){
	int i = 0;
	int j = 0;
	while(i < this->height){
		j = 0;
		while(j < this->width){
			std::cout<<this->states[state_num][i*this->width+j];
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

Shape *Shape::load_shape(const char *filename){
	Shape *shapes;
	char ch;
	unsigned char **states;
	int w, h, r, g, b, a;
	w = h = r = g = b = a = 0;
	Vec4 col;
	int num_state;
	std::ifstream infile;
	infile.open(filename, std::ios::in);
	int n;
	infile >> n;
	
	shapes = new Shape[n];
	int i = 0, j = 0, k = 0, m = 0;
	while(i < n){
		infile >> ch >> num_state >> h >> w;
		j = 0;
		states = new unsigned char*[num_state];
		while(j < num_state){
			k = 0;
			states[j] = new unsigned char[w*h];
			while(k < h){
				m = 0;
				while(m < w){
					infile>>states[j][k*w+m];
					m++;
				}
				++k;
			}
			++j;
		}
		infile >> r >> g >> b;
		col.set(r, g, b, 1);
		Shape shp(ch, states, w, h, col, num_state);
		shapes[i] = shp;
		shp.free();
		++i;
	}
	infile.close();
	return shapes;
}
