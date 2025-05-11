#pragma once

#include <memory>
#include <vector>

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	class EarClipResult_Impl;
	class EarClipTriangulator_Triangle;

	/// \brief Ear clipping triangulation result structure.
	class EarClipResult
	{
	public:
		/// \brief Constructs an ear clipping result structure.
		EarClipResult(int num_triangles);

		virtual ~EarClipResult();

		/// \brief Returns the triangles for this result.
		std::vector<EarClipTriangulator_Triangle> &get_triangles();

		/// \brief return a reference to a triangle in the triangulation.
		/** Memory  is preallocated for all triangles at creation. Use the returned reference to modify the triangles.*/
		EarClipTriangulator_Triangle &get_triangle(int index);

	private:
		std::shared_ptr<EarClipResult_Impl> impl;
	};

	/// \}
}
