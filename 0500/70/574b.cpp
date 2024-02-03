#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

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
    std::cout << -1 << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    std::vector<std::vector<bool>> m(n, std::vector<bool>(n));
    for (const std::pair<unsigned, unsigned>& q : e) {
        m[q.first-1][q.second-1] = true;
        m[q.second-1][q.first-1] = true;
    }

    std::vector<std::vector<unsigned>> g(n);
    for (const std::pair<unsigned, unsigned>& q : e) {
        g[q.first-1].push_back(q.second-1);
        g[q.second-1].push_back(q.first-1);
    }

    unsigned q = oo;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() < 2)
            continue;

        for (const size_t j : g[i]) {
            if (g[j].size() < 2)
                continue;

            for (const size_t k : g[j]) {
                if (m[i][k])
                    q = std::min<unsigned>(q, g[i].size() + g[j].size() + g[k].size() - 6);
            }
        }
    }

    q < oo ? answer(q) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> e(m);
    std::cin >> e;

    solve(n, e);

    return 0;
}
