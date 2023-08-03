#include <iostream>
#include <vector>

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
    const unsigned n = a.size();

    std::vector<unsigned> f(1 + n);
    for (const unsigned x : a) {
        if (x <= n)
            ++f[x];
    }

    std::vector<unsigned> c(1 + n);
    for (unsigned i = 1; i <= n; ++i) {
        if (f[i] == 0)
            continue;

        for (unsigned j = i; j <= n; j += i)
            c[j] += f[i];
    }

    unsigned k = 0;
    for (unsigned i = 1; i <= n; ++i)
        k = std::max(k, c[i]);

    answer(k);
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
