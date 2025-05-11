#pragma once

#include "vec4.h"
#include "vec3.h"

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	class AxisAlignedBoundingBox;
	class OrientedBoundingBox;
	class FrustumPlanes;

	class IntersectionTest
	{
	public:
		enum Result
		{
			outside,
			inside,
			intersecting,
		};

		enum OverlapResult
		{
			disjoint,
			overlap
		};

		static Result plane_aabb(const Vec4f &plane, const AxisAlignedBoundingBox &aabb);
		static Result plane_obb(const Vec4f &plane, const OrientedBoundingBox &obb);
		static OverlapResult sphere(const Vec3f &center1, float radius1, const Vec3f &center2, float radius2);
		static OverlapResult sphere_aabb(const Vec3f &center, float radius, const AxisAlignedBoundingBox &aabb);
		static OverlapResult aabb(const AxisAlignedBoundingBox &a, const AxisAlignedBoundingBox &b);
		static Result frustum_aabb(const FrustumPlanes &frustum, const AxisAlignedBoundingBox &box);
		static Result frustum_obb(const FrustumPlanes &frustum, const OrientedBoundingBox &box);
		static OverlapResult ray_aabb(const Vec3f &ray_start, const Vec3f &ray_end, const AxisAlignedBoundingBox &box);
	};

	/// \}
}
