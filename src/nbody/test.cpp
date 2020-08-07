#include "Vector3D.h"

int main()
{
	Vector3D<float> x(1, 2, 3);
	float s(2);

	x.print();
	(x * s).print();

	std::cout << x.mag() << std::endl;

	return 0;
}
