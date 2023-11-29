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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = b.size();

    a.push_back(1);

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    unsigned k = 0;
    for (size_t i = 0, j = 0; i < n; ++i)
        a[j] < b[i] ? ++j : ++k;

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n - 1), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
