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

struct Cross {
    unsigned x;
    unsigned y;
    unsigned r;
};

void answer(const Cross& c)
{
    std::cout << c.y << ' ' << c.x << '\n';
    std::cout << c.y - c.r << ' ' << c.x << '\n';
    std::cout << c.y + c.r << ' ' << c.x << '\n';
    std::cout << c.y << ' ' << c.x - c.r << '\n';
    std::cout << c.y << ' ' << c.x + c.r << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& s, size_t k)
{
    const size_t n = s.size(), m = s[0].size();

    std::vector<Cross> c;
    for (size_t i = 1; i + 1 < n; ++i) {
        for (size_t j = 1; j + 1 < m; ++j) {
            if (s[i][j] != '*')
                continue;

            for (size_t r = 1; r <= i && i + r < n && r <= j && j + r < m; ++r) {
                if (s[i-r][j] == '*' && s[i][j+r] == '*' && s[i+r][j] == '*' && s[i][j-r] == '*')
                    c.push_back({ 1 + j, 1 + i, r });
            }
        }
    }

    if (c.size() < k)
        return no_answer();

    std::sort(c.begin(), c.end(), [](const Cross& lhs, const Cross& rhs) {
        if (lhs.r != rhs.r)
            return lhs.r < rhs.r;

        return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
    });

    answer(c[k-1]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, k);

    return 0;
}
