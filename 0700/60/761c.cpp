#include <iostream>
#include <vector>

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

template <typename F>
std::vector<std::pair<size_t, unsigned>> select(const std::vector<std::string>& s, F&& filter)
{
    const size_t n = s.size(), m = s[0].length();

    const auto distance = [m](size_t x) {
        return std::min(x, m - x);
    };

    std::vector<std::pair<size_t, unsigned>> p;
    for (size_t i = 0; i < n; ++i) {
        size_t x = m;
        for (size_t j = 0; j < m; ++j) {
            if (!filter(s[i][j]))
                continue;

            if (x == m || distance(j) < distance(x))
                x = j;
        }

        if (x != m)
            p.emplace_back(i, distance(x));
    }
    return p;
}

void solve(const std::vector<std::string>& s)
{
    unsigned d = ~0u;
    for (const auto& p : select(s, [](char c) { return isdigit(c); })) {
        for (const auto& q : select(s, [](char c) { return isalpha(c); })) {
            if (q.first == p.first)
                continue;

            for (const auto& r : select(s, [](char c) { return !isalnum(c); })) {
                if (r.first != p.first && r.first != q.first)
                    d = std::min(d, p.second + q.second + r.second);
            }
        }
    }

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}