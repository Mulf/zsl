#include <iostream>
#include "basics/std_vector_op.h"
#include "basics/ZException.h"

using namespace zsl;
void print(const std::vector<double>& v)
{
	for (auto x : v)
		std::cout << x << " ";
	std::cout << std::endl;
}

void test_throw_exception() {
	std::vector<double> a {0.0, 2.0, 3.0};
	std::vector<double> b {1.0, 2.0, 3.0};
	double d = 1;
	//auto c = a - b;

	//a = { 0 };
	auto c = b / a;
	print(c);
}



int main()
{
	try
	{
		test_throw_exception();
	}
	catch (const ZException & e)
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