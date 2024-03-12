#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::vector<std::pair<integer, integer>>& d)
{
    const size_t n = d.size();

    integer s = 0, x = ~integer(0);
    for (size_t i = 0; i < n; ++i) {
        const size_t j = (n + i - 1) % n;

        const integer v = std::min(d[i].first, d[j].second);
        s += d[i].first - v;
        x = std::min(x, v);
    }

    answer(s + x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<integer, integer>> d(n);
    std::cin >> d;

    solve(d);
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
