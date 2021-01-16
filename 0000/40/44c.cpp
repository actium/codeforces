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

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    std::vector<unsigned> f(n);
    for (const auto [a, b] : s) {
        for (size_t i = a - 1; i < b; ++i)
            ++f[i];
    }

    size_t x = 0;
    while (x < n && f[x] == 1)
        ++x;

    if (x == n) {
        std::cout << "OK" << '\n';
    } else {
        std::cout << 1+x << ' ' << f[x] << '\n';
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> s(m);
    std::cin >> s;

    solve(n, s);

    return 0;
}

