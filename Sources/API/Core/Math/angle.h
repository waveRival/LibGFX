#pragma once

#include <memory>

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	class Angle_Impl;

	/// \brief Angle unit
	enum class AngleUnit
	{
		degrees,
		radians
	};

	/// \brief Euler angle rotation order
	enum class EulerOrder
	{
		XYZ,
		XZY,
		YZX,
		YXZ,
		ZXY,
		ZYX
	};

	/// \brief Angle class.
	class Angle
	{
	public:
		/// \brief Constructs a null Angle object.
		Angle();

		/// \brief Constructs an Angle object.
		Angle(float value, AngleUnit unit);

		/// \brief From radians
		///
		/// \param value = value
		///
		/// \return Angle
		static Angle from_radians(float value);

		/// \brief From degrees
		///
		/// \param value = value
		///
		/// \return Angle
		static Angle from_degrees(float value);

		/// \brief Returns the angle as degrees.
		float to_degrees() const;

		/// \brief Returns the angle as radians.
		float to_radians() const;

		/// \brief Set the angle value in degrees.
		void set_degrees(float value_degrees);

		/// \brief Set the angle value in radians.
		void set_radians(float value_radians);

		/// \brief Converts angle to range [0,360] degrees.
		///
		/// \return reference to this object
		Angle &normalize();

		/// \brief Converts angle to range [-180,180] degrees.
		///
		/// \return reference to this object
		Angle &normalize_180();

		/// \brief += operator.
		void operator += (const Angle &angle);

		/// \brief -= operator.
		void operator -= (const Angle &angle);

		/// \brief *= operator.
		void operator *= (const Angle &angle);

		/// \brief /= operator.
		void operator /= (const Angle &angle);

		/// \brief + operator.
		Angle operator + (const Angle &angle) const;

		/// \brief - operator.
		Angle operator - (const Angle &angle) const;

		/// \brief * operator.
		Angle operator * (const Angle &angle) const;

		/// \brief * operator.
		Angle operator * (float value) const;

		/// \brief / operator.
		Angle operator / (const Angle &angle) const;

		/// \brief / operator.
		Angle operator / (float value) const;

		/// \brief < operator.
		bool operator < (const Angle &angle) const;

		/// \brief < operator.
		bool operator <= (const Angle &angle) const;

		/// \brief > operator.
		bool operator > (const Angle &angle) const;

		/// \brief > operator.
		bool operator >= (const Angle &angle) const;

		/// \brief == operator.
		bool operator== (const Angle &angle) const;

		/// \brief != operator.
		bool operator!= (const Angle &angle) const;

	private:
		float value_rad;
	};

	/// \}
}
