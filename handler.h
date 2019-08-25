#ifndef __HANDLER_H_INCLUDED__
#define __HANDLER_H_INCLUDED__

#include "shape.h"
#include "board.h"
#include "queue.h"

enum class Control{
	LEFT,
	RIGHT,
	ROTATE_CLOCKWISE, 
	ROTATE_ANTICLOCKWISE,
	HOLD,
	HARD_DROP,
	SOFT_DROP
};

struct pair{
	int first, second;
	pair();
	pair(int, int);
};

class Handler{
	private:
		Board board;
		Shape shape;
		Shape* shapes;
		int xpos, ypos;
		int ylandedpos;
		Shape holded_shape;
		int queue_size;
		Queue<Shape> queue(5);
		bool is_holded;
		int set_pre_landing();
		pair* wall_kick;
		pair* wall_kick_i;
		int num_shape;
		int wWall;
		int hWall;
		int set_preview_landing_place()
	public:
		Handler();
		~Handler();
		Shape get_shape();
		Board get_board();
		Shape* get_queue();
		int get_xpos();
		int get_ypos();
		int get_ylandedpos();
		bool rotate(Control);
		bool move(Control);
		bool has_collision();
		void hold();
		void spawn();
		void reset();
		void land();
};

#endif
