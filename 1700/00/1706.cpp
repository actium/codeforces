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

void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    std::vector<unsigned> d(n);
    for (size_t i = 1; i < n-1; ++i) {
        const unsigned x = std::max(h[i-1], h[i+1]);
        if (h[i] <= x)
            d[i] = x - h[i] + 1;
    }

    std::vector<integer> p(1+n), s(n+1);
    for (size_t i = 1; i < n; i += 2) {
        p[1+i] = p[i-1] + d[i];
        s[n-i-1] = s[n-i+1] + d[n-1-i];
    }

    if (n % 2 == 1)
        return answer(p[n-1]);

    integer x = ~integer(0);
    for (size_t i = 1; i < n; i += 2) {
        x = std::min(x, p[i-1] + s[i+1]);
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
