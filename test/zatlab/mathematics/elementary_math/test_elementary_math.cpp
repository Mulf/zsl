#include "zatlab/mathematics/elementary_math/elementary_math.h"
#include "zsl.h"

#include <filesystem>
#include <gtest/gtest.h>
#include <matplot/matplot.h>

using namespace zsl;
using namespace std::complex_literals;
static constexpr double EPS = 1e-4;

template<Form V, Form W>
void expect_eq(const V &v, const W &w) {
    if constexpr (Vector<V> && Vector<W>) {
        for (size_t i = 0; i < v.size(); i++) {
            EXPECT_EQ(v[i], w[i]);
        }
    }
    else if constexpr (Matrix<V> && Matrix<W>) {
        auto [N, M] = dim(v);
        for (decltype(N) i = 0; i < N; i++) {
            for (decltype(M) j = 0; j < N; j++) {
                EXPECT_EQ(at(v, i, j), at(w, i, j));
            }
        }
    }
    else {
        EXPECT_TRUE(false) << "not equal";
    }
}

template<class V, class Op, class A>
void expect_eq_self(V &v, Op op, const A &ans) {
    op(v);
    expect_eq(v, ans);
}

template<class R, class V, class Op, class A>
void expect_eq_to(R &r, const V &v, Op op, const A &ans) {
    op(r, v);
    expect_eq(r, ans);
}


template<Form V, Form W>
void expect_near(const V &v, const W &w) {
    if constexpr (Scalar<V> && Scalar<W>) {
        //static_assert(std::is_same_v<V, W>);
        EXPECT_LE(abs(v - w), EPS);
        return;
	}
    if constexpr (Vector<V> && Vector<W>) {
        for (size_t i = 0; i < v.size(); i++) {
            expect_near(v[i], w[i]);
        }
        return;
    }
    else if constexpr (Matrix<V> && Matrix<W>) {
        auto [N, M] = dim(v);
        for (decltype(N) i = 0; i < N; i++) {
            for (decltype(M) j = 0; j < N; j++) {
                expect_near(at(v, i, j), at(w, i, j));
            }
        }
        return;
    }
    else {
        EXPECT_TRUE(false) << "not near";
    }
}

template<class V, class Op, class A>
bool expect_near_self(V &v, Op op, const A &ans) {
    op(v);
    expect_near(v, ans);
    return true;
}

template<class R, class V, class Op, class A>
bool expect_near_to(R &r, const V &v, Op op, const A &ans) {
    op(r, v);
    expect_near(r, ans);
    return true;
}


