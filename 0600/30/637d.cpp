#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<std::string_view, unsigned>>& v)
{
    for (const std::pair<std::string_view, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "IMPOSSIBLE" << '\n';
}

void solve(std::vector<unsigned>& a, unsigned m, unsigned s, unsigned d)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> b;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] - a[i-1] >= s + 2)
            b.push_back(a[i-1] + 1);
    }
    b.push_back(a.back() + 1);

    std::reverse(b.begin(), b.end());

    std::vector<std::pair<std::string_view, unsigned>> p;
    {
        unsigned x = 0;
        for (size_t i = 0; i < n; ++i) {
            if (a[i] < x)
                continue;

            if (x + s >= a[i] || a[i] - 1 + d < b.back())
                return no_answer();

            p.emplace_back("RUN", (a[i] - 1) - x);
            p.emplace_back("JUMP", b.back() - (a[i] - 1));

            x = b.back();
            b.pop_back();
        }

        if (x < m)
            p.emplace_back("RUN", m - x);
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m, s, d;
    std::cin >> m >> s >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, s, d);

    return 0;
}
