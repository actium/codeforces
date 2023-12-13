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

void traverse(std::vector<std::string>& g, size_t i, size_t j, std::string& p)
{
    const auto check = [&](size_t i, size_t j, char x) {
        if (i < g.size() && j < g[0].size() && g[i][j] == x) {
            g[i][j] = '.';
            return true;
        }
        return false;
    };

    for (const char x : { '*', 'S' }) {
        if (check(i-1, j, x)) {
            p.push_back('U');
            return traverse(g, i-1, j, p);
        }
        if (check(i, j+1, x)) {
            p.push_back('R');
            return traverse(g, i, j+1, p);
        }
        if (check(i+1, j, x)) {
            p.push_back('D');
            return traverse(g, i+1, j, p);
        }
        if (check(i, j-1, x)) {
            p.push_back('L');
            return traverse(g, i, j-1, p);
        }
    }
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size();

    size_t i = -1, j = std::string::npos;
    while (j == std::string::npos)
        j = g[++i].find('S');

    std::string p;
    traverse(g, i, j, p);

    answer(p);
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
