#pragma once

namespace cl
{
	class Easing
	{
	public:
		static float linear(float t);
		static float easeout(float t);
		static float easein(float t);
		static float easeinout(float t);
		static float backin(float t);
		static float backout(float t);
		static float elastic(float t);
		static float bounce(float t);
	};
}
