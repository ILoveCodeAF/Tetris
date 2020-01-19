#ifndef __VEC3_H_INCLUDED__
#define __VEC3_H_INCLUDED__

class Vec3{
	private:
		int x, y, z;
	public:
//	Vec3& operator=(const Vec3 &vec3){
//		if(this == &vec3)
//			return *this;
//		Vec3 temp(vec3.x, vec3.y, vec3.z);
//		*this = temp;
//		return *this;
//	}
		Vec3(const Vec3 &&);
		Vec3& operator=(const Vec3 &vec3);
		Vec3(const Vec3 &);
		Vec3& operator=(const Vec3 &&vec3);
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
