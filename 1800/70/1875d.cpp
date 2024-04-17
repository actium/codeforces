#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> f(1 + n);
    for (const unsigned x : a) {
        if (x < n)
            ++f[x];
    }

    if (f[0] == 0)
        return answer(0);

    std::vector<unsigned> t(1 + n, oo);
    for (unsigned i = 1; i <= n; ++i) {
        t[i] = (f[0] - 1) * i;
        for (unsigned j = 1; j < i; ++j)
            t[i] = std::min(t[i], (f[j] - 1) * i + j + t[j]);

        if (f[i] == 0)
            return answer(t[i]);
    }

    answer(t[n]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
