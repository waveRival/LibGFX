#pragma once

#include "mat4.h"
#include "vec4.h"

namespace cl
{
	class FrustumPlanes
	{
	public:
		FrustumPlanes();
		explicit FrustumPlanes(const Mat4f &world_to_projection);

		Vec4f planes[6];

	private:
		static Vec4f left_frustum_plane(const Mat4f &matrix);
		static Vec4f right_frustum_plane(const Mat4f &matrix);
		static Vec4f top_frustum_plane(const Mat4f &matrix);
		static Vec4f bottom_frustum_plane(const Mat4f &matrix);
		static Vec4f near_frustum_plane(const Mat4f &matrix);
		static Vec4f far_frustum_plane(const Mat4f &matrix);
	};
}
