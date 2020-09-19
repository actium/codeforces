#include <algorithm>
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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a, int x)
{
    const unsigned k = std::count(a.cbegin(), a.cend(), x);
    if (k == a.size())
        return answer(0);

    const int d = std::accumulate(a.cbegin(), a.cend(), 0, [x](int s, int r) { return s + (x - r); });
    answer(d == 0 || k > 0 ? 1 : 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int x;
    std::cin >> x;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

