#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include <array>
#include "vec4.h"
#include "tetrimino.h"

#define FIELD_HEIGHT 22
#define FIELD_WIDTH 10

class Board{
	private:
		int width, height;
		std::array<std::array<Vec4, FIELD_WIDTH>, FIELD_HEIGHT> playfield;
	public:
		Board();
		~Board();
		std::array<std::array<Vec4, FIELD_WIDTH>, FIELD_HEIGHT> get_playfield() const;
		int get_height() const;
		int get_width() const;
		void add(Tetrimino tetrimino, int xpos, int ypos);
		void print() const;
		bool full();
		Vec4 get_cell(int i, int j) const;
};

#endif
