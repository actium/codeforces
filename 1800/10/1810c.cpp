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

void solve(std::vector<unsigned>& a, integer c, integer d)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    const size_t k = std::unique(a.begin(), a.end()) - a.begin();
    a.resize(k);

    integer x = n * c + d;
    for (integer s = (n - k) * c; !a.empty(); s += c) {
        x = std::min(x, s + (a.back() - a.size()) * d);
        a.pop_back();
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned c, d;
    std::cin >> c >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, c, d);
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
