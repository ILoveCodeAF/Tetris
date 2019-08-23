#ifndef __SHAPE_H_INCLUDED__
#define __SHAPE_H_INLCUDE__

#include "vec3.h"

class Shape{
	private:
		char character;
		unsigned char*** shape;
		Vec3 color;
		int num_state;
		int current_state;
	public:
		Shape(char ch, unsigned char*** shape, Vec3 col, int num_state, int c_state);
		char get_character();
		Vec3 get_color();
		int get_shape();
		void change_state(int n);
};

#endif
