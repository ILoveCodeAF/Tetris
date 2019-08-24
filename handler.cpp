#include "handler.h"
#include "board.h"
#include "queue.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>

pair::pair(){}

pair::pair(int f, int s){
	this->first = f;
	this->second = s;
}

Handler::Handler(){
	this->xpos = 0;
	this->ypos = this->board.get_width()/2-2;
	this->shapes = Shape::load_shape("shapes.txt");
	srand(time(NULL));
	int random;
	this->num_shape = 7;
	this->queue_size = 5;
	while(!this->queue.full()){
		random = rand()%this->num_shape;
		queue.push(shapes[random]);
	}
	int m, n;
	std::ifstream infile;
	infile.open("wall_kick.txt", std::ios::in);
	infile>>n>>m;
	int i = 0;
	int j;
	this->wall_kick = new pair[n*m];
	while(i < n){
		j = 0;
		while(j < m){
			infile>>this->wall_kick[i*m+j].first;
			infile>>this->wall_kick[i*m+j].second;
			++j;
		}
		++i;
	}
	i = 0;
	while(i < n){
		j = 0;
		while(j < m){
			infile>>this->wall_kick_i[i*m+j].first;
			infile>>this->wall_kick_i[i*m+j].second;
			++j;
		}
		++i;
	}
	infile.close();
	this->wWall = m;
	this->hWall = n;
}

Handler::~Handler(){}

Shape Handler::get_shape(){
	return this->shape;
}

Board Handler::get_board(){
	return this->board;
}

Shape* Handler::get_queue(){
	return this->queue.get_queue();
}

bool Handler::rotate(Control control){
	if(this->shape.get_character() == 'O')
		return false;
	int row;
	//tobe continue
}

bool Handler::move(Control control){
	int delta = 0;
	if(control == Control::LEFT){
		delta = -1;
	}
	else if(control == Control::RIGHT){
		delta = 1;
	}
	else
		return false;
	this->xpos += delta;
	if(this->has_collision()){
		this->xpos -= delta;
		return false;
	}
	return true;
}

bool Handler::has_collision(){
	Cell* cells = this->board.get_board();
	unsigned char* shape_arr = this->shape.get_shape();
	int i = 0;
	int j = 0;
	while(i < this->shape.get_height()){
		j = 0;
		while(j < this->shape.get_width()){
			if(shape_arr[i*this->shape.get_width()+j]){
				if((i+ypos) >= this->board.get_height()
						|| (j+xpos)<0
						|| (j+xpos) >= this->board.get_width()
						|| cells[(i+ypos)*this->board.get_width()+j+xpos].has_brick)
					return true;
			}
			++j;
		}
		++i;
	}
	return false;
}
