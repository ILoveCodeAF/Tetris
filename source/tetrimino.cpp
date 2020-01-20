#include "tetrimino.h"
#include <iostream>
#include <fstream>

Tetrimino::Tetrimino(){}

Tetrimino::Tetrimino(char ch, unsigned char **states, int w, int h, Vec4 col, int num_state){
	this->character = ch;
	this->states = states;
	this->width = w;
	this->height = h;
	this->color = col;
	this->num_state = num_state;
	this->current_state = 0;
}

Tetrimino& Tetrimino::operator=(const Tetrimino &tetrimino){
	if (this == &tetrimino)
		return *this;
	this->character = tetrimino.get_character();
	this->states = tetrimino.get_states();
	this->width = tetrimino.get_width();
	this->height = tetrimino.get_height();
	this->color = tetrimino.get_color();
	this->num_state = tetrimino.get_num_state();
	this->current_state = tetrimino.get_current_state();
	return *this;
}

Tetrimino& Tetrimino::operator=(const Tetrimino &&tetrimino){
	if (this == &tetrimino)
		return *this;
	this->character = tetrimino.get_character();
	this->states = tetrimino.get_states();
	this->width = tetrimino.get_width();
	this->height = tetrimino.get_height();
	this->color = tetrimino.get_color();
	this->num_state = tetrimino.get_num_state();
	this->current_state = tetrimino.get_current_state();
	return *this;
}

Tetrimino::~Tetrimino(){
	if(this->states != NULL){
		for(int i = this->num_state-1; i > 0; ++i){
			if (this->states[i] != NULL)
				delete[] this->states[i];
		}
		delete[] this->states;
	}
}

void Tetrimino::free(){
	this->character = ' ';
	this->states = NULL;
	this->width = this->height = 0;
	this->num_state = this->current_state = 0;
}

char Tetrimino::get_character() const{
	return this->character;
}

int Tetrimino::get_width() const{
	return this->width;
}

int Tetrimino::get_height() const{
	return this->height;
}

Vec4 Tetrimino::get_color() const{
	return this->color;
}

unsigned char *Tetrimino::get_tetrimino() const{
	return this->states[current_state];
}

int Tetrimino::get_num_state() const{
	return this->num_state;
}

void Tetrimino::change_state(int n){
	this->current_state += n;
	this->current_state %= this->num_state;
	if(this->current_state < 0)
		this->current_state += this->num_state;
}

unsigned char **Tetrimino::get_states() const{
	return this->states;
}

int Tetrimino::get_current_state() const{
	return this->current_state;
}

void Tetrimino::print(int state_num){
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
void Tetrimino::print(){
	int i = 0;
	while(i < this->num_state){
		this->print(i);
		std::cout<<std::endl;
		++i;
	}
}

Tetrimino *Tetrimino::load_tetrimino(const char *filename){
	Tetrimino *tetriminos;
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
	
	tetriminos = new Tetrimino[n];
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
		Tetrimino tetrimino(ch, states, w, h, col, num_state);
		tetriminos[i] = tetrimino;
		tetrimino.free();
		++i;
	}
	infile.close();
	return tetriminos;
}
