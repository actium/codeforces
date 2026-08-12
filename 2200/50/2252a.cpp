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
    unsigned f[1001] = {};
    for (const unsigned x : a)
        ++f[x];

    unsigned t = 0;
    for (unsigned i = 1; i <= 1000; ++i) {
        if (f[i] > f[t])
            t = i;
    }

    unsigned s = 0;
    for (const unsigned x : a) {
        if (x != t)
            s += x;
    }

    answer(s + std::min<unsigned>(f[t], a.size() - f[t] + 2) * t);
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
