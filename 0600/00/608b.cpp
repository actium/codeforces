#include <complex>
#include <iostream>
#include <string>
#include <vector>

#include <cmath>

namespace fft {

    using Number = std::complex<double>;

    const double PI = std::acos(-1);

    unsigned base = 1;

    std::vector<Number> rts = { Number(0, 0), Number(1, 0) };
    std::vector<unsigned> rev = { 0, 1 };

    void ensure_base(unsigned x)
    {
        if (x <= base)
            return;

        const size_t q = 1 << x;

        rev.resize(q);
        for (size_t i = 0; i < q; ++i)
            rev[i] = rev[i/2] / 2 + ((i & 1) << (x - 1));

        rts.resize(q);
        while (base < x) {
            const double angle = 2 * PI / (1 << (base + 1));

            for (size_t i = 1 << (base - 1); i < (1 << base); ++i) {
                rts[i << 1] = rts[i];

                const double a = angle * (2 * i + 1 - (1 << base));
                rts[(i << 1) + 1] = Number(std::cos(a), std::sin(a));
            }

            ++base;
        }
    }

    void compute(std::vector<Number>& a)
    {
        const size_t n = a.size(), z = __builtin_ctz(n);

        ensure_base(z);

        const size_t d = base - z;

        for (size_t i = 0; i < n; ++i) {
            if (i < (rev[i] >> d))
                std::swap(a[i], a[rev[i] >> d]);
        }

        for (size_t k = 1; k < n; k <<= 1) {
            for (size_t i = 0; i < n; i += 2 * k) {
                for (size_t j = 0; j < k; ++j) {
                    const Number z = a[i + j + k] * rts[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] += z;
                }
            }
        }
    }

    std::vector<unsigned> multiply(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
    {
        const size_t q = a.size() + b.size() - 1;

        size_t x = 0;
        while ((1 << x) < q)
            ++x;

        ensure_base(x);

        const size_t n = 1 << x;

        std::vector<Number> fa(n);
        for (size_t i = 0; i < a.size(); ++i)
            fa[i] = a[i];
        for (size_t i = 0; i < b.size(); ++i)
            fa[i].imag(b[i]);

        compute(fa);

        const Number r(0, -0.25 / n);
        for (size_t i = 0; i <= n / 2; ++i) {
            const size_t j = (n - i) & (n - 1);

            const Number x = fa[i] * fa[i], y = fa[j] * fa[j], z = (y - std::conj(x)) * r;
            if (i != j)
                fa[j] = (x - std::conj(y)) * r;

            fa[i] = z;
        }

        compute(fa);

        std::vector<unsigned> v(q);
        for (size_t i = 0; i < q; ++i)
            v[i] = round(fa[i].real());

        return v;
    }

} // namespace fft

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = b.length(), m = a.length();

    std::vector<unsigned> p[2];
    for (size_t i = 0; i < 2; ++i) {
        p[i].resize(n);

        for (size_t j = 0; j < n; ++j)
            p[i][j] = (b[j] - '0' == i);
    }

    std::vector<unsigned> q[2];
    for (size_t i = 0; i < 2; ++i) {
        q[i].resize(m);

        for (size_t j = 0; j < m; ++j)
            q[i][j] = (a[m-1-j] - '0' == i);
    }

    std::vector<unsigned> v;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            if (j == i)
                continue;

            auto c = fft::multiply(p[i], q[j]);
            if (v.empty()) {
                v = std::move(c);
            } else {
                for (size_t k = 0; k < v.size(); ++k)
                    v[k] += c[k];
            }
        }
    }

    integer k = 0;
    for (size_t i = m - 1; i < n; ++i)
        k += v[i];

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
