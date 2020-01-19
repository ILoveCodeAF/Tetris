#ifndef __SHAPE_H_INCLUDED__
#define __SHAPE_H_INCLUDED__

#include "vec4.h"

class Shape{
	private:
		char character;
		unsigned char **states;
		int width;
		int height;
		Vec4 color;
		int num_state;
		int current_state;
		
		Shape(const Shape &);
		void free();
		void print(int state);
	public:
		Shape();
		Shape(char ch, unsigned char **states, int w, int h, Vec4 col, int num_state);
		Shape& operator=(const Shape &);
		Shape& operator=(const Shape &&);
		~Shape();
		char get_character() const;
		int get_width() const;
		int get_height() const;
		Vec4 get_color() const;
		unsigned char* get_shape() const;
		int get_num_state() const;
		void change_state(int n);
		unsigned char **get_states() const;
		int get_current_state() const;
		void print();
		static Shape* load_shape(const char* filename);
};

#endif
