#include <iostream>
#include <map>
#include <vector>

#include <cmath>

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

void solve(const std::vector<int>& x, const std::vector<unsigned>& r)
{
    const size_t n = x.size();

    std::map<int, integer> s;
    for (size_t i = 0; i < n; ++i) {
        for (integer d = 0; d <= r[i]; ++d) {
            const integer b = sqrt(1ull * r[i] * r[i] - d * d);
            s[x[i]-d] = std::max(s[x[i]-d], b);
            s[x[i]+d] = std::max(s[x[i]+d], b);
        }
    }

    integer k = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
        k += it->second * 2 + 1;

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<int> x(n);
    std::cin >> x;

    std::vector<unsigned> r(n);
    std::cin >> r;

    solve(x, r);
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
