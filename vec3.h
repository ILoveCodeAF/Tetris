#ifndef __VEC3_H_INCLUDED__
#define __VEC3_H_INCLUDED__

class Vec3{
	private:
		int x, y, z;
	public:
		Vec3();
		Vec3(int , int, int);
		~Vec3();
		Vec3 get();
		void set(int, int, int);
		int getx();
		int gety();
		int getz();
};

#endif
