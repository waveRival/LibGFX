#pragma once

#include <memory>
#include "../Math/point.h"
#include <vector>

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	/// \brief EarClipTriangulator_Triangle
	class EarClipTriangulator_Triangle
	{
	public:
		float x1, y1, x2, y2, x3, y3;
	};

	class EarClipTriangulator_Impl;
	class EarClipResult;

	/// \brief Polygon orientations.
	enum PolygonOrientation
	{
		cl_clockwise,
		cl_counter_clockwise
	};

	/// \brief Ear-clipping triangulator.
	class EarClipTriangulator
	{
	public:
		/// \brief Constructs a triangulator.
		EarClipTriangulator();

		virtual ~EarClipTriangulator();

		/// \brief Returns a list of the vertices added to the triangulator.
		std::vector<Pointf> get_vertices();

		/// \brief Returns the number of vertices in the triangulator.
		int get_vertice_count();

		/// \brief Determine the orientation of the vertices in the triangulator.
		PolygonOrientation calculate_polygon_orientation();

		/// \brief Add the next vertex of the polygon to the triangulator.
		void add_vertex(float x, float y);

		/// \brief Add vertex
		///
		/// \param p = Pointf
		void add_vertex(const Pointf &p);

		/// \brief Remove all vertices from triangulator.
		void clear();

		/// \brief Set polygon orientation.
		void set_orientation(PolygonOrientation orientation);

		/// \brief Perform triangulation.
		EarClipResult triangulate();

		/// \brief Mark beginning of a polygon hole.
		void begin_hole();

		/// \brief Mark ending of a polygon hole.
		void end_hole();

	private:
		std::shared_ptr<EarClipTriangulator_Impl> impl;
	};

	/// \}
}
