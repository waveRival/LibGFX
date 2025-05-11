#pragma once

#include <memory>
#include <vector>

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	/// \brief Vertex in the delauney triangulation.
	class DelauneyTriangulator_Vertex
	{
	public:
		/// \brief Data pointer given when adding the vertex.
		void *data;

		/// \brief X position of vertex.
		float x;

		/// \brief Y position of vertex.
		float y;
	};

	/// \brief Triangle generated from a delauney triangulation.
	class DelauneyTriangulator_Triangle
	{
	public:
		/// \brief First point in the triangle.
		DelauneyTriangulator_Vertex *vertex_A;

		/// \brief Second point in the triangle.
		DelauneyTriangulator_Vertex *vertex_B;

		/// \brief Third point in the triangle.
		DelauneyTriangulator_Vertex *vertex_C;
	};

	class DelauneyTriangulator_Impl;

	/// \brief Delauney triangulator.
	///
	///    <p>This class uses the <a href="http://astronomy.swin.edu.au/~pbourke/terrain/triangulate/">
	///    delauney triangulation algorithm</a> to produce
	///    triangles between a list of points.</p>
	class DelauneyTriangulator
	{
	public:
		/// \brief Creates a triangulator object.
		DelauneyTriangulator();

		virtual ~DelauneyTriangulator();

		/// \brief Returns the list of vertices in the triangulation.
		const std::vector<DelauneyTriangulator_Vertex> &get_vertices() const;

		/// \brief Returns the resulting triangles produced from triangulation.
		const std::vector<DelauneyTriangulator_Triangle> &get_triangles() const;

		/// \brief This function specifies a point to be used in the triangulation.
		void add_vertex(float x, float y, void *data);

		/// \brief Converts passed points into triangles.
		void generate();

	private:
		std::shared_ptr<DelauneyTriangulator_Impl> impl;
	};

	/// \}
}
