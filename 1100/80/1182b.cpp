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
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& p)
{
    constexpr unsigned oo = ~0u;

    const size_t h = p.size(), w = p[0].length();

    std::pair<size_t, size_t> gh = { oo, oo }, gv = { oo, oo };
    for (size_t i = 0; i < h; ++i) {
        const size_t j = p[i].find('*');
        if (j == std::string::npos)
            continue;

        if (i < gv.first) {
            gv.first = i;
            gv.second = j;
        }
        if (j < gh.second) {
            gh.first = i;
            gh.second = j;
        }
    }

    if (gh.first == gv.first || gh.second == gv.second || gh.first+1 == h || gv.second+1 == w)
        return answer(false);

    for (size_t i = 0; i < h; ++i) {
        for (size_t j = 0; j < w; ++j) {
            if (p[i][j] != '*')
                continue;

            if (i != gh.first && j != gv.second)
                return answer(false);

            if (i == gh.first && j != gh.second && p[i][j-1] != '*')
                return answer(false);

            if (j == gv.second && i != gv.first && p[i-1][j] != '*')
                return answer(false);
        }
    }

    answer(p[gh.first][gv.second+1] == '*' && p[gh.first+1][gv.second] == '*');
}

int main()
{
    size_t h, w;
    std::cin >> h >> w;

    std::vector<std::string> p(h);
    std::cin >> p;

    solve(p);

    return 0;
}

