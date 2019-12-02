#ifndef __UI_H_INCLUDED__
#define __UI_H_INCLUDED__

#include "board.h"
#include "shape.h"

class Window{
	private:
		int window_width;
		int window_height;
		char* light_shape;
		char* full_block;
		char* blank;
		char* right_border;
		char* left_border;
		char* bottom_border;

		void gotoxy(int x, int y);
		void resize_event();
	public:
		Window();
		~Window();
		void clear();
		void draw(Board board, int x, int y);
		void draw(Shape shape, int x, int y, bool shadow = false);
};

#endif
