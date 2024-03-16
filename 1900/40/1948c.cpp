#include <array>
#include <iostream>
#include <queue>
#include <string>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
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

void solve(std::array<std::string, 2>& g)
{
    const size_t n = g[0].length();

    std::queue<std::pair<size_t, size_t>> q;

    const auto enqueue = [&](size_t r, size_t c) {
        if (r < 2 && c < n && g[r][c] != '#') {
            q.emplace(r, c);
            g[r][c] = '#';
        }
    };

    enqueue(0, 0);
    while (!q.empty()) {
        const std::pair<size_t, size_t> p = q.front();
        q.pop();

        if (p.first == 1 && p.second == n - 1)
            return answer(true);

        enqueue(p.first^1, g[p.first^1][p.second] == '<' ? p.second - 1 : p.second + 1);
        if (p.second > 0 && g[p.first][p.second-1] == '<')
            enqueue(p.first, p.second - 2);
        if (p.second + 1 < n && g[p.first][p.second+1] == '>')
            enqueue(p.first, p.second + 2);
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::array<std::string, 2> g;
    std::cin >> g;

    solve(g);
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
