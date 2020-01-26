#include "tetrimino.h"
#include <iostream>
#include <fstream>

Tetrimino::Tetrimino(){
	this->free();
}

Tetrimino::Tetrimino(char ch, Vec4 **states, int w, int h, int num_state){
	this->character = ch;
	this->states = states;
	this->width = w;
	this->height = h;
	this->num_state = num_state;
	this->current_state = 0;
}

Tetrimino::Tetrimino(const Tetrimino &tetrimino){
	this->character = tetrimino.character;
	this->width = tetrimino.width;
	this->height = tetrimino.height;
	this->num_state = tetrimino.num_state;
	this->current_state = tetrimino.current_state;
	
	this->states = new Vec4*[this->num_state];
	for(int i = 0; i < this->num_state; ++i){
		this->states[i] = new Vec4[this->width*this->height];
		for(int j = 0; j < this->width*this->height; ++j)
			this->states[i][j] = tetrimino.states[i][j];
	}
}

void Tetrimino::_copy(const Tetrimino &tetrimino){
	if (this->num_state != tetrimino.num_state 
			|| this->width*this->height != 
			tetrimino.width*tetrimino.height){
		std::cout<<"------hello------";
		this->~Tetrimino();//call destructor;
		this->states = new Vec4*[tetrimino.num_state];
		for(int i = 0; i < tetrimino.num_state; ++i){
			this->states[i] = 
				new Vec4[tetrimino.width*tetrimino.height];
		}
	}
	this->character = tetrimino.character;
	this->current_state = tetrimino.current_state;

	this->num_state = tetrimino.num_state;
	this->width = tetrimino.width;
	this->height = tetrimino.height;
	for(int i = 0; i < this->num_state; ++i){
		for(int j = 0; j < this->width*this->height; ++j)
			this->states[i][j] = tetrimino.states[i][j];
	}
}

Tetrimino& Tetrimino::operator=(const Tetrimino &tetrimino){
	if (this == &tetrimino)
		return *this;
	
	this->_copy(tetrimino);	
	return *this;
}

Tetrimino& Tetrimino::operator=(const Tetrimino &&tetrimino){
	std::cout<<"-------=&& called---------";
	if (this == &tetrimino)
		return *this;
	
	this->_copy(tetrimino);
	return *this;
}

Tetrimino::~Tetrimino(){
	if(this->states != NULL){
		for(int i = this->num_state-1; i > 0; --i){
			if (this->states[i] != NULL)
				delete[] this->states[i];
		}
		delete[] this->states;
	}
	this->free();
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

Vec4 *Tetrimino::get_tetrimino() const{
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

Vec4 **Tetrimino::get_states() const{
	return this->states;
}

int Tetrimino::get_current_state() const{
	return this->current_state;
}

void Tetrimino::print(int state_num) const{
	int i = 0;
	int j = 0;
	Vec4 vec;
	while(i < this->height){
		j = 0;
		while(j < this->width){
			if(this->states[state_num][i*this->width+j] == vec){
				std::cout<<'0';
			}
			else
				std::cout<<'1';
			j++;
		}
		std::cout<<std::endl;
		i++;
	}
}
void Tetrimino::print() const{
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
	Vec4 **states;
	int w, h, r, g, b, a;
	w = h = r = g = b = a = 0;
	Vec4 col;
	int num_state;
	std::ifstream infile;
	infile.open(filename, std::ios::in);
	int n;
	infile >> n;
	
	tetriminos = new Tetrimino[n];
	int i = 0, j = 0, k = 0, m = 0, is_not_zezo;
	while(i < n){
		infile >> ch >> num_state >> h >> w;
		infile >> r >> g >> b;
		col.set(r, g, b, 1);

		j = 0;
		states = new Vec4*[num_state];
		while(j < num_state){
			k = 0;
			states[j] = new Vec4[w*h];
			while(k < h){
				m = 0;
				while(m < w){
					infile>>is_not_zezo;

					if(is_not_zezo)
						states[j][k*w+m] = col;
					m++;
				}
				++k;
			}
			++j;
		}
		Tetrimino tetrimino(ch, states, w, h, num_state);
		tetriminos[i] = tetrimino;
		tetrimino.free();
		++i;
	}
	infile.close();
	return tetriminos;
}
