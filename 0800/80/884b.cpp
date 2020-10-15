#include <iostream>
#include <numeric>
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

void solve(const std::vector<unsigned>& a, size_t x)
{
    const unsigned s = std::accumulate(a.cbegin(), a.cend(), 0);

    answer(s + a.size() - 1 == x);
}

int main()
{
    size_t n, x;
    std::cin >> n >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);

    return 0;
}

