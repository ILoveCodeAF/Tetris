#include "Vec3.h"

Vec3::Vec3(){
	this->x = this->y = this->z = 0;
}

Vec3::Vec3(int x, int y, int z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3 Vec3::get(){
	return *this;
}

int Vec3::getx(){
	return this->x;
}

int Vec3::gety(){
	return this->y;
}

int Vec3::getz(){
	return this->z;
}
