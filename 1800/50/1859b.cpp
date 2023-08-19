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

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> s(n, std::make_pair(~0u, ~0u));
    for (size_t i = 0; i < n; ++i) {
        for (unsigned x : a[i]) {
            if (x < s[i].first)
                std::swap(x, s[i].first);

            if (x < s[i].second)
                std::swap(x, s[i].second);
        }
    }

    size_t x = 0, y = 0;
    for (size_t i = 1; i < n; ++i) {
        if (s[i].first < s[x].first)
            x = i;

        if (s[i].second < s[y].second)
            y = i;
    }

    integer v = s[x].first;
    for (size_t i = 0; i < n; ++i) {
        if (i != y)
            v += s[i].second;
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n);
    for (size_t i = 0; i < n; ++i) {
        size_t m;
        std::cin >> m;

        a[i].resize(m);
        std::cin >> a[i];
    }

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}