#ifndef __TETRIMINO_H_INCLUDED__
#define __TETRIMINO_H_INCLUDED__

#include "vec4.h"

class Tetrimino{
	private:
		char character;
		Vec4 **states;
		int width;
		int height;
		int num_state;
		int current_state;
		
		void free();
		void _copy(const Tetrimino &tetrimino);
		void print(int state) const;
	public:
		Tetrimino();
		Tetrimino(char ch, Vec4 **states, int w, int h, int num_state);
		Tetrimino(const Tetrimino &);
		Tetrimino& operator=(const Tetrimino &);
		Tetrimino& operator=(const Tetrimino &&);
		~Tetrimino();
		char get_character() const;
		int get_width() const;
		int get_height() const;
		Vec4 *get_tetrimino() const;
		int get_num_state() const;
		void change_state(int n);
		Vec4 **get_states() const;
		int get_current_state() const;
		void print() const;
		static Tetrimino *load_tetrimino(const char *filename);
};

#endif
