# Introduction


ZSL (ZA Scientific Library) is a `C++` project which dedicating to provide interface similar to `Matlab` with native data structure.

Usually, a `C++` algorithm engineer tests his/her idea in `Matlab`, then transplant the algorithm  to `C++` project. Yet when writing `C++` code, he/she commonly find that things pretty easy in `Matlab` would be difficult in `C++`. For example, to smooth a group of data with moving average method, one simply call _movemean_ in `Matlab`, but to achieve this, he/she will have to write a long loop and carefully deal with data at end and the corner case that the data is shorter than the window. It is a heavy burden for a algorithm engineer. 

Indeed, there are some `C/C++` libraries that provides a lot assistant scientific functions, like `GSL`， `Eigen`, `Armadillo`. But they all define 
their own data structure to store data, while the data in our `C++` project are typically stored in `std::vector` or managed by raw pointer. Then to use the function given by those libraries, we will first move data from our project to those types defined in those libaries, and move back afterwards. This causes a lot of extra code to be written in the project. Also, the names and implementatio details for similar method from `Matlab` are probably different, so we should be careful when transfering from `Matlab` to those libraries.

The motivation to implement such a project comes from the pain mentioned above. Then I decide to write a libary with following principles:
1. Written in mordern C++. `GSL` is great, but it is written in `C`. So we have to carefully manage the memory, which is cumbersome. I want to skip it.
2. Using native type and data structure. `Eigen`, `Armadillo` and many other scientific libraries  provide many functions on vector/matrix operation, but they all define their own class of vetor and matrix. It takes time to learn them, and code to use it. I want to skip it.
3. Avoid template. Template is powerful, but also heavy to use. From my experience, we just, in most of cases, deal with data of type `double`. So I want to limit the functions to deal with several specified classes with `double` as template arguments.
4. Provide interface similar to `Matlab`. With similar interfaces, we can easily migrate algorithm of `Matlab` to `C++`. The simliarites include, function name, arguements, return and implementation details. But due to the fundamental difference between two languages, I can only persue _similarity_ in this project. 
5. Organize the source code like `Matlab`. The files in the project, including both headers and source files, are similar to the [Matlab documentation](https://www.mathworks.com/help/matlab). I hope such structure would help user easily map from one to another.
7. All-in-one header. All functions are included in one file， named `zsl.h`. We just need to include this header, then can access all functions given in the project.