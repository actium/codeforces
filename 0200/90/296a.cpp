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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t f[1000] = {};
    for (const unsigned x : a)
        ++f[x - 1];

    size_t max = 0;
    for (const size_t x : f) {
        if (x > max)
            max = x;
    }

    answer(max <= (n + 1) / 2);
}

int main()
{
    std::vector<size_t> f(1001);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

