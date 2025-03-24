#include <iostream>
#include "zsl/std_vector_op.h"
#include "zsl/ZException.h"


void print(const std::vector<double>& v)
{
	for (auto x : v)
		std::cout << x << " ";
	std::cout << std::endl;
}


void test_func()
{
	std::vector<double> a{1, 2, 3};
	std::vector<double> b{2, 3, 4};
	double d = 5;

	print(zsl::vadd(a, b));
	print(zsl::vadd(a, d));
	print(zsl::vadd(d, a));

	print(zsl::vsub(a, b));
	print(zsl::vsub(a, d));
	print(zsl::vsub(d, a));

	print(zsl::vmul(a, b));
	print(zsl::vmul(a, d));
	print(zsl::vmul(d, a));

	print(zsl::vdiv(a, b));
	print(zsl::vdiv(a, d));
	print(zsl::vdiv(d, a));
}

void test_op()
{
	std::vector<double> a{1, 2, 3};
	std::vector<double> b{2, 3, 4};
	double d = 5;

	print(a + b);
	print(a + d);
	print(d + a);

	print(a - b);
	print(a - d);
	print(d - a);

	print(a * b);
	print(a * d);
	print(d * a);

	print(a / b);
	print(a / d);
	print(d / a);

	a += b;
	print(a);

	a += d;
	print(a);


	a *= d;
	print(a);

	a /= d;
	print(a);
	
}



void ProcessData(int value)
{
	if (value < 0)
	{
		Z_THROW(1001, "Input value cannot be negative");
	}

	if (value > 100)
	{
		Z_THROW(1002, "Input value exceeds maximum limit");
	}

	// 正常处理...
}

int main()
{
	try
	{
		ProcessData(-5);
	}
	catch (const ZException& e)
	{
		std::cerr << "Caught exception:\n";
		std::cerr << e.what() << "\n";

		//std::cerr << "Error code: " << e.GetErrorCode() << "\n";
		//std::cerr << "Location: " << e.GetLocation() << "\n";
		//std::cerr << "Stack trace:\n" << e.GetStackTrace() << "\n";

		// 清理符号系统
	//ZException::CleanupSymbols();
	}

	

	return 0;
}