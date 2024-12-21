#include <iostream>
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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t p = 0;
    while (p < n && a[p] == 0)
        ++p;

    if (p == n)
        return answer(0);

    size_t s = n-1;
    while (s > p && a[s] == 0)
        --s;

    size_t x = p;
    while (x < s && a[x] != 0)
        ++x;

    answer(x == s ? 1 : 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
