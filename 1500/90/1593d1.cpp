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

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(std::vector<int>& a)
{
    std::sort(a.begin(), a.end());

    auto it = std::upper_bound(a.begin(), a.end(), a.front());
    if (it == a.end())
        return answer(-1);

    unsigned x = *it - a.front();
    while (++it != a.end())
        x = std::gcd(x, *it - a.front());

    answer(x);
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
