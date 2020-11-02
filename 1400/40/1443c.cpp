#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& c)
{
    const size_t n = c.size();

    std::sort(c.begin(), c.end());

    std::vector<integer> s(n+1);
    for (size_t i = n; i-- > 0; )
        s[i] = c[i].second + s[i+1];

    integer v = s[0];
    for (size_t i = 0; i < n; ++i)
        v = std::min(v, std::max<integer>(c[i].first, s[i+1]));

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> c[i].first;
    for (size_t i = 0; i < n; ++i)
        std::cin >> c[i].second;

    solve(c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
