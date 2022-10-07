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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<unsigned> d[2];
    for (size_t i = 0; i < n; ++i)
        d[a[i]].push_back(b[i]);

    for (std::vector<unsigned>& v : d)
        std::sort(v.begin(), v.end());

    integer s = 0;
    if (d[0].size() == d[1].size())
        s -= std::min(d[0][0], d[1][0]);

    while (d[0].size() > 0 && d[1].size() > 0) {
        for (std::vector<unsigned>& v : d) {
            s += 2 * v.back();
            v.pop_back();
        }
    }

    for (const std::vector<unsigned>& v : d) {
        for (const int x : v)
            s += x;
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