TEST(elementary_math, complex_numbers)
{
    // abs
    {
        vector_c v{3.0 + 4.0i, 6.0 + 8.0i, 9.0 + 12.0i};
        vector_d v_abs{5.0, 10.0, 15.0};
        vector_c v_abs_c{5.0, 10.0, 15.0};
        auto vs = v;
        auto vt = v_abs;
        vector_d va = abs(v);
        expect_eq(va, v_abs);
        expect_eq_self(vs, [](auto &x) { return abs_self(x); }, v_abs_c);
        expect_eq_to(vt, v, [](auto &x, const auto &y) { return abs_to(x, y); }, v_abs_c);

		vector_c w{3.0 + 4.0i, 6.0 + 8.0i, 9.0 + 12.0i, 12.0 + 16.0i};
        vector2_c m{{3.0 + 4.0i, 6.0 + 8.0i}, {9.0 + 12.0i, 12.0 + 16.0i}};
        span2_c ws{w.data(), 2, 2};
        vector_d w_abs{5.0, 10.0, 15.0, 20.0};
        vector2_d m_abs{{5.0, 10.0}, {15.0, 20.0}};
        vector2_c m_abs_c{{5.0, 10.0}, {15.0, 20.0}};
        span2_d w_abs_s{w_abs.data(), 2, 2};
        auto ms = m;
        auto mt = m_abs;
        expect_eq(abs(m), m_abs);
        expect_eq(abs(ws), m_abs);
        expect_eq_self(ms, [](auto &x) { return abs_self(x); }, m_abs_c);
        expect_eq_self(ws, [](auto &x) { return abs_self(x); }, m_abs_c);
        expect_eq_to(
            mt, m, [](auto &x, const auto &y) { return abs_to(x, y); },
            m_abs);
        expect_eq_to(
            ws, m, [](auto &x, const auto &y) { return abs_to(x, y); },
            m_abs_c);

	}

	// angle / arg
	{
        vector_c v{2.0 * exp(0.5i), 3.0 * exp(1.0i), 4.0 * exp(1.5i)};
        vector_d v_arg{0.5, 1.0, 1.5};
        auto vs = v;
        auto vt = v;
        auto va = arg(v);
        expect_near(va, v_arg);
        expect_near_self(vs, [](auto &x) { return arg_self(x); }, v_arg);
        expect_near_to(
            vt, v, [](auto &x, const auto &y) { return arg_to(x, y); }, v_arg);

        expect_near(angle(v), v_arg);
        vs = v;
        expect_near_self(vs, [](auto &x) { return angle_self(x); }, v_arg);
        expect_near_to(
            vt, v, [](auto &x, const auto &y) { return angle_to(x, y); },
            v_arg);
	}

	// conj
    {
        vector_c v{3.0 + 4.0i, 6.0 + 8.0i, 9.0 + 12.0i};
        vector_c v_conj{3.0 - 4.0i, 6.0 - 8.0i, 9.0 - 12.0i};
        auto vs = v;
        auto vt = v;
        expect_eq(conj(v), v_conj);
        expect_eq_self(vs, [](auto &x) { return conj_self(x); }, v_conj);
        expect_eq_to(
            vt, v, [](auto &x, const auto &y) { return conj_to(x, y); },
            v_conj);
    }

	// imag
    {
        vector_c v{3.0 + 4.0i, 6.0 + 8.0i, 9.0 + 12.0i};
        vector_d v_imag{4.0, 8.0, 12.0};
        auto vs = v;
        auto vt = v;
        expect_near(imag(v), v_imag);
        expect_near_self(vs, [](auto &x) { return imag_self(x); }, v_imag);
        expect_near_to(
            vt, v, [](auto &x, const auto &y) { return imag_to(x, y); },
            v_imag);
    }

	// real
    {
        vector_c v{3.0 + 4.0i, 6.0 + 8.0i, 9.0 + 12.0i};
        vector_d v_real{3.0, 6.0, 9.0};
        auto vs = v;
        auto vt = v;
        expect_near(real(v), v_real);
        expect_near_self(vs, [](auto &x) { return real_self(x); }, v_real);
        expect_near_to(
            vt, v, [](auto &x, const auto &y) { return real_to(x, y); },
            v_real);
    }

	{
        vector_d v{-2.0, 0.0, 2.0};
        vector_d v_sign{-1.0, 0.0, 1.0};
        auto va = sign(v);
        auto vs = v;
        auto vt = v;
        expect_eq(va, v_sign);
        expect_eq_self(vs, [](auto &x) { return sign_self(x); }, v_sign);
        expect_eq_to(
            vt, v, [](auto &x, const auto &y) { return sign_to(x, y); },
            v_sign);
        vector_c w{6.0 + 8.0i, 0, 6.0i, -7.0};
        vector_c w_sign{0.6 + 0.8i, 0, 1.0i, -1.0};
        auto wa = sign(w);
        auto ws = w;
        auto wt = w;
        expect_eq(wa, w_sign);
        expect_eq_self(ws, [](auto &x) { return sign_self(x); }, w_sign);
        expect_eq_to(
            wt, w, [](auto &x, const auto &y) { return sign_to(x, y); },
            w_sign);
	}
}

TEST(elementary_math, exponents_and_logarithms) {

}