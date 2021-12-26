#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, size_t>>& b)
{
    const size_t n = a.size();

    std::vector<std::vector<unsigned>> c(1 + n, a);
    for (size_t i = 1; i <= n; ++i) {
        std::vector<unsigned> f(1 + n);
        for (const unsigned x : c[i-1])
            ++f[x];

        for (size_t j = 0; j < n; ++j)
            c[i][j] = f[c[i-1][j]];
    }

    for (const auto& q : b)
        answer(c[std::min(q.second, n)][q.first - 1]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<unsigned, size_t>> b(q);
    std::cin >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
