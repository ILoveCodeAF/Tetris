#include <stdio.h>
#include "ui.h"
#include <signal.h>
#include <sys/ioctl.h>

Window::Window(){
	winsize ws;
	ioctl(fileno(stdout), TIOCGWINSZ, &ws);
	this->window_width = ws.ws_col;
	this->window_height = ws.ws_row;

	this->light_shape = new char[3];
	this->light_shape[0] = 0xE2;
	this->light_shape[1] = 0x96;
	this->light_shape[2] = 0x91;
	
	this->full_block = new char[3];
	this->full_block[0] = 0xE2;
	this->full_block[1] = 0x96;
	this->full_block[2] = 0x88;

	this->blank = new char[2];
	this->blank[0] = this->blank[1] = ' ';

	this->left_border = new char[3];
	this->left_border[0] = 0xE2;
	this->left_border[1] = 0x96;
	this->left_border[2] = 0x95;
	
	this->right_border = new char[3];
	this->right_border[0] = 0xE2;
	this->right_border[1] = 0x96;
	this->right_border[2] = 0x8F;

	this->bottom_border = new char[3];
	this->bottom_border[0] = 0xE2;
	this->bottom_border[1] = 0x96;
	this->bottom_border[2] = 0x94;
}

Window::~Window(){
	if(this->light_shape != NULL){
		delete[] this->light_shape;
	}
	if(this->full_block != NULL){
		delete[] this->full_block;
	}
	if(this->blank != NULL){
		delete[] this->blank;
	}
	if(this->right_border != NULL){
		delete[] this->right_border;
	}
	if(this->left_border != NULL){
		delete[] this->left_border;
	}
	if(this->bottom_border != NULL){
		delete[] this->bottom_border;
	}
}

void Window::resize_event(){
	winsize ws;
	ioctl(fileno(stdout), TIOCGWINSZ, &ws);
	this->window_width = ws.ws_col;
	this->window_height = ws.ws_row;
}

void Window::gotoxy(int x, int y){
	printf("%c[%d;%df", 0x1B, y, x);
}

void Window::clear(){
	int i = 0;
	int j;

	this->gotoxy(0, 0);
	while(i < this->window_height){
		j = 0;
		while(j < this->window_width){
			printf(" ");
			++j;
		}
		++i;
	}
}

void Window::draw(Board board, int x, int y){
	int i = 2;
	int j = 0;
	Cell cell;
	while(i < board.get_height()+1){
		j = 0;
		this->gotoxy(y, y+j);
		while(j < board.get_width()+2){
			if(i == board.get_height()){
				printf("%s", bottom_border);
			}
			else{
				if(j == 0){
					printf("%s", left_border); 
				}
				else if(j == board.get_width()+1){
					printf("%s", right_border);
				}
				else{
					cell = board.get_cell(i, j-1);
					if(cell.has_brick){
						printf("%s%s", this->full_block, this->full_block);
					}
					else
						printf("%s%s", this->blank, this->blank);
				}
			}
			++j;
		}
		++i;
	}
}


