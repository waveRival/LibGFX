#pragma once

#include <memory>
#include <vector>

namespace cl
{
	/// \addtogroup clanCore_Math clanCore Math
	/// \{

	class BezierCurve_Impl;
	class Pointf;
	class Angle;

	/// \brief Bezier curve generator.
	class BezierCurve
	{
	public:
		/// \brief Constructs a bezier curve generator.
		BezierCurve();

		virtual ~BezierCurve();

		/// \brief Returns the control points of the bezier.
		std::vector<Pointf> get_control_points() const;

		/// \brief Adds a control point to bezier.
		void add_control_point(float x, float y);

		void add_control_point(const Pointf &);

		/// \brief Generates points on the bezier curve.
		std::vector<Pointf> generate_curve_points(const Angle &split_angle);

		/// \brief Get a point on the bezier curve.
		Pointf get_point_relative(float pos_0_to_1) const;

	private:
		std::shared_ptr<BezierCurve_Impl> impl;
	};

	/// \}
}
