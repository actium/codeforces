#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& h, unsigned k)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + a[i];

    std::vector<unsigned> s(n, 1);
    for (size_t i = n - 1; i > 0; --i) {
        if (h[i-1] % h[i] == 0)
            s[i-1] = s[i] + 1;
    }

    size_t d = 0;
    for (size_t i = 0, j = 0; i < n; ++i) {
        while (j < i + s[i] && p[j+1] - p[i] <= k)
            ++j;

        d = std::max(d, j - i);
    }

    answer(d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n), h(n);
    std::cin >> a >> h;

    solve(a, h, k);
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
