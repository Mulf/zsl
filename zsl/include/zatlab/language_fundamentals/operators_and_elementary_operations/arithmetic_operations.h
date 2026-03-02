#ifndef ZSL_ZATLAB_OPERATORS_AND_ARITHMETIC_OPERATOR_H
#define ZSL_ZATLAB_OPERATORS_AND_ARITHMETIC_OPERATOR_H

#include "basics/basics.h"

namespace zsl {

template<typename F, typename T = double, typename U = double>
concept ArithOp = requires(F f, T t, U u) {
    { f(t, u) } -> std::same_as<std::common_type_t<T, U>>;
};

template<typename F, typename T = double, typename U = double>
concept ArithOpSelf = requires(F f, T t, U u) {
    f(t, u);
    std::same_as<std::common_type_t<T, U>, T>;
};

template<Vector V>
std::ostream &operator<<(std::ostream &os, const V &v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template<Matrix V>
std::ostream &operator<<(std::ostream &os, const V &v) {
    os << "[";

    const auto [N, M] = dim(v);
    for (size_t i = 0; i < N; i++) {
        os << "[";
        for (size_t j = 0; j < M; j++) {
            os << at(v, i, j);
            if (j != M - 1) {
                os << ", ";
            }
        }
        os << "]";
        if (i != N - 1) {
            os << "; ";
        }
    }
    os << "]";
    return os;
}

template<Form S, Form F, ArithOp Op>
auto arith_op(const S &s, const F &f, Op op) {
    using T = std::common_type_t<element_type_t<S>, element_type_t<F>>;

    if constexpr (Scalar<S>) {
        if constexpr (Scalar<F>) {
            return op(s, f);
        }
        else if constexpr (Vector<F>) {
            const std::size_t N = f.size();
            std::vector<T> r(N);
            for (size_t i = 0; i < N; i++) {
                r[i] = op(s, f[i]);
            }
            return r;
        }
        else if constexpr (Matrix<F>) {
            const auto [N, M] = dim(f);
            std::vector<std::vector<T>> r(N, std::vector<T>(M));
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    r[i][j] = op(s, at(f, i, j));
                }
            }
            return r;
        }
    }
    else if constexpr (Vector<S>) {
        if constexpr (Scalar<F>) {
            const std::size_t N = s.size();
            std::vector<T> r(N);
            for (size_t i = 0; i < N; i++) {
                r[i] = op(s[i], f);
            }
            return r;
        }
        else if constexpr (Vector<F>) {
            const std::size_t N = s.size();
            std::vector<T> r(N);
            for (size_t i = 0; i < N; i++) {
                r[i] = op(s[i], f[i]);
            }
            return r;
        }
        else if constexpr (Matrix<F>) {
            const auto [N, M] = dim(f);
            std::vector<std::vector<T>> r(N, std::vector<T>(M));
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    r[i][j] = op(s[i], at(f, i, j));
                }
            }
            return r;
        }
    }
    else if constexpr (Matrix<S>) {
        if constexpr (Scalar<F>) {
            const auto [N, M] = dim(s);
            std::vector<std::vector<T>> r(N, std::vector<T>(M));
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    r[i][j] = op(at(s, i, j), f);
                }
            }
            return r;
        }
        else if constexpr (Vector<F>) {
            const auto [N, M] = dim(s);
            std::vector<std::vector<T>> r(N, std::vector<T>(M));
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    r[i][j] = op(at(s, i, j), f[i]);
                }
            }
            return r;
        }
        else if constexpr (Matrix<F>) {
            const auto [N, M] = dim(f);
            std::vector<std::vector<T>> r(N, std::vector<T>(M));
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    r[i][j] = op(at(s, i, j), at(f, i, j));
                }
            }
            return r;
        }
    }
}

template<Form S, Form F, ArithOpSelf Op>
void arith_op_self(S &s, const F &f, Op op) {
    using T = std::common_type_t<element_type_t<S>, element_type_t<F>>;

    if constexpr (Scalar<S>) {
        if constexpr (Scalar<F>) {
            op(s, f);
        }
    }
    else if constexpr (Vector<S>) {
        if constexpr (Scalar<F>) {
            const std::size_t N = s.size();
            for (size_t i = 0; i < N; i++) {
                op(s[i], f);
            }
        }
        else if constexpr (Vector<F>) {
            const std::size_t N = s.size();
            for (size_t i = 0; i < N; i++) {
                op(s[i], f[i]);
            }
        }
    }
    else if constexpr (Matrix<S>) {
        if constexpr (Scalar<F>) {
            const auto [N, M] = dim(s);
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    op(at(s, i, j), f);
                }
            }
        }
        else if constexpr (Vector<F>) {
            const auto [N, M] = dim(s);
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    op(at(s, i, j), f[i]);
                }
            }
        }
        else if constexpr (Matrix<F>) {
            const auto [N, M] = dim(f);
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    op(at(s, i, j), at(f, i, j));
                }
            }
        }
    }
}

