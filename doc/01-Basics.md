# Basics

The module `basics` includes basic types, classes and functions which are common in this project. `basics/basics.h` is the the header will be included in every source file. 


## <defines>



In `basics/defines.h`, some types are defined as short form of native 

### using vector_d = std::vector<double>;
Through the project, `vector_d` is taken as a one-dimensional vector in math, element of which is double. It is 


### using vector_sz = std::vector<size_t>;
Type for storing indices of vector.


### using complex_d = std::complex<double>;
Type for complex number.


### using vector_c = std::vector<std::complex<double>>;
Type for vector of complex number


### using vector2_d = std::vector<std::vector<double>>;
Type as dynamic array of double vector, sometimes taken as **matrix**. In some cases, a varible of `vector2_d/vector2_c` is considered as matrix. For example, in `vector2_d reshape(const vector2_d &A)`, A has to be a _matrix-like_ 2-D vector. But in some cases,  the length of vectors in `vector2_d/vector2_c` can be different. For example, in `vector2_d plus(const vector2_d& A, double s)`, each vector of A can have different length.

### using vector2_c = std::vector<std::vector<std::complex<double>>>;
Type as dynamic array of complex vector, sometimes taken as **matrix**.

## <ZException>

### enum class ZErrorCode
`ZErrorCode` defines error code that will be use in the project. 

|  Error Code  |   Number  |  Remark  |
|   ---        |    ---    |   ---    |
|   None       |    0      |   None error  |
|  LANG_INVALID_INDEX  |  101   |  Invalid index   | 
|  LANG_INVALID_RANGE  |  102   |  Invalid index range   | 
|  MATH_EMPTY_VEC      |  201   |  Vector or matrix is empty   | 
|  MATH_INVALID_MATRIX |  202   |  Invalid matrix   | 
|  MATH_ZERO_DIVISOR   |  203   |  Divisor is 0   | 
|  MATH_DIM_UNMATCH    |  204   |  Dimensions of matrices(vectors) not match   | 
|  MATH_INVALID_LEN    |  205   |  Invalid length of vector   | 
|  FILE_NOT_EXIST      |  301   |  File or directory not exists   | 
|  FILE_FAIL_TO_OPEN   |  302   |  Fail to open file   |   


### class ZException
 In many functions in `ZSL`, some properties of input argument will be checked before excution. If the requirement on the arguments is not satisfied, a `ZException` will be throwed. By using `std::source_location` as constructor arguments, a `ZException` obj will contain the calling stack. 
 
 For eaxmple, in `vector_d operator/(const vector_d &v, const vector_d &w)`, first `ZSL` will if `w` contains zero, if so, the function will throw a `ZException` with `ZErrorCode` of `MATH_ZERO_DIVISOR`. Then, it check if the length of two vectors are same, if not, it throws a `ZExceptioin` with error code `MATH_DIM_UNMATCH`. 

 ##### ZException(std::source_location loc = std::source_location::current());
 Default contructor with source location as input.

 #### ZException(ZErrorCode errorCode, std::string message, std::source_location loc = std::source_location::current());
 Constructor with error code and error message.

 #### int error_code() const noexcept  
 Error code of the exception.

 #### const std::string &stacktrace() 
 Stack trace of the exception.

 ####  const char *what() const noexcept override;
 Full message in the exception.


## <check>

In `check.h`, a number of `check_xxx` functions are defined to examine if the argument meet the requirement.

### template<typename T> void expect_valid_index(const std::vector<T> &v, size_t i, std::source_location loc = std::source_location::current())
Check if the index `i` is valid for `vector` v.

### template<typename T> void expect_valid_index(const std::vector<std::vector<T>> &A, size_t i, size_t j, std::source_location loc = std::source_location::current())
Check if the index `{i, j}` is valid for `vector<vector>` A.

### template<typename T> void expect_valid_range(const std::vector<T> &v, size_t first, size_t last, std::source_location loc = std::source_location::current())
Check if the range `[first : last]` is valid for `vector` v.

### template<typename T> void expect_valid_range(const std::vector<T> &v, size_t first, int interval, size_t last, std::source_location loc = std::source_location::current())
Check if the range `[first : interval : last]` for `vector` v.

### template<typename T> void expect_valid_range(const std::vector<std::vector<T>> &A, size_t i, size_t j, size_t m, size_t n, std::source_location loc = std::source_location::current())
Check if the range `[i : j, m : n]` is valid for `vector<vector>` A.

### template<typename T> void expect_valid_range(const std::vector<std::vector<T>> &A, size_t i, int a, size_t j, size_t m, int b, size_t n, std::source_location loc = std::source_location::current())
Check if the range `[i : a : j, m : b : n]` is valid for `vector<vector>` A.

### template<typename T> void expect_not_empty(const std::vector<T> &v, std::source_location loc = std::source_location::current()) 
Check if the `vector` v is empty.

### template<typename T> void expect_not_empty(const std::vector<std::vector<T>> &A, std::source_location loc = std::source_location::current())
Check if the `vector<vector>` A  **has** emtpy vetor.

### template<typename T> void expect_valid_matrix(const std::vector<std::vector<T>> &A, std::source_location loc = std::source_location::current())
Check if the `vector<vector>` A has valid form of a matrix, which means every `vector` shoud have same length.

### template<typename T> void expect_no_zero(const std::vector<T> &v, std::source_location loc = std::source_location::current())
Check if `vector` v has zero.

### template<typename T> void expect_no_zero(const std::vector<std::vector<T>> &A, std::source_location loc = std::source_location::current())
Check if `vector<vector>` has zero.

### template<typename T, typename U> void expect_dim_match(const std::vector<T> &v, const std::vector<U> &w, std::source_location loc = std::source_location::current())
Check if dimensions of `vector` v and `vector` w match, which means that `v.size() == w.size()`.

### template<typename T, typename U> void expect_dim_match(const  std::vector<std::vector<T>> &A, const std::vector<U> &v, std::source_location loc = std::source_location::current())
Check if dimensions of `vector<vector>` A and `vector` v match, which means that `A.size() == v.size()`

### template<typename T, typename U> void expect_dim_match(const std::vector<std::vector<T>> &A, const std::vector<std::vector<U>> &B, std::source_location loc = std::source_location::current())
Check if dimensions of `vector<vector>` A and `vector<vector>` B match, which means that `A.size() == B.size() && A[0].size() == B[0].size()`

### template<typename T> void expect_len_gt(const std::vector<T> &v, size_t len, std::source_location loc = std::source_location::current())
Check if  length `vector` v is less that len.

### void expect_file_exist(const std::string &filepath, std::source_location loc = std::source_location::current())
Check if file at `filepath` exists.