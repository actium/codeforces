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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<integer>& m)
{
    const size_t n = a.size();

    std::vector<std::pair<unsigned, unsigned>> s;
    for (size_t i = 1; i < n; ++i) {
        const unsigned u = a[0], v = a[i];
        s.emplace_back(u, v);
        a[0] = std::max(u, v);
        a[i] = std::min(u, v);
    }

    for (const integer x : m) {
        if (x < n)
            answer(s[x-1].first, s[x-1].second);
        else
            answer(a[0], a[1 + (x - 1) % (n - 1)]);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<integer> m(q);
    std::cin >> m;

    solve(a, m);

    return 0;
}
