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

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x;

    std::cout << '\n';
}

using segment_t = std::pair<unsigned, unsigned>;

void solve(size_t n, const std::vector<segment_t>& /*s*/)
{
    std::vector<unsigned> f(n);
    for (size_t i = 0; i < n; ++i)
        f[i] = i % 2;

    answer(f);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<segment_t> s(m);
    std::cin >> s;

    solve(n, s);

    return 0;
}

