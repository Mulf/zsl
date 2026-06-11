#pragma once

#include "basics/basics.h"

namespace zsl {

template<typename R>
concept IndexRange = requires(R r, std::size_t i) {
    requires std::same_as<typename R::value_type, std::size_t>;
    typename R::iterator;
    { r.size() } -> std::same_as<std::size_t>;
    requires std::same_as<std::remove_cvref_t<decltype(r[i])>, std::size_t>;
    requires std::same_as<std::remove_cvref_t<decltype(r.at(i))>, std::size_t>;
    { r.begin() } -> std::same_as<typename R::iterator>;
    { r.end() } -> std::same_as<typename R::iterator>;
};

struct Colon;
namespace detail {
class colon_iterator {
public:
    using difference_type = int;
    using value_type = std::size_t;

    colon_iterator() = delete;
    colon_iterator(const colon_iterator &rhs): _cln{rhs._cln}, _idx{rhs._idx} {}
    colon_iterator operator=(const colon_iterator &rhs) {
        _cln = rhs._cln;
        _idx = rhs._idx;
    }
    colon_iterator(colon_iterator &&rhs) noexcept:
        _cln{rhs._cln}, _idx{rhs._idx} {}
    colon_iterator operator=(colon_iterator &&rhs) noexcept {
        _cln = rhs._cln;
        _idx = rhs._idx;
    }
    colon_iterator(const Colon &cln, std::size_t idx): _cln{cln}, _idx{idx} {}

    std::size_t operator*() const;
    std::size_t size() const;

    colon_iterator operator+(difference_type n) const {
        int idx = static_cast<int>(_idx) + n;
        const std::size_t N = size();
        if (idx > static_cast<int>(N))
            idx = static_cast<int>(N);
        else if (idx <= 0)
            idx = 0;
        return {_cln, static_cast<std::size_t>(idx)};
    }

    colon_iterator &operator+=(difference_type n) {
        int idx = static_cast<int>(_idx) + n;
        const std::size_t N = size();
        if (idx > static_cast<int>(N))
            idx = static_cast<int>(N);
        else if (idx <= 0)
            idx = 0;
        _idx = static_cast<std::size_t>(idx);
        return *this;
    }

    colon_iterator &operator++() {
        ++_idx;
        return *this;
    }

    colon_iterator operator++(int) {
        auto prev = *this;
        ++*this;
        return prev;
    }

    colon_iterator operator-(difference_type n) const {
        int idx = static_cast<int>(_idx) - n;
        const std::size_t N = size();
        if (idx > static_cast<int>(N))
            idx = static_cast<int>(N);
        else if (idx <= 0)
            idx = 0;
        return {_cln, static_cast<std::size_t>(idx)};
    }

    difference_type operator-(const colon_iterator &rhs) const {
        return static_cast<int>(_idx) - static_cast<int>(rhs._idx);
    }

    colon_iterator &operator-=(difference_type n) {
        int idx = static_cast<int>(_idx) - n;
        const std::size_t N = size();
        if (idx > static_cast<int>(N))
            idx = static_cast<int>(N);
        else if (idx <= 0)
            idx = 0;
        _idx = static_cast<std::size_t>(idx);
        return *this;
    }

    colon_iterator &operator--() {
        --_idx;
        return *this;
    }

    colon_iterator operator--(int) {
        auto prev = *this;
        --*this;
        return prev;
    }

    auto operator<=>(const colon_iterator &rhs) const {
        return _idx <=> rhs._idx;
    }

    bool operator==(const colon_iterator &rhs) const {
        return _idx == rhs._idx;
    }

    bool operator!=(const colon_iterator &rhs) const {
        return _idx != rhs._idx;
    }

private:
    std::reference_wrapper<const Colon> _cln;
    std::size_t _idx{0};
};

} // namespace detail

struct Colon {
    std::size_t first;
    std::size_t last;
    int interval;
    Colon() = default;
    Colon(size_t first, size_t last): Colon(first, 1, last) {}
    Colon(size_t first, int interval, size_t last):
        first{first}, interval{interval}, last{last} {}

    using iterator = detail::colon_iterator;
    using value_type = std::size_t;

