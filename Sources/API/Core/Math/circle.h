#pragma once

#include "point.h"

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	/// \brief Circle
	///
	/// These circle templates are defined for: int (Circle), float (Circlef), double (Circled)
	template<typename Type>
	class Circlex
	{
	public:
		/// \brief Circle center point
		Vec2<Type> position;

		/// \brief Circle radius
		Type radius;

		Circlex(Type x, Type y, Type radius) : position(x, y), radius(radius) { }
		Circlex(const Vec2<Type> &p, Type radius) : position(p), radius(radius) { }
		Circlex() : position(), radius(static_cast<Type> (0))  { }
		Circlex(const Circlex<Type> &copy) = default;

		bool is_inside(const Vec2<Type> &point) { return radius >= position.distance(point); }

		Circlex<Type> &operator = (const Circlex<Type>& copy) = default;
		bool operator == (const Circlex<Type>& circle) const { return ((position == circle.position) && (radius == circle.radius)); }
		bool operator != (const Circlex<Type>& circle) const { return ((position != circle.position) || (radius != circle.radius)); }
	};

	/// \brief Circle - Integer
	class Circle : public Circlex<int>
	{
	public:
		Circle(int x, int y, int radius) : Circlex<int>(x, y, radius) { }
		Circle(const Vec2<int> &p, int radius) : Circlex<int>(p, radius) { }
		Circle() : Circlex<int>(){ }
		Circle(const Circlex<int> &copy) : Circlex<int>(copy){ }
	};

	/// \brief Circle - Float
	class Circlef : public Circlex<float>
	{
	public:
		Circlef(float x, float y, float radius) : Circlex<float>(x, y, radius) { }
		Circlef(const Vec2<float> &p, float radius) : Circlex<float>(p, radius) { }
		Circlef() : Circlex<float>(){ }
		Circlef(const Circlex<float> &copy) : Circlex<float>(copy){ }
	};

	/// \brief Circle - Double
	class Circled : public Circlex<double>
	{
	public:
		Circled(double x, double y, double radius) : Circlex<double>(x, y, radius) { }
		Circled(const Vec2<double> &p, double radius) : Circlex<double>(p, radius) { }
		Circled() : Circlex<double>(){ }
		Circled(const Circlex<double> &copy) : Circlex<double>(copy){ }
	};

	/// \}
}
