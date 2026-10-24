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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const auto r = std::minmax_element(a.begin(), a.end());
    if (*r.first == *r.second)
        return answer(a[0]);

    const auto b = 1 << 32 - __builtin_clz(*r.first ^ *r.second);
    answer(*r.second | b - 1);
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
