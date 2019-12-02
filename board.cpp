#include "vec3.h"
#include "shape.h"
#include "board.h"
#include "tetris.h"
#include "config.h"

#include <iostream>
#include <exception>


Cell::Cell(){
	this->has_brick = 0;
}

Board::Board(){
	this->height = BOARD_HEIGHT;
	this->width = BOARD_WIDTH;
	this->board = new Cell[this->height*this->width];
	this->is_full = false;
}

Board::~Board(){}

Cell* Board::get_board(){
	return this->board;
}

int Board::get_width(){
	return this->width;
}

int Board::get_height(){
	return this->height;
}

void Board::add(Shape shape, int xpos, int ypos){
	int i = 0;
	int j = 0;
	if(ypos == 0)
		this->is_full = true;
	unsigned char* shape_arr = shape.get_shape();
	Vec3 color = shape.get_color(); 
	while(i < shape.get_height()){
		j = 0;
		while(j < shape.get_width()){
			if(shape_arr[i*shape.get_width() + j]){
				board[(ypos+i)*this->width+xpos+j].color = color;
				board[(ypos+i)*this->width+xpos+j].has_brick = 1;
			}
			++j;
		}
		++i;
	}
}

void Board::print(){
	int i = 0;
	int j = 0;
	std::cout<<"\n-----------------------\n";
	while(i < this->height){
		j = 0;
		while(j < this->width){
			if(this->board[i*this->width + j].has_brick)
				std::cout<<'#';
			else
				std::cout<<' ';
			++j;
		}
		std::cout<<'\n';
		++i;
	}
	std::cout<<"\n-----------------------\n";
}

bool Board::full(){
	return this->is_full;
}

Cell Board::get_cell(int i, int j){
	if(i < 0 || i >= this->height || j < 0 || j >= this->width){
		throw "out of range: board.get_cell";
	}
	return this->board[i*this->width+j];
}
