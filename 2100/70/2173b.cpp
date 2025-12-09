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

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size();

    std::pair<integer, integer> r = {};
    for (size_t i = 0; i < n; ++i) {
        r = {
            std::min(std::min(r.first - a[i], b[i] - r.first), std::min(r.second - a[i], b[i] - r.second)),
            std::max(std::max(r.first - a[i], b[i] - r.first), std::max(r.second - a[i], b[i] - r.second)),
        };
    }

    answer(r.second);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
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