    vector_sz to_vector() const;
    std::size_t at(std::size_t idx) const;
    std::size_t operator[](std::size_t idx) const { return at(idx); }
    std::size_t size() const;
    std::size_t count() const { return size();  }
    iterator begin() const;
    iterator end() const;
};



template<Vector V, IndexRange Rng>
auto seg(const V &v, const Rng &rng) {
    const auto N = rng.size();
    using T = element_type_t<V>;
    std::vector<T> r(N);
    for (std::size_t i = 0; i < N; i++) {
        auto idx = rng.at(i);
        r[i] = v[idx];
    }
    return r;
}

template<Vector R, Vector V, IndexRange Rng>
void seg_to(R &r, const V &v, const Rng &rng) {
    const auto N = rng.size();
    for (std::size_t i = 0; i < N; i++) {
        auto idx = rng.at(i);
        r[i] = v[idx];
    }
}

template<Vector V, IndexRange Rng, Vector W>
auto set_seg(const V &v, const Rng &rng, const W &w) {
    using T = element_type_t<V>;
    const auto N = rng.size();
    std::vector<T> r(N);
    for (std::size_t i = 0; i < N; i++) {
        r[i] = v[i];
    }
    for (std::size_t i = 0; i < N; i++) {
        auto idx = rng.at(i);
        r[idx] = w[i];
    }
    return r;
}

template<Vector V, IndexRange Rng, Vector W>
void set_seg_self(V &v, const Rng &rng, const W &w) {
    const auto N = rng.size();
    for (std::size_t i = 0; i < N; i++) {
        auto idx = rng.at(i);
        v[idx] = w[i];
    }
}

template<Vector R, Vector V, IndexRange Rng, Vector W>
void set_seg_to(R &r, const V &v, const Rng &rng, const W &w) {
    const auto N = rng.size();
    for (std::size_t i = 0; i < N; i++) {
        r[i] = v[i];
    }

    for (std::size_t i = 0; i < N; i++) {
        auto idx = rng.at(i);
        r[idx] = w[i];
    }
}

template<Matrix M, IndexRange RngRow, IndexRange RngCol>
auto block(const M &m, const RngRow &rngRow, const RngCol &rngCol) {
    const auto ROW = rngRow.size();
    const auto COL = rngCol.size();
    using T = element_type_t<M>;
    std::vector<std::vector<T>> r(ROW, std::vector<T>(COL));
    for (std::size_t i = 0; i < ROW; i++) {
        auto row = rngRow.at(i);
        for (std::size_t j = 0; j < COL; j++) {
            auto col = rngCol.at(j);
            at(r, i, j) = at(m, row, col);
        }
    }
    return r;
}

template<Matrix R, Matrix M, IndexRange RngRow, IndexRange RngCol>
void block_to(R &r, const M &m, const RngRow &rngRow, const RngCol &rngCol) {
    const auto ROW = rngRow.size();
    const auto COL = rngCol.size();
    using T = element_type_t<M>;
    for (std::size_t i = 0; i < ROW; i++) {
        auto row = rngRow.at(i);
        for (std::size_t j = 0; j < COL; j++) {
            auto col = rngCol.at(j);
            at(r, i, j) = at(m, row, col);
        }
    }
}

template<Matrix M, IndexRange RngRow, IndexRange RngCol, Matrix P>
auto set_block(
    const M &m, const RngRow &rngRow, const RngCol &rngCol, const P &p) {
    const auto [mROW, mCOL] = dim(m);
    using T = element_type_t<M>;
    std::vector<std::vector<T>> r(mROW, std::vector<T>(mCOL));
    for (std::size_t i = 0; i < mROW; i++) {
        for (std::size_t j = 0; j < mCOL; j++) {
            at(r, i, j) = at(m, i, j);
        }
    }

    const auto ROW = rngRow.size();
    const auto COL = rngCol.size();
    for (std::size_t i = 0; i < ROW; i++) {
        auto row = rngRow.at(i);
        for (std::size_t j = 0; j < COL; j++) {
            auto col = rngCol.at(j);
            at(r, row, col) = at(p, i, j);
        }
    }
    return r;
}

template<Matrix M, IndexRange RngRow, IndexRange RngCol, Matrix P>
void set_block_self(
    M &m, const RngRow &rngRow, const RngCol &rngCol, const P &p) {
    const auto ROW = rngRow.size();
    const auto COL = rngCol.size();
    for (std::size_t i = 0; i < ROW; i++) {
        auto row = rngRow.at(i);
        for (std::size_t j = 0; j < COL; j++) {
            auto col = rngCol.at(j);
            at(m, row, col) = at(p, i, j);
        }
    }
}

template<Matrix R, Matrix M, IndexRange RngRow, IndexRange RngCol, Matrix P>
void set_block_to(
    R &r, const M &m, const RngRow &rngRow, const RngCol &rngCol, const P &p) {
    const auto [mROW, mCOL] = dim(m);
    for (std::size_t i = 0; i < mROW; i++) {
        for (std::size_t j = 0; j < mCOL; j++) {
            at(r, i, j) = at(m, i, j);
        }
    }

    const auto ROW = rngRow.size();
    const auto COL = rngCol.size();
    for (std::size_t i = 0; i < ROW; i++) {
        auto row = rngRow.at(i);
        for (std::size_t j = 0; j < COL; j++) {
            auto col = rngCol.at(j);
            at(r, row, col) = at(p, i, j);
        }
    }
}

template<Matrix M>
auto col(const M &m, size_t n) {
    using T = element_type_t<M>;
    const auto [ROW, COL] = dim(m);
    std::vector<T> r(ROW);
    for (std::size_t i = 0; i < ROW; i++)
        r.at(i) = at(m, i, n);
    return r;
}

template<Vector R, Matrix M>
void col_to(R &r, const M &m, size_t n) {
    const auto [ROW, COL] = dim(m);
    for (std::size_t i = 0; i < ROW; i++)
        r.at(i) = at(m, i, n);
}

template<Matrix M, Vector V>
auto set_col(const M &m, size_t n, const V &v) {
    const auto [mROW, mCOL] = dim(m);
    using T = element_type_t<M>;
    std::vector<std::vector<T>> r(mROW, std::vector<T>(mCOL));
    for (std::size_t i = 0; i < mROW; i++) {
        for (std::size_t j = 0; j < mCOL; j++) {
            at(r, i, j) = at(m, i, j);
        }
    }
    for (std::size_t i = 0; i < mROW; i++)
        at(r, i, n) = v[i];
    return r;
}

template<Matrix M, Vector V>
void set_col_self(const M &m, size_t n, const V &v) {
    const auto [mROW, mCOL] = dim(m);
    for (std::size_t i = 0; i < mROW; i++)
        at(m, i, n) = v[i];
}

template<Matrix R, Matrix M, Vector V>
void set_col_to(R &r, const M &m, size_t n, const V &v) {
    const auto [mROW, mCOL] = dim(m);
    for (std::size_t i = 0; i < mROW; i++) {
        for (std::size_t j = 0; j < mCOL; j++) {
            at(r, i, j) = at(m, i, j);
        }
    }
    for (std::size_t i = 0; i < mROW; i++)
        at(r, i, n) = v[i];
}

template<Matrix M>
auto row(const M &m, size_t n) {
    using T = element_type_t<M>;
    const auto [ROW, COL] = dim(m);
    std::vector<T> r(COL);
    for (std::size_t i = 0; i < COL; i++)
        r.at(i) = at(m, n, i);
    return r;
}

template<Vector R, Matrix M>
void row_to(R &r, const M &m, size_t n) {
    const auto [ROW, COL] = dim(m);
    for (std::size_t i = 0; i < COL; i++)
        r.at(i) = at(m, n, i);
}

template<Matrix M, Vector V>
auto set_row(const M &m, size_t n, const V &v) {
    const auto [mROW, mCOL] = dim(m);
    using T = element_type_t<M>;
    std::vector<std::vector<T>> r(mROW, std::vector<T>(mCOL));
    for (std::size_t i = 0; i < mROW; i++) {
        for (std::size_t j = 0; j < mCOL; j++) {
            at(r, i, j) = at(m, i, j);
        }
    }
    for (std::size_t i = 0; i < mCOL; i++)
        at(r, n, i) = v[i];
    return r;
}

template<Matrix M, Vector V>
void set_row_self(const M &m, size_t n, const V &v) {
    const auto [mROW, mCOL] = dim(m);
    for (std::size_t i = 0; i < mCOL; i++)
        at(m, n, i) = v[i];
}

template<Matrix R, Matrix M, Vector V>
void set_row_to(R &r, const M &m, size_t n, const V &v) {
    const auto [mROW, mCOL] = dim(m);
    for (std::size_t i = 0; i < mROW; i++) {
        for (std::size_t j = 0; j < mCOL; j++) {
            at(r, i, j) = at(m, i, j);
        }
    }
    for (std::size_t i = 0; i < mCOL; i++)
        at(r, n, i) = v[i];
}



}