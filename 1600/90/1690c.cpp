#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& s, const std::vector<unsigned>& f)
{
    const size_t n = s.size();

    std::vector<unsigned> d(n);
    d[0] = f[0] - s[0];
    for (size_t i = 1; i < n; ++i) {
        d[i] = f[i] - std::max(s[i], f[i-1]);
    }

    answer(d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n), f(n);
    std::cin >> s >> f;

    solve(s, f);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
