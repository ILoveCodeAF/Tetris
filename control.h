#ifndef __CONTROL_H_INCLUDED__
#define __CONTROL_H_INCLUDED__

#include "shape.h"
#include "board.h"
#include "queue.h"

enum class ControlKey{
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

class Control{
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
		Control();
		~Control();
		Shape get_shape();
		Board get_board();
		Shape* get_queue();
		int get_xpos();
		int get_ypos();
		int get_ylandedpos();
		bool rotate(ControlKey);
		bool move(ControlKey);
		bool has_collision();
		void hold();
		void spawn();
		void reset();
		void land();
};

#endif
