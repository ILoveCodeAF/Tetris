#include "vec4.h"

Vec4::Vec4(){
	this->r = this->g = this->b = 0;
	this->a = 1;
}

Vec4::Vec4(float r, float g, float b):
	r(r), g(g), b(b), a(1)
{}

Vec4::Vec4(float r, float g, float b, float a):
	r(r), g(g), b(b), a(a)
{}

Vec4::Vec4(const Vec4& vec4):
	r(vec4.r), g(vec4.g), b(vec4.b), a(vec4.a)
{}

Vec4& Vec4::operator=(const Vec4 &vec4){
	if(this == &vec4)
		return *this;
	this->set(vec4);
	return *this;
}

Vec4& Vec4::operator=(const Vec4 &&vec4){
	if(this == &vec4)
		return *this;
	this->set(vec4);
	return *this;
}

Vec4::Vec4(const Vec4 &&vec4):
	r(vec4.r), g(vec4.g), b(vec4.b), a(vec4.a)
{}

Vec4::~Vec4(){}

void Vec4::set(float r, float g, float b, float a) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Vec4::set(const Vec4 &vec4) {
	this->r = vec4.getr();
	this->g = vec4.getg();
	this->b = vec4.getb();
	this->a = vec4.geta();
}

Vec4 Vec4::get() const{
	return *this;
}

float Vec4::getr() const{
	return this->r;
}

float Vec4::getg() const{
	return this->g;
}

float Vec4::getb() const{
	return this->b;
}

float Vec4::geta() const{
	return this->a;
}

std::ostream& operator<<(std::ostream& out, const Vec4 &vec4){
	out<<"vec4 : (r="<<vec4.getr();
	out<<", g="<<vec4.getg();
	out<<", b="<<vec4.getb();
	out<<", a="<<vec4.geta()<<")";
	return out;
}
