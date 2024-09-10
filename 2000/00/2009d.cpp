#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p)
{
    const size_t n = p.size();

    std::vector<bool> v[2];
    for (size_t i = 0; i < 2; ++i)
        v[i].resize(1+n);

    for (const auto& [x, y] : p)
        v[y][x] = true;

    integer k = 0;
    for (size_t i = 0; i <= n; ++i) {
        if (v[0][i] && v[1][i])
            k += n - 2;

        if (i > 0 && i < n && v[0][i] && v[1][i-1] && v[1][i+1])
            ++k;

        if (i > 0 && i < n && v[1][i] && v[0][i-1] && v[0][i+1])
            ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p);
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
