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

void solve(const std::vector<int>& c)
{
    const size_t n = c.size();

    integer s[2] = {}, v = c[0];
    for (size_t i = 0; i < n; ++i) {
        s[i%2] += std::max(c[i], 0);
        v = std::max<integer>(v, c[i]);
    }

    answer(v < 0 ? v : std::max(s[0], s[1]));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> c(n);
    std::cin >> c;

    solve(c);
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
