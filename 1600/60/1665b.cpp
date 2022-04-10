#include <iostream>
#include <map>
#include <vector>

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

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::map<int, unsigned> f;
    for (const int x : a)
        ++f[x];

    unsigned c = 0;
    for (const auto& e : f)
        c = std::max(c, e.second);

    unsigned k = 0;
    while (c < n) {
        k += std::min<unsigned>(n - c, c) + 1;
        c *= 2;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
