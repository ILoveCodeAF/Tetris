#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include "vec3.h"
#include "shape.h"

struct Cell{
	Vec3 color;
	bool has_brick;
	Cell();
};

class Board{
	private:
		int height;
		int width;
		Cell* board;
   	public:
		Board();
		~Board();
		Cell* get_board();
		int get_height();
		int get_width();
		void add(Shape shape, int xpos, int ypos);
		void print();
};

#endif
