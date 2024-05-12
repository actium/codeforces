#include <iostream>
#include <queue>
#include <string>
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

struct State {
    unsigned r;
    unsigned c;
    unsigned d;
    unsigned t;
};

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    unsigned d = ~0u;
    {
        std::queue<State> q;
        q.push({ 1, 0, 0, 0 });
        while (!q.empty()) {
            const State s = q.front();
            q.pop();

            if (s.r > n) {
                d = std::min(d, s.d);
                continue;
            }

            std::vector<unsigned> p;
            for (size_t j = 0; j < m; ++j) {
                if (g[n-s.r][j] == '1')
                    p.push_back(j);
            }

            if (p.empty()) {
                q.push({ s.r+1, 0, s.d, s.t + 1 + s.c });
                q.push({ s.r+1, m-1, s.d, s.t + 1 + (m-1 - s.c) });
            } else {
                const unsigned tx = (s.c < p.front() ? p.back() : p.front());
                const unsigned dx = std::max(s.c, tx) - std::min(s.c, tx);

                q.push({ s.r+1, 0, s.d + s.t + dx, 1 + tx });
                q.push({ s.r+1, m-1, s.d + s.t + dx, 1 + (m-1 - tx) });
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

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}
