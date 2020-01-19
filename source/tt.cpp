#include "shape.h"
#include "vec4.h"
#include <iostream>

int main(){
	//
	//Shape* shps = Shape::load_shape("data/shapes.txt");
	unsigned char **state = new unsigned char*[1];
	state[0] = new unsigned char[12];
	Vec4 vec4(1, 1, 0, 1);
	Vec4 vec;
	vec = vec4;
	std::cout<<vec<<std::endl;
	Shape sh('t', state, 3, 4, vec4, 1);
	sh.print();

	Shape* shps = Shape::load_shape("data/shapes.txt");

	for(int i = 0; i < 7; ++i){
		std::cout<<"----------------\n";
		shps[i].print();
	}
	return 0;
}