template<Form R, Form S, Form F, ArithOp Op>
void arith_op_to(R &r, const S &s, const F &f, Op op) {
    using T = std::common_type_t<element_type_t<S>, element_type_t<F>>;

    if constexpr (Scalar<S>) {
        if constexpr (Scalar<F>) {
            r = op(s, f);
        }
        else if constexpr (Vector<F>) {
            const std::size_t N = f.size();
            for (size_t i = 0; i < N; i++) {
                r[i] = op(s, f[i]);
            }
        }
        else if constexpr (Matrix<F>) {
            const auto [N, M] = dim(f);
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    at(r, i, j) = op(s, at(f, i, j));
                }
            }
        }
    }
    else if constexpr (Vector<S>) {
        if constexpr (Scalar<F>) {
            const std::size_t N = s.size();
            for (size_t i = 0; i < N; i++) {
                r[i] = op(s[i], f);
            }
        }
        else if constexpr (Vector<F>) {
            const std::size_t N = s.size();
            for (size_t i = 0; i < N; i++) {
                r[i] = op(s[i], f[i]);
            }
        }
        else if constexpr (Matrix<F>) {
            const auto [N, M] = dim(f);
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    at(r, i, j) = op(s[i], at(f, i, j));
                }
            }
        }
    }
    else if constexpr (Matrix<S>) {
        if constexpr (Scalar<F>) {
            const auto [N, M] = dim(s);
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    at(r, i, j) = op(at(s, i, j), f);
                }
            }
        }
        else if constexpr (Vector<F>) {
            const auto [N, M] = dim(s);
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    at(r, i, j) = op(at(s, i, j), f[i]);
                }
            }
        }
        else if constexpr (Matrix<F>) {
            const auto [N, M] = dim(f);
            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < M; j++) {
                    at(r, i, j) = op(at(s, i, j), at(f, i, j));
                }
            }
        }
    }
}

template<Form F, Form G>
auto plus(const F &f, const G &g) {
    return arith_op(f, g, [](auto a, auto b) { return a + b; });
}

template<Form F, Form G>
void plus_self(F &f, const G &g) {
    arith_op_self(f, g, [](auto &a, auto b) { a += b; });
}

template<Form R, Form F, Form G>
auto plus_to(R &r, const F &f, const G &g) {
    arith_op_to(r, f, g, [](auto a, auto b) { return a + b; });
}

template<Form F, Form G>
auto minus(const F &f, const G &g) {
    return arith_op(f, g, [](auto a, auto b) { return a - b; });
}

template<Form F, Form G>
void minus_self(F &f, const G &g) {
    return arith_op_self(f, g, [](auto &a, auto b) { a -= b; });
}

template<Form R, Form F, Form G>
auto minus_to(R &r, const F &f, const G &g) {
    return arith_op_to(r, f, g, [](auto a, auto b) { return a - b; });
}

template<Form F, Form G>
auto times(const F &f, const G &g) {
    return arith_op(f, g, [](auto a, auto b) { return a * b; });
}

template<Form F, Form G>
void times_self(F &f, const G &g) {
    return arith_op_self(f, g, [](auto &a, auto b) { a *= b; });
}

template<Form R, Form F, Form G>
auto times_to(R &r, const F &f, const G &g) {
    return arith_op_to(r, f, g, [](auto a, auto b) { return a * b; });
}

template<Form F, Form G>
auto rdivide(const F &f, const G &g) {
    return arith_op(f, g, [](auto a, auto b) { return a / b; });
}

template<Form R, Form F, Form G>
auto rdivide_to(R &r, const F &f, const G &g) {
    return arith_op_to(r, f, g, [](auto a, auto b) { return a / b; });
}

template<Form F, Form G>
void rdivide_self(F &f, const G &g) {
    return arith_op_self(f, g, [](auto &a, auto b) { a /= b; });
}

} // namespace zsl

using zsl::Form;
template<Form F, Form G>
auto operator+(const F &f, const G &g) {
    return zsl::plus(f, g);
}

template<Form F, Form G>
void operator+=(F &f, const G &g) {
    zsl::plus_self(f, g);
}

template<Form F, Form G>
auto operator-(const F &f, const G &g) {
    return zsl::minus(f, g);
}

template<Form F, Form G>
void operator-=(F &f, const G &g) {
    zsl::minus_self(f, g);
}

template<Form F, Form G>
auto operator*(const F &f, const G &g) {
    return zsl::times(f, g);
}

template<Form F, Form G>
void operator*=(F &f, const G &g) {
    zsl::times_self(f, g);
}

template<Form F, Form G>
auto operator/(const F &f, const G &g) {
    return zsl::rdivide(f, g);
}

template<Form F, Form G>
void operator/=(F &f, const G &g) {
    zsl::rdivide_self(f, g);
}

#endif // !ZSL_ZATLAB_OPERATORS_AND_ARITHMETIC_OPERATOR_H
