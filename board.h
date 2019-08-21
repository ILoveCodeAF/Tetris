#ifndef __BOARD_H_INCLUDED__
#define __BOARD_H_INCLUDED__

#include "vec3.h"

class Board{
	private:
		Vec3 board[20][10];
	public:
		Board();
		Vec3** getBoard();

};

#endif
