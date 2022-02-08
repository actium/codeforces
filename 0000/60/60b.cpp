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

struct Point {
    size_t l;
    size_t r;
    size_t c;
};

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::vector<std::string>>& t, unsigned x, unsigned y)
{
    const size_t k = t.size(), n = t[0].size(), m = t[0][0].length();

    std::queue<Point> q;

    const auto enqueue = [&](size_t l, size_t r, size_t c) {
        if (l < k && r < n && c < m && t[l][r][c] == '.') {
            q.push({ l, r, c });
            t[l][r][c] = '+';
        }
    };

    unsigned c = 0;
    for (enqueue(0, x-1, y-1); !q.empty(); q.pop()) {
        const Point p = q.front();

        enqueue(p.l - 1, p.r, p.c);
        enqueue(p.l + 1, p.r, p.c);
        enqueue(p.l, p.r - 1, p.c);
        enqueue(p.l, p.r + 1, p.c);
        enqueue(p.l, p.r, p.c - 1);
        enqueue(p.l, p.r, p.c + 1);

        ++c;
    }

    answer(c);
}

int main()
{
    size_t k, n, m;
    std::cin >> k >> n >> m;

    std::vector<std::vector<std::string>> t(k, std::vector<std::string>(n));
    std::cin >> t;

    unsigned x, y;
    std::cin >> x >> y;

    solve(t, x, y);

    return 0;
}
