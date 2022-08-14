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

void solve(size_t n, std::vector<unsigned>& a)
{
    const size_t m = a.size();

    std::sort(a.begin(), a.end());

    a.push_back(n + a[0]);      // sentinel

    std::vector<unsigned> r;
    for (size_t i = 0; i < m; ++i)
        r.push_back(a[i+1] - a[i] - 1);
    
    std::sort(r.begin(), r.end(), std::greater<unsigned>());

    unsigned k = 0;
    for (size_t i = 0; i < m && r[i] > 4 * i; ++i)
        k += std::max<unsigned>(r[i] - 4 * i - 1, 1);

    answer(n - k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
