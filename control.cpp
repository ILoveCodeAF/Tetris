#include "control.h"
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

Control::Control(){
	srand(time(NULL));

	this->ypos = 0;
	this->xpos = this->board.get_width()/2-2;
	this->shapes = Shape::load_shape("data/shapes.txt");
	srand(time(NULL));
	int random;
	this->num_shape = 7;
	this->queue_size = 5;
	while(!this->queue.full()){
		random = rand()%this->num_shape;
		queue.push(shapes[random]);
	}
	this->is_holded = false;
	this->holed_shape = NULL;
	int m, n;
	std::ifstream infile;
	infile.open("data/wall_kick.txt", std::ios::in);
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

Control::~Control(){}

Shape Control::get_shape(){
	return this->shape;
}

Board Control::get_board(){
	return this->board;
}

Shape* Control::get_queue(){
	return this->queue.get_queue();
}

int Control::get_xpos(){
	return this->xpos;
}

int Control::get_ypos(){
	return this->ypos;
}

int Control::get_ylandedpos(){
	return this->ylandedpos;
}

bool Control::rotate(ControlKey control_key){
	if(this->shape.get_character() == 'O')
		return false;
	int row;
	int current_state = this->shape.get_current_state();
	int delta;
	if(control_key == ControlKey::ROTATE_CLOCKWISE)
		delta = 1;
	else if(control_key == ControlKey::ROTATE_ANTICLOCKWISE)
		delta = -1;
	switch(current_state){
		case 0:
			if(delta > 0)
				row = 0;
			else
				row = 7;
			break;
		case 1:
			if(delta > 0)
				row = 2;
			else
				row = 1;
			break;
		case 2:
			if(delta > 0)
				row = 4;
			else
				row = 3;
			break;
		case 3:
			if(delta > 0)
				row = 6;
			else
				row = 5;
			break;
	}
	pair* wk;
	if(this->shape.get_character() == 'I'){
		wk = this->wall_kick_i;
	}
	else{
		wk = this->wall_kick;
	}
	this->shape.change_state(delta);
	int i = 0;
	while(i < this->wWall){
		this->ypos += wk[row*this->wWall+i].first;
		this->xpos += wk[row*this->wWall+i].second;
		if(!this->has_collision())
			break;
		this->ypos -= wk[row*this->wWall+i].first;
		this->xpos -= wk[row*this->wWall+i].second;
		++i;
	}
	if(i == this->wWall)
		return false;
	return true;
}

bool Control::move(ControlKey control_key){
	int delta = 0;
	if(control_key == ControlKey::LEFT){
		delta = -1;
	}
	else if(control_key == ControlKey::RIGHT){
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

bool Control::has_collision(){
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

void Control::hold(){
	if(this->is_holded){
		Shape shp = this->holded_shape;
		this->holded_shape = this->shape;
		this->shape = shp;
		if(this->shape == NULL){
			this.spawn();
		}
		this->reset();
		this->is_holded = false;
	}
}

void Control::spawn(){
	this->shape = this->queue.front();
	this->queue.pop();
	int r = rand()%this->num_shape;
	this->queue.push(this->shapes[r]);
}

void Control::reset(){
	tthis->ypos = 0;
	this->xpos = this->board.get_width()/2-2;
}

bool Control::land(){
}

int Control::preview_landing_place(){
	int i, j;
	unsigned char* check = new unsigned char[this->shape.get_width()];
	i = 0;
	while(i < this->shape.get_width()){
		check[i] = 1;
		++i;
	}
	i = this->shape.get_height()-1;
	unsigned char* shape_arr = this->shape.get_shape();
	while(i >= 0){
		j = 0;
		while(j < this->shape.get_width()){
			if(check[j] == 1 && shape_arr[i*this->shape.get_width()+j])
				check[j] = i+1-this->shape.get_height();
			++j;
		}
		++i;
	}
	i = ;
	int ylandedpos = 0;
	while(i >= 0){
		j = 0;
		while(j < this->shape.get_width()){
			//your code here
		}
	}
	return ylandedpos; 
}
