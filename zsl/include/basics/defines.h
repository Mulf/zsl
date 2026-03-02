#ifndef ZSL_BASICS_DEFINES_H
#define ZSL_BASICS_DEFINES_H

#include <complex>
#include <concepts>
#include <format>
#include <functional>
#include <iostream>
#include <limits>
#include <mdspan>
#include <numbers>
#include <ranges>
#include <span>
#include <type_traits>
#include <vector>

namespace zsl {
constexpr double pi = std::numbers::pi_v<double>;
// constexpr double eps = std::numeric_limits<double>::epsilon();

using complex_d = std::complex<double>;
using vector_d = std::vector<double>;
using vector_sz = std::vector<size_t>;
using vector_c = std::vector<std::complex<double>>;
using vector2_d = std::vector<std::vector<double>>;
using vector2_c = std::vector<std::vector<std::complex<double>>>;

using span_d = std::span<double>;
using span_c = std::span<std::complex<double>>;
using span2_d = std::mdspan<double, std::dextents<size_t, 2>>;
using span2_c = std::mdspan<std::complex<double>, std::dextents<size_t, 2>>;

template<typename S>
concept Scalar = std::same_as<S, double> || std::same_as<S, complex_d>;

template<typename V>
concept Vector = std::same_as<V, vector_d> || std::same_as<V, vector_c>
                 || std::same_as<V, span_d> || std::same_as<V, span_c>;

template<typename M>
concept Matrix = std::same_as<M, vector2_d> || std::same_as<M, vector2_c>
                 || std::same_as<M, span2_d> || std::same_as<M, span2_c>;

template<typename T>
concept Form = Scalar<T> || Vector<T> || Matrix<T>;

template<class T, template<class...> class Primary>
struct is_specialization_of: std::false_type {};

template<template<class...> class Primary, class... Args>
struct is_specialization_of<Primary<Args...>, Primary>: std::true_type {};

template<class T, template<class...> class Primary>
inline constexpr bool is_specialization_of_v
    = is_specialization_of<T, Primary>::value;

template<class V>
inline constexpr bool is_vetcor_v = is_specialization_of_v<V, std::vector>;

template<Vector V>
inline constexpr bool is_span_v
    = std::is_same_v<V, span_d> || std::is_same_v<V, span_c>;

template<Matrix M>
inline constexpr bool is_span2_v
    = std::is_same_v<M, span2_d> || std::is_same_v<M, span2_c>;

template<typename T>
struct get_element {
    using type = T;
};

template<typename T>
struct get_element<std::vector<T>> {
    using type = T;
};

template<typename T>
struct get_element<std::vector<std::vector<T>>> {
    using type = T;
};

template<typename T, std::size_t N>
struct get_element<std::span<T, N>> {
    using type = T;
};

template<typename T, typename E, typename L, typename A>
struct get_element<std::mdspan<T, E, L, A>> {
    using type = T;
};

template<typename T>
using element_type_t = typename get_element<T>::type;

template<Vector V>
size_t len(const V &v) {
    return v.size();
}

template<Vector V>
auto at(const V &v, std::size_t i) {
    return v[i];
}

template<Vector V>
auto &at(V &v, std::size_t i) {
    return v[i];
}

template<Matrix M>
std::pair<size_t, size_t> dim(const M &m) {
    if constexpr (is_vetcor_v<M>) {
        return {m.size(), m[0].size()};
    }
    else if constexpr (is_span2_v<M>) {
        return {m.extent(0), m.extent(1)};
    }
}

template<Matrix M>
auto at(const M &m, std::size_t row, std::size_t col) {
    if constexpr (is_vetcor_v<M>) {
        return m[row][col];
    }
    else if constexpr (is_span2_v<M>) {
        return m[row, col];
    }
}

template<Matrix M>
auto &at(M &m, std::size_t row, std::size_t col) {
    if constexpr (is_vetcor_v<M>) {
        return m[row][col];
    }
    else if constexpr (is_span2_v<M>) {
        return m[row, col];
    }
}

template<class Matrix>
bool is_matrix(const Matrix &A) {
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i].size() != A[0].size()) {
            return false;
        }
    }
    return true;
}

using UnaryOp = std::function<double(double)>;

constexpr double ABS_EPS = 1e-4;
} // namespace zsl

#endif // !ZSL_BASICS_DEFINES_H
