#include <iostream>
#include <string>
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

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    const auto distance = [&s](size_t i, size_t j) {
        const size_t m = s[i].length();

        unsigned d = 0;
        for (size_t k = 0; k < m; ++k) {
            d += abs(s[i][k] - s[j][k]);
        }
        return d;
    };

    unsigned r = ~0u;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            r = std::min(r, distance(i, j));
        }
    }

    answer(r);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
