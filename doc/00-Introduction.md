# Introduction


ZSL (ZA Scientific Library) is a `C++` project which dedicating to provide interface similar to `Matlab` with native data structure.

## Demo
With `ZSL`, we can quickly convert the scripts of `Matlab` to code in `C++`, here is a demo of rewriting 
[fft example of Matlab](https://www.mathworks.com/help/matlab/ref/fft.html). 

```c++
#include <iostream>
#include <zsl.h>
#include <matplot/matplot.h>
using namespace zsl;

int main()
{
	double Fs = 1000;            // Sampling frequency                    
	double T = 1 / Fs;             // Sampling period       
	double L = 1500;             // Length of signal
	auto t = colon(0, L - 1) * T;        // Time vector
	auto S = 0.8 + 0.7 * sin(2 * pi * 50 * t) + sin(2 * pi * 120 * t);
	auto X = S + 2 * rand_v(S.size());
	{
        // Install gnuplot to plot the figure
		using namespace matplot;

		figure();
		plot(1000 * t, X);
		title("Signal Corrupted with Zero-Mean Random Noise");
		xlabel("t (milliseconds)");
		ylabel("|fft(X)|");

		figure();
		auto Y = fft(X);
		plot(Fs / L * colon(0, L - 1), abs(Y))->line_width(3);
		title("Complex Magnitude of fft Spectrum");
		xlabel("f (Hz)");
 		ylabel("|fft(X)|");
	}
	system("pause");
	return 0;
}

```

## Motivation

Usually, a `C++` algorithm engineer tests his/her idea in `Matlab`, then transplant the algorithm  to `C++` project. Yet when writing `C++` code, he/she commonly find that things pretty easy in `Matlab` would be difficult in `C++`. For example, to smooth a group of data with moving average method, one simply call _movemean_ in `Matlab`, but to achieve this, he/she will have to write a long loop and carefully deal with data at end and the corner case that the data is shorter than the window. It is a heavy burden for a algorithm engineer. 

Surely, there are some `C/C++` libraries that provides plenty assistant scientific functions, like `GSL`, `Eigen`, `Armadillo`. Why do we still not just use them? They are great libraries, but some issues discourage me to use these libraries frequently：
1. Self defined data structures. All libraries define their own data structures for vector and matrix. So it takes time and energy to study these data structures, and often we will forget it after some time. More importantly, the data is our projects are typically managed by native capacity like `std::vector`, we have to move data from native class to those self-defined structure and then move back. It takes plenty of extra codes to implement such job and cost considerable performance if copying is inevitable.
2. Name of interface. We are used to the functions in `Matlab`. But to use the functions from those libraries, we need to spend some time again to find the the corresponding functions and arguments.  This is not a happy job.
3. Different implentation details from matlab. It of happens that for similar functions, the result from `Matlab` and these libraries are different, which require us pretty careful to use them. 


## Philosophy

### Principles 

With these pain in developing algorithm with `C++`, finally I decide to write a libary. From the past experience and future demand, I establish following principles:
1. Written in mordern C++. `GSL` is great, but it is written in `C`. So we have to carefully manage the memory, which is cumbersome. I want to skip it.
2. Using native type and data structure. `Eigen`, `Armadillo` and many other scientific libraries  provide many functions on vector/matrix operation, but they all define their own class of vetor and matrix. It takes time to learn them, and code to use it. I want to skip it.
3. Avoid template, just double. Template is powerful, but also heavy to use. From my experience, we just, in most of cases, deal with data of type `double`. So I want to limit the functions to deal with several specified classes with `double` as template arguments. Albeit the internal implementation in source files might use template, the interfaces exposed in headers are provided without template. 
4. Provide interface similar to `Matlab`. With similar interfaces, we can easily migrate algorithm of `Matlab` to `C++`. The simliarites include, function name, arguements, return and implementation details. But due to the fundamental difference between two languages, I can only persue **similarity** in the project. 
5. Organize the source code like `Matlab`. The files in the project, including both headers and source files, are similar to the [Matlab documentation](https://www.mathworks.com/help/matlab). I hope such structure would help user easily map from one to another.
6. Throw exception for error. Some libraries, like `GSL`, indicate error use error code as return. This requires plenty of code to pass the error upwards. So I want to design a exception system to handle errors in functions. Users just need to catch such exceptions in the top level.
7. All-in-one header. All functions are included in one file, named `zsl.h`. We just need to include this header, then can access all functions given in the project.

### Style

**Different versions of function**. In `Matlab`, variables are immutable, which means we also get a new object by calling a function. While for a `C++` programmer, it is natural to avoid memory allocation in some, perhaps most, cases. So in `ZSL`, a lot of interfaces are presented with three versions:
* Orginal version. The function name `func` is just same as that from `Matlab`. This function is defined like `T func(const T &v)`, then return a new created object. Thanks to `NRVO`, we do not need worry about performance loss when passing these objects.
* Self version. The function name is like `func_self`. This function wis defined like `void func_self(const T&)`. This function, not certainly but very likely, will directly operate on the input arguments, so that no memory allocation for output happens. 
* <span style="color:gray">To version(TODO)</span> . The function name is like `{func}_to`. The arugments of this functions are like `void func_to(T &out, const T &v)`. With this version, we just write the result in variable `out`. No internal memory allcation happens for output.

**Handle multiple ouputs**. A function in `Matlab` might have different numbers of return values, but it is impossible to do so in `C++`. Maybe there is some template magic to implement this feature, but it is too heavy. Therefore, I handle this case is to define a set of functions to indicate the output. Take [`max`](https://www.mathworks.com/help/matlab/ref/double.max.html) as an exmple, possible outputs in `Matlab` include
```
M = max(A)   % return max value M in A
[M,I] = max(A)  % return max value M and index I in A
```
The corresponding version in `ZSL` is
```
double max(const T& A);
size_t max_index(const T& A);
```

Also function like [`bounds`](https://www.mathworks.com/help/matlab/ref/bounds.html) have multiple outputs natively. In `Matlab`, it is
```
[minA,maxA] = bounds(A)
```
To present result meaningfully, I define a struct `MinMaxVal` to encapsulate the result in `ZSL`. With structured bind in `C++`, it is aslo concise to use it
```
// declaration
struct MinMaxVal
{
	double minVal;
	double maxVal;
};
MinMaxVal bounds(const vector_d &v);
// use
auto [minA, maxA] = bounds(A);

```

**Adapt to different dimensions**. In matlab, scalar, vector and matrix are same type indeed. A function can return one of them with different arguments. For example, result of `ones` just depend on input dimensions
```
v = ones(1, 4)   % retun a vector of length 4
A = ones(4)   % return a matrix of 4*4
A = ones(4, 4)  % return a matrix
```
In `ZSL`, function definitions are **vector-first**. To return a matrix, we have to specify two dimension values.
```
v = ones(4)     // return of std::vector<double> of length 4
A = ones(4, 4)  // return std::vector<std::vector<double>> of 4*4
``` 

**Name change**. In some cases, we have to change name of function. For example `std` is standard deviation in `Matlab`, yet it is key word in `C++`. So it is changed to `stdev`.

## Implementation
For some basic functions, they are implemented by my own code, such as the `plus/minus/times/rdivide` of two vectors . Some functions are implemented with `STL`, such as `sin/cos/tan`. 

For those more complicated functions, I take use of `GSL` internally. For example, functions in descriptive statistics are implemented by calling functions in `GSL`. Actually, encapsulating `GSL` is the idea bud of this project. I used to encapsulate `fft`, `mean`, `sd` from `GSL` in my job. With time going on, I finally decided to write a bigger project than just encapsulating `GSL`. 


## Status
`Matlab` is a monolithic software. There are a lot of [modules](https://www.mathworks.com/help/index.html) in `Matlab`. With limited time and capability, only a small part of functions are implemented in `ZSL`. Now, only part of functions from [`MATLAB module`](https://www.mathworks.com/help/matlab/index.html) are implemented in `ZSL`. The functions declarations locate in `zsl/include/zatlab`, and the implementations are in `zsl/src/zatlab`.  I hope more people to participate in this project to make `ZSL` more comprehensive and versatile.

