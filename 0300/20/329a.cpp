#include <iostream>
#include <string>
#include <vector>

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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size();

    std::vector<std::pair<unsigned, unsigned>> p(n), q(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (g[i][j] != '.')
                continue;

            p[i] = std::make_pair(1 + i, 1 + j);
            q[j] = std::make_pair(1 + i, 1 + j);
        }
    }

    const auto check = [](const std::vector<std::pair<unsigned, unsigned>>& v) {
        for (const std::pair<unsigned, unsigned>& p : v) {
            if (p.first == 0)
                return false;
        }
        return true;
    };

    if (check(p))
        return answer(p);

    if (check(q))
        return answer(q);

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}
