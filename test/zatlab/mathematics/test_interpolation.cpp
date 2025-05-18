#include <zatlab/mathematics/interpolation.h>
#include <zsl.h>
#include <gtest/gtest.h>
#include <matplot/matplot.h>

using namespace zsl;



TEST(interpolation, interp) {
	auto x = colon(0, pi / 4, 2 * pi);
	auto v = sin(x);
	auto xq = colon(0, pi / 16, 2 * pi);
	auto vq1 = interp1(x, v, xq);
	{
		//using namespace matplot;
		//plot(x, v, "o");
		//hold(on);
		//plot(xq, vq1, "-*");
		//show();
	}

}