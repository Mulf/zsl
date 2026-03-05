#pragma once

#include "basics/basics.h"

namespace zsl {
	
template<Form F, class Func>
auto unary_func(const F &v, Func op) {
    using U = element_type_t<F>;
    using T = std::invoke_result_t<Func, U>;
    if constexpr (Vector<F>) {
        const std::size_t N = v.size();
        std::vector<T> r(N);
        for (size_t i = 0; i < N; i++) {
            r[i] = op(v[i]);
        }
        return r;
    }
    else if constexpr (Matrix<F>) {
        const auto [N, M] = dim(v);
        std::vector<std::vector<T>> r(N, std::vector<T>(M));
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < M; j++) {
                r[i][j] = op(at(v, i, j));
            }
        }
        return r;
    }
}

template<Form F, class Func>
void unary_func_self(F &v, Func op) {
    using U = element_type_t<F>;
    using T = std::invoke_result_t<Func, U>;
    static_assert(
        std::is_same_v<std::common_type_t<U, T>, U>, "Type is not convertible");
    if constexpr (Vector<F>) {
        const std::size_t N = v.size();
        for (size_t i = 0; i < N; i++) {
            v[i] = op(v[i]);
        }
    }
    else if constexpr (Matrix<F>) {
        const auto [N, M] = dim(v);
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < M; j++) {
                at(v, i, j) = op(at(v, i, j));
            }
        }
    }
}

template<Form R, Form F, class Func>
void unary_func_to(R &r, const F &v, Func op) {
    using U = element_type_t<F>;
    using T = std::invoke_result_t<Func, U>;
    using Ry = element_type_t<R>;
    static_assert(
        std::is_same_v<std::common_type_t<T, Ry>, Ry>,
        "Type is not convertible");
    if constexpr (Vector<F>) {
        const std::size_t N = v.size();
        for (size_t i = 0; i < N; i++) {
            r[i] = op(v[i]);
        }
    }
    else if constexpr (Matrix<F>) {
        const auto [N, M] = dim(v);
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < M; j++) {
                at(r, i, j) = op(at(v, i, j));
            }
        }
    }
}

#define UNARY_STD_FUNC(func)                                       \
    template<Form F>                                               \
    auto func(const F &v) {                                        \
        return unary_func(v, [](auto x) { return std::func(x); }); \
    }

#define UNARY_STD_FUNC_SELF(func)                                \
    template<Form F>                                             \
    auto func##_##self(F &v) {                                   \
        unary_func_self(v, [](auto x) { return std::func(x); }); \
    }

#define UNARY_STD_FUNC_TO(func)                                   \
    template<Form R, Form F>                                      \
    void func##_##to(R &r, const F &v) {                          \
        unary_func_to(r, v, [](auto x) { return std::func(x); }); \
    }

#define STD_FUNC_PACK(func)   \
    UNARY_STD_FUNC(func)      \
    UNARY_STD_FUNC_SELF(func) \
    UNARY_STD_FUNC_TO(func)


#define UNARY_STD_FUNC_RENAME(func, func_std)                                       \
    template<Form F>                                               \
    auto func(const F &v) {                                        \
        return unary_func(v, [](auto x) { return std::func_std(x); }); \
    }

#define UNARY_STD_FUNC_SELF_RENAME(func, func_std)                                \
    template<Form F>                                             \
    auto func##_##self(F &v) {                                   \
        unary_func_self(v, [](auto x) { return std::func_std(x); }); \
    }

#define UNARY_STD_FUNC_TO_RENAME(func, func_std)                                   \
    template<Form R, Form F>                                      \
    void func##_##to(R &r, const F &v) {                          \
        unary_func_to(r, v, [](auto x) { return std::func_std(x); }); \
    }

#define STD_FUNC_PACK_RENAME(func, func_std)   \
    UNARY_STD_FUNC_RENAME(func, func_std)      \
    UNARY_STD_FUNC_SELF_RENAME(func, func_std) \
    UNARY_STD_FUNC_TO_RENAME(func, func_std)


}