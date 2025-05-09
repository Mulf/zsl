#include <iostream>
#include <zsl.h>

#include <matplot/matplot.h>


using namespace zsl;
using namespace matplot;

int main()
{
	
	vector_d x = zsl::linspace(0, 10, 100);
	auto y = sin(x);

	plot(x, y, "-o");

	show();

	return 0;
}