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

void solve(const std::vector<int>& p)
{
    const int n = p.size() / 2;

    if (n == 1)
        return answer(std::abs(p[0] - p[1]));

    integer s = 0, t = 0, u = 0;
    for (const int x : p) {
        s += std::abs(x);
        t += std::abs(x + 1);
        u += std::abs(x - 2);
    }

    if (n == 2)
        s = std::min(s, u);

    if (n % 2 == 0) {
        for (const int x : p)
            s = std::min(s, t - std::abs(x + 1) + std::abs(x - n));
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> p(2 * n);
    std::cin >> p;

    solve(p);
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
