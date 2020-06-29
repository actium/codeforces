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

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

#define CHECK(x, y)     do {                                        \
                            const char cell = maze[x][y];           \
                            if (cell == 'B') return false;          \
                            if (cell == '+') return true;           \
                            if (cell != '#' && !visited[x][y]) {    \
                                q.emplace(x, y);                    \
                                visited[x][y] = true;               \
                            }                                       \
                        } while (false)

bool check_path(const std::vector<std::string>& maze, size_t n, size_t m, size_t i, size_t j)
{
    using point_t = std::pair<size_t, size_t>;

    std::queue<point_t> q;
    bool visited[50][50] = {};

    q.emplace(i, j);
    visited[i][j] = true;

    while (!q.empty()) {
        const point_t p = q.front();
        q.pop();
        if (p.first == n-1 && p.second == m-1)
            return true;

        if (p.first > 0)
            CHECK(p.first-1, p.second);
        if (p.first < n-1)
            CHECK(p.first+1, p.second);

        if (p.second > 0)
            CHECK(p.first, p.second-1);
        if (p.second < m-1)
            CHECK(p.first, p.second+1);
    }
    return false;
}

#define SWITCH(x, y)	do {                                        \
                            char& cell = maze[x][y];                \
                            if (cell == 'G') return answer(false);  \
                            if (cell == '.') cell = '#';            \
                        } while (false)

void solve(std::vector<std::string>& maze, size_t n, size_t m)
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (maze[i][j] != 'B')
                continue;

            if (i > 0)
                SWITCH(i-1, j);
            if (i < n-1)
                SWITCH(i+1, j);

            if (j > 0)
                SWITCH(i, j-1);
            if (j < m-1)
                SWITCH(i, j+1);
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (maze[i][j] != 'G')
                continue;

            if (!check_path(maze, n, m, i, j))
                return answer(false);

            maze[i][j] = '+';
        }
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

