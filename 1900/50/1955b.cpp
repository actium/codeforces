#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, unsigned c, unsigned d, std::vector<unsigned>& b)
{
    std::sort(b.begin(), b.end());

    std::vector<unsigned> a;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            a.push_back(b[0] + i * c + j * d);
    }

    std::sort(a.begin(), a.end());

    answer(a == b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned c, d;
    std::cin >> c >> d;

    std::vector<unsigned> b(n * n);
    std::cin >> b;

    solve(n, c, d, b);
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
