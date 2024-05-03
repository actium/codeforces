#include <iostream>
#include <vector>

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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "IMPOSSIBLE" << '\n';
}

void solve(unsigned n, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t m = r.size();

    unsigned u = std::max(r[0].second + r[0].first - 1, r[m-1].second + n - r[m-1].first);
    for (size_t i = 1; i < m; ++i) {
        const unsigned d = r[i].first - r[i-1].first, hp = r[i-1].second, hq =r[i].second;

        const unsigned dh = std::max(hp, hq) - std::min(hp, hq);
        if (dh > d)
            return no_answer();

        u = std::max(u, std::max(hp, hq) + (d - dh) / 2);
    }

    answer(u);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(n, r);

    return 0;
}
