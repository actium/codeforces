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

void solve(const std::vector<unsigned>& a, size_t t)
{
    size_t x = 1;
    while (x < t)
        x += a[x-1];

    answer(x == t);
}

int main()
{
    size_t n, t;
    std::cin >> n >> t;

    std::vector<unsigned> a(n-1);
    std::cin >> a;

    solve(a, t);

    return 0;
}

