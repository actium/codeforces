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

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& e)
{
    const size_t n = e.size();

    std::vector<std::vector<unsigned>> p;
    for (size_t i = 0; i < n; ++i) {
        if (e[i].first != 0)
            continue;

        p.emplace_back();
        for (unsigned x = 1 + i; x != 0; x = e[x-1].second)
            p.back().push_back(x);
    }

    for (size_t i = 1; i < p.size(); ++i) {
        const unsigned u = p[i-1].back(), v = p[i].front();
        e[u-1].second = v;
        e[v-1].first = u;
    }

    answer(e);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> e(n);
    std::cin >> e;

    solve(e);

    return 0;
}
