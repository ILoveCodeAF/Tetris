#include "vec3.h"

Vec3::Vec3(){
	this->x = this->y = this->z = 0;
}

Vec3::Vec3(int x, int y, int z):
	x(x), y(y), z(z)
{}

Vec3::Vec3(const Vec3& vec):
	x(vec.x), y(vec.y), z(vec.z)
{}

Vec3& Vec3::operator=(const Vec3 &vec3){
	if(this == &vec3)
		return *this;
	Vec3 temp(vec3.x, vec3.y, vec3.z);
	*this = temp;
	return *this;
}

Vec3& Vec3::operator=(const Vec3 &&vec3){
	if(this == &vec3)
		return *this;
	this->set(vec3.x, vec3.y, vec3.z);
	return *this;
}

Vec3::Vec3(const Vec3 &&vec3):
	x(vec3.x), y(vec3.y), z(vec3.z)
{}
//Vec3& operator=(Vec3& vec3){
//	this->x = vec3.getx();
//	this->y = vec3.gety();
//	this->z = vec4.getz();
//}

Vec3::~Vec3(){}

void Vec3::set(int x, int y, int z){
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
