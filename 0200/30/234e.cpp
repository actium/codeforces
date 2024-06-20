#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using team_t = std::pair<std::string, unsigned>;

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

void answer(const std::vector<std::vector<std::string>>& v)
{
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << "Group " << char('A' + i) << ':' << '\n';
        for (size_t j = 0; j < 4; ++j)
            std::cout << v[i][j] << '\n';
    }
}

void solve(std::vector<team_t>& t, unsigned x, unsigned a, unsigned b, unsigned c)
{
    const size_t n = t.size(), m = n / 4;

    const auto randomize = [&] {
        const unsigned y = (x * a + b) % c;
        x = y;
        return x;
    };

    std::sort(t.begin(), t.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second > rhs.second;
    });

    std::vector<std::string> bs[4];
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < m; ++j)
            bs[i].push_back(t[i*m+j].first);
    }

    std::vector<std::vector<std::string>> g(m);
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            const size_t p = randomize() % bs[j].size();
            g[i].push_back(bs[j][p]);
            bs[j].erase(bs[j].begin() + p);
        }
    }

    answer(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n;
    std::cin >> n;

    unsigned x, a, b, c;
    std::cin >> x >> a >> b >> c;

    std::vector<team_t> t(n);
    std::cin >> t;

    solve(t, x, a, b, c);

    return 0;
}
