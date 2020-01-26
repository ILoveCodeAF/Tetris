#include "board.h"
#include <iostream>
#include <exception>

Board::Board():
	width(FIELD_WIDTH), height(FIELD_HEIGHT)
{}

Board::~Board(){}

std::array<std::array<Vec4, FIELD_WIDTH>, FIELD_HEIGHT> 
Board::get_playfield() const{
	return this->playfield;
}

int Board::get_width() const{
	return this->width;
}

int Board::get_height() const{
	return this->height;
}

void Board::add(Tetrimino tetrimino, int xpos, int ypos){
	int i = 0;
	int j = 0;
	Vec4 vec;
	Vec4 *tetrimino_arr = tetrimino.get_tetrimino();
	while(i < tetrimino.get_height()){
		j = 0;
		while(j < tetrimino.get_width()){
			if(tetrimino_arr[i*tetrimino.get_width()+j]	!= vec){
				if(ypos+i >= 0 && ypos+i < this->height
						&& xpos+j >= 0 && xpos+j < this->width)
					playfield[ypos+i][xpos+j] = 
						tetrimino_arr[i*tetrimino.get_width()+j];
			}
			++j;
		}
		++i;
	}
}

void Board::print() const{
	int i = 0;
	int j = 0;
	Vec4 vec;
	std::cout<<"\n-----------------------\n";
	while(i < this->height){
		j = 0;
		while(j < this->width){
			if(this->playfield[i][j] == vec)
				std::cout<<' ';
			else
				std::cout<<'#';
			++j;
		}
		std::cout<<'\n';
		++i;
	}
	std::cout<<"\n-----------------------\n";
}

Vec4 Board::get_cell(int i, int j) const{
	if(i < 0 || i >= this->height || j < 0 || j >= this->width){
		throw "out of range: playfield.get_cell";
	}
	return this->playfield[i][j];
}
