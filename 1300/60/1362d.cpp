#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

struct Blog {
    size_t topic;
    std::vector<size_t> adjacents;
};

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    const char* separator = "";
    for (const auto& x : v) {
        std::cout << separator << 1 + x.first;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<Blog>& g)
{
    const size_t n = g.size();

    for (const Blog& b : g) {
        std::unordered_set<size_t> w;
        for (size_t x : b.adjacents) {
            if (g[x].topic == b.topic)
                return answer(-1);

            if (g[x].topic < b.topic)
                w.insert(g[x].topic);
        }
        if (w.size() != b.topic - 1)
            return answer(-1);
    }

    std::vector<std::pair<size_t, size_t>> z(n);
    for (size_t i = 0; i < n; ++i) {
        z[i].first = i;
        z[i].second = g[i].topic;
    }

    std::sort(z.begin(), z.end(), [](const std::pair<size_t, size_t>&a, const std::pair<size_t, size_t>& b) { return a.second < b.second; });

    answer(z);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<Blog> g(n);
    for (size_t i = 0; i < m; ++i) {
        size_t a, b;
        std::cin >> a >> b;

        g[a-1].adjacents.push_back(b-1);
        g[b-1].adjacents.push_back(a-1);
    }
    for (size_t i = 0; i < n; ++i) {
        std::cin >> g[i].topic;
    }

    solve(g);
}

int main()
{
    test_case();

    return 0;
}

