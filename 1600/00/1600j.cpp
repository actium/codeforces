#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << ' ';

    std::cout << '\n';
}

unsigned count(const std::vector<std::vector<unsigned>>& b, size_t i, size_t j, std::vector<std::vector<bool>>& v)
{
    const size_t n = b.size(), m = b[0].size();

    std::queue<std::pair<size_t, size_t>> q;

    const auto enqueue = [&](size_t i, size_t j) {
        if (i < n && j < m && !v[i][j]) {
            q.emplace(i, j);
            v[i][j] = true;
        }
    };

    unsigned k = 0;
    for (enqueue(i, j); !q.empty(); q.pop()) {
        const std::pair<size_t, size_t> p = q.front();

        if ((b[p.first][p.second] & 0x8) == 0)
            enqueue(p.first-1, p.second);

        if ((b[p.first][p.second] & 0x4) == 0)
            enqueue(p.first, p.second+1);

        if ((b[p.first][p.second] & 0x2) == 0)
            enqueue(p.first+1, p.second);

        if ((b[p.first][p.second] & 0x1) == 0)
            enqueue(p.first, p.second-1);

        ++k;
    }

    return k;
}

void solve(const std::vector<std::vector<unsigned>>& b)
{
    const size_t n = b.size(), m = b[0].size();

    std::vector<unsigned> c;

    std::vector<std::vector<bool>> v(n, std::vector<bool>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (!v[i][j])
                c.push_back(count(b, i, j, v));
        }
    }

    std::sort(c.begin(), c.end(), std::greater<unsigned>());
    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> b(n, std::vector<unsigned>(m));
    std::cin >> b;

    solve(b);

    return 0;
}
