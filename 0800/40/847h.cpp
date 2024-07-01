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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    if (n == 1)
        return answer(0);

    std::vector<std::pair<unsigned, integer>> p(n), s(n);
    p[0].first = a[0];
    s[n-1].first = a[n-1];
    for (size_t i = 1; i < n; ++i) {
        p[i].first = std::max(p[i-1].first + 1, a[i]);
        p[i].second = p[i-1].second + p[i].first - a[i];

        s[n-1-i].first = std::max(s[n-i].first + 1, a[n-1-i]);
        s[n-1-i].second = s[n-i].second + s[n-1-i].first - a[n-1-i];
    }

    integer h = ~integer(0);
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) {
            const integer d = std::max(p[i-1].first + 1, s[i].first) - s[i].first;
            h = std::min(h, p[i-1].second + s[i].second + d);
        }
        if (i + 1 < n) {
            const integer d = std::max(p[i].first, s[i+1].first + 1) - p[i].first;
            h = std::min(h, p[i].second + s[i+1].second + d);
        }
    }

    answer(h);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
