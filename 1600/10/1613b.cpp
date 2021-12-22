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

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned> x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t k = a.size() / 2;

    std::sort(a.begin(), a.end());

    std::vector<std::pair<unsigned, unsigned>> v(k);
    for (size_t i = 0; i < k; ++i)
        v[i] = { a[i+1], a[0] };

    answer(v);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
