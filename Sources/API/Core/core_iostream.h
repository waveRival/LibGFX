#pragma once

#include <iosfwd>
#include <iostream>

namespace cl
{
	class Rect;
	class Rectf;
	class Rectd;
	class Point;
	class Pointf;
	class Pointd;
	class Size;
	class Sizef;
	class Sized;

	std::ostream& operator<<(std::ostream& s, const Rect& rect);
	std::ostream& operator<<(std::ostream& s, const Rectf& rect);
	std::ostream& operator<<(std::ostream& s, const Rectd& rect);
	std::ostream& operator<<(std::ostream& s, const Point& point);
	std::ostream& operator<<(std::ostream& s, const Pointf& point);
	std::ostream& operator<<(std::ostream& s, const Pointd& point);
	std::ostream& operator<<(std::ostream& s, const Size& size);
	std::ostream& operator<<(std::ostream& s, const Sizef& size);

	template<typename T>
	std::ostream& operator<<(std::ostream& s, const Vec2<T>& vec)
	{
		s << "["
			<< vec.x << ", "
			<< vec.y << "]";
		return s;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& s, const Vec3<T>& vec)
	{
		s << "["
			<< vec.x << ", "
			<< vec.y << ", "
			<< vec.z << "]";
		return s;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& s, const Vec4<T>& vec)
	{
		s << "["
			<< vec.x << ", "
			<< vec.y << ", "
			<< vec.z << ", "
			<< vec.w << "]";
		return s;
	}
}
