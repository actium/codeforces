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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<integer>& d)
{
    const size_t n = d.size() / 2;

    std::sort(d.begin(), d.end(), std::greater<integer>());

    integer s = 0;
    for (size_t i = 0; i < n; ++i) {
        if (d[2*i] != d[2*i+1] || i != 0 && d[2*i] == d[2*i-1])
            return answer(false);

        const unsigned x = 2 * (n - i);
        if (d[2*i] <= s || (d[2*i] - s) % x != 0)
            return answer(false);

        s += 2 * (d[2*i] - s) / x;
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> d(2 * n);
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
