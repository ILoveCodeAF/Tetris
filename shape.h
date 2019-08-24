#ifndef __SHAPE_H_INCLUDED__
#define __SHAPE_H_INCLUDED__

#include "vec3.h"

class Shape{
	private:
		char character;
		unsigned char** shapes;
		int width;
		int height;
		Vec3 color;
		int num_state;
		int current_state;
		unsigned char* gen_shape(unsigned char* spawn_shape);
		void print(int state);
	public:
		Shape();
		Shape(char ch, unsigned char* spawn_shape, int w, int h, Vec3 col, int num_state);
		~Shape();
		char get_character();
		int get_width();
		int get_height();
		Vec3 get_color();
		unsigned char* get_shape();
		void change_state(int n);
		int get_state(int n);
		int get_current_state();
		void print();
		static Shape* load_shape(char* filename);
};

#endif
