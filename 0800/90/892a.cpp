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

void solve(const std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    unsigned long long s = 0;
    for (const unsigned x : a)
        s += x;

    std::sort(b.begin(), b.end(), std::greater<unsigned>());
    const unsigned long long v = b[0] + b[1];

    answer(s <= v);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b);

    return 0;
}

