#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const graph_t& g, const std::vector<unsigned>& x)
{
    const size_t n = g.size();

    std::vector<std::pair<size_t, size_t>> q;
    std::vector<bool> v(n);

    const auto enqueue = [&](size_t player, size_t room) {
        if (!v[room]) {
            q.emplace_back(player, room);
            v[room] = true;
        }
    };

    for (const unsigned p : x)
        enqueue(1, p - 1);

    enqueue(0, 0);
    for (size_t i = 0; i < q.size(); ++i) {
        const auto [player, room] = q[i];
        if (player == 0 && room != 0 && g[room].size() == 1)
            return answer(true);

        for (const size_t u : g[room])
            enqueue(player, u);
    }

    answer(false);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> x(k);
    std::cin >> x;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
