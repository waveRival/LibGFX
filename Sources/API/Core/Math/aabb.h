#pragma once

#include "vec3.h"
#include "cl_math.h"

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	class AxisAlignedBoundingBox
	{
	public:
		AxisAlignedBoundingBox() : aabb_min(), aabb_max() {}
		AxisAlignedBoundingBox(const Vec3f &aabb_min, const Vec3f &aabb_max) : aabb_min(aabb_min), aabb_max(aabb_max) { }
		AxisAlignedBoundingBox(const AxisAlignedBoundingBox &aabb, const Vec3f &barycentric_min, const Vec3f &barycentric_max)
			: aabb_min(mix(aabb.aabb_min, aabb.aabb_max, barycentric_min)), aabb_max(mix(aabb.aabb_min, aabb.aabb_max, barycentric_max)) { }

		Vec3f center() const { return (aabb_max + aabb_min) * 0.5f; }
		Vec3f extents() const { return (aabb_max - aabb_min) * 0.5f; }

		Vec3f aabb_min;
		Vec3f aabb_max;
	};

	/// \}
}
