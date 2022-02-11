#include <iostream>
#include <queue>
#include <string>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

struct Node {
    size_t x;
    size_t y;
    unsigned t;
};

void solve(const std::vector<std::string>& a, size_t k)
{
    const size_t n = a[0].size();

    std::queue<Node> q;
    std::vector<std::vector<bool>> v(2, std::vector<bool>(n));

    const auto enqueue = [&](size_t x, size_t y, unsigned t) {
        if (a[x][y] == '-' && !v[x][y]) {
            q.push({ x, y, t });
            v[x][y] = true;
        }
    };

    for (enqueue(0, 0, 0); !q.empty(); q.pop()) {
        const Node p = q.front();
        if (p.y + k >= n)
            return answer(true);

        if (p.y > p.t + 1)
            enqueue(p.x, p.y-1, p.t+1);

        enqueue(p.x, p.y+1, p.t+1);
        enqueue(p.x^1, p.y+k, p.t+1);
    }

    answer(false);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> a(2);
    std::cin >> a[0] >> a[1];

    solve(a, k);

    return 0;
}
