#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    size_t s = 1;
    while (s < n && p[s] == p[0])
        ++s;

    size_t e = n / 2;
    while (e > s && p[e] == p[n/2])
        --e;

    size_t b = s + s + 1;
    while (b < e && p[b] == p[s+s])
        ++b;

    b + s <= e ? answer(s, b - s, e - b + 1) : answer(0, 0, 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
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
