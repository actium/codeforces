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

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    unsigned x = ~0u;
    for (const std::pair<unsigned, unsigned>& e : s)
        x = std::min(x, e.second - e.first + 1);

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i)
        a[i] = i % x;

    answer(x, a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> s(m);
    std::cin >> s;

    solve(n, s);

    return 0;
}
