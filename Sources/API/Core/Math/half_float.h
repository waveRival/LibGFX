#pragma once

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	class HalfFloat
	{
	public:
		HalfFloat() : value(0)
		{
		}

		HalfFloat(const HalfFloat &other) = default;

		HalfFloat(float v) : value(float_to_half(v))
		{
		}

		HalfFloat &operator =(const HalfFloat &other) = default;

		HalfFloat &operator =(const float v)
		{
			return from_float(v);
		}

		operator float() const
		{
			return to_float();
		}

		float to_float() const
		{
			return half_to_float(value);
		}

		HalfFloat &from_float(float v)
		{
			value = float_to_half(v);
			return *this;
		}

		/// Only works for 'normal' half-float values
		static float half_to_float_simple(unsigned short hf)
		{
			unsigned int float_value = ((hf & 0x8000) << 16) | (((hf & 0x7c00) + 0x1C000) << 13) | ((hf & 0x03FF) << 13);
			void *ptr = static_cast<void*>(&float_value);
			return *static_cast<float*>(ptr);
		}

		/// Only works for 'normal' half-float values
		static unsigned short float_to_half_simple(float float_value)
		{
			void *ptr = static_cast<void*>(&float_value);
			unsigned int f = *static_cast<unsigned int*>(ptr);
			return ((f >> 16) & 0x8000) | ((((f & 0x7f800000) - 0x38000000) >> 13) & 0x7c00) | ((f >> 13) & 0x03ff);
		}

		static float half_to_float(unsigned short hf)
		{
			unsigned int float_value = mantissa_table[offset_table[hf >> 10] + (hf & 0x3ff)] + exponent_table[hf >> 10];
			void *ptr = static_cast<void*>(&float_value);
			return *static_cast<float*>(ptr);
		}

		static unsigned short float_to_half(float float_value)
		{
			void *ptr = static_cast<void*>(&float_value);
			unsigned int f = *static_cast<unsigned int*>(ptr);
			return base_table[(f >> 23) & 0x1ff] + ((f & 0x007fffff) >> shift_table[(f >> 23) & 0x1ff]);
		}

	private:
		unsigned short value;

		static unsigned int mantissa_table[2048];
		static unsigned int exponent_table[64];
		static unsigned short offset_table[64];

		static unsigned short base_table[512];
		static unsigned char shift_table[512];
	};

	/// \}
}
