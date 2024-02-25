#include <algorithm>
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

void answer(bool v)
{
    constexpr const char* s[2] = { "LOSE", "WIN" };
    std::cout << s[v] << '\n';
}

struct State {
    std::pair<unsigned, unsigned> p;
    std::vector<std::pair<unsigned, unsigned>> s;

    bool valid() const
    {
        return p.first < 8 && p.second < 8 && std::find(s.begin(), s.end(), p) == s.end();
    }

    State update(int dr, int dc) const
    {
        State x;
        x.p = std::make_pair(p.first + dr, p.second + dc);
        for (const std::pair<unsigned, unsigned>& q : s) {
            if (x.p == q)
                x.p = std::make_pair(~0u, ~0u);

            if (q.first < 7)
                x.s.emplace_back(q.first + 1, q.second);
        }
        return x;
    }
};

void solve(const std::vector<std::string>& g)
{
    State x;
    x.p = std::make_pair(7, 0);
    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 8; ++j) {
            if (g[i][j] == 'S')
                x.s.emplace_back(i, j);
        }
    }

    std::vector<State> q;
    q.push_back(x);
    for (size_t i = 0; i < q.size(); ++i) {
        if (q[i].s.empty())
            return answer(true);

        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                const State w = q[i].update(dr, dc);
                if (w.valid())
                    q.push_back(w);
            }
        }
    }

    answer(false);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::vector<std::string> g(8);
    std::cin >> g;

    solve(g);

    return 0;
}
