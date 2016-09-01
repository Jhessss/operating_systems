#include "geometry.h"

double *size_of_sides(CartesianTriangle triangle)
{
	const int AB = 0;
	const int BC = 1;
	const int CA = 2;

	static double sides_size[3];

	sides_size[AB] = hypot((triangle.b.x - triangle.a.x),
			(triangle.b.y - triangle.a.y));
	sides_size[BC] = hypot((triangle.c.x - triangle.b.x),
			(triangle.c.y - triangle.b.y));
	sides_size[CA] = hypot((triangle.a.x - triangle.c.x),
			(triangle.a.y - triangle.c.y));

	return sides_size;
}

Boolean exists(CartesianTriangle triangle)
{
	const int AB = 0;
	const int BC = 1;
	const int CA = 2;

	double *sides_size = size_of_sides(triangle);

	Boolean passed_triangle_inequality = false;
	if(sides_size[AB] > 0 && sides_size[BC] > 0 && sides_size[CA] > 0
			&& sides_size[AB] + sides_size[BC] > sides_size[CA]
			&& sides_size[CA] > abs(sides_size[AB] - sides_size[BC])
			&& sides_size[BC] + sides_size[CA] > sides_size[AB]
			&& sides_size[AB] > abs(sides_size[BC] - sides_size[CA])
			&& sides_size[CA] + sides_size[AB] > sides_size[BC]
			&& sides_size[BC] > abs(sides_size[CA] - sides_size[AB]))
	{
		passed_triangle_inequality = true;
	}

	return passed_triangle_inequality;
}

double perimeter(CartesianTriangle triangle)
{
	double perimeter = 0.0;
	if(exists(triangle))
	{
		const int AB = 0;
		const int BC = 1;
		const int CA = 2;
		double *sides_size = size_of_sides(triangle);
		perimeter = sides_size[AB] + sides_size[BC] + sides_size[CA];
	}

	return perimeter;
}

double area(CartesianTriangle triangle)
{
	double area = 0.0;
	if(exists(triangle))
	{
		const int AB = 0;
		const int BC = 1;
		const int CA = 2;
		double *sides_size = size_of_sides(triangle);
		double s = perimeter(triangle)/2.0;
		area = sqrt(s*(s-sides_size[AB])*(s-sides_size[BC])*(s-sides_size[CA]));
	}

	return area;
}
