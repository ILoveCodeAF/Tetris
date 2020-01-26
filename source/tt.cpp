#include "tetrimino.h"
#include "vec4.h"
#include "board.h"
#include <iostream>

int main(){
	//
	//Tetrimino* shps = Tetrimino::load_tetrimino("data/tetriminos.txt");
	Vec4 **state = new Vec4*[1];
	state[0] = new Vec4[12];
	Tetrimino sh('t', state, 3, 4, 1);
	sh.print();

	Tetrimino* shps = Tetrimino::load_tetrimino("data/tetriminos.txt");

	for(int i = 0; i < 7; ++i){
		std::cout<<"----------------\n";
		shps[i].print();
	}
	Board board;
	Tetrimino t = shps[0];
	std::cout<<"------ ^ ^-----------\n";
	t.print();
	board.add(shps[0], 2, 5);
	board.print();
	t = shps[1];
	t.print();
	std::cout<<"-------delete--------\n";
	delete[] shps;
	std::cout<<"-------return-------\n";
	return 0;std::cout<<"-------return-------\n";

}
