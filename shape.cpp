#include "shape.h"

Shape::Shape(char ch, unsigned char*** shape, Vec3 col, int num_state, int c_state){
	this->character = ch;
	this->shape = shape;
	this->color = col;
	this->num_state = num_state;
	this->current_state = c_state;
}

char Shape::get_character(){
	return this->character;
}

Vec3 Shape::get_color(){
	return this->color;
}

unsigned char** Shape::get_shape(){
	return this->shape[current_state];
}

void Shape::change_state(int n){
	this->current_state += n;
	while(this->current_state < 0)
		this->current_state += this->num_state;
	this->current_state %= this->num_state;
}
