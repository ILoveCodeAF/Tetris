#ifndef __VEC4_H_INCLUDED__
#define __VEC4_H_INCLUDED__

#include <iostream>

class Vec4{
	private:
		float r, g, b, a;
	public:
		Vec4(const Vec4 &&);
		Vec4& operator=(const Vec4 &vec4);
		Vec4(const Vec4 &);
		Vec4& operator=(const Vec4 &&vec4);
		Vec4();
		Vec4(float , float, float);
		Vec4(float , float, float, float);
		~Vec4();
		void set(float, float, float, float);
		void set(const Vec4 &vec4);
		Vec4 get() const;
		float getr() const;
		float getg() const;
		float getb() const;
		float geta() const;
};

std::ostream &operator<<(std::ostream &out, const Vec4 &vec);

#endif
