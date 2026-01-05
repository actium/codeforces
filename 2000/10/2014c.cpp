#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();
    if (n < 3)
        return no_answer();

    std::sort(a.begin(), a.end());

    integer x = 0;
    for (const unsigned v : a)
        x += v;

    answer(std::max<integer>(2LL * a[n/2] * n - x + 1, 0LL));
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
