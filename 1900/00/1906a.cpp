#include <array>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& s)
{
    std::cout << s << '\n';
}

std::vector<std::pair<size_t, size_t>> adjacents(size_t i, size_t j)
{
    std::vector<std::pair<size_t, size_t>> p;
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            if (di == 0 && dj == 0)
                continue;

            if (i + di <= 2 && j + dj <= 2)
                p.emplace_back(i + di, j + dj);
        }
    }
    return p;
}

void solve(const std::array<std::string, 3>& s)
{
    std::string x = "ZZZ";
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            for (const std::pair<size_t, size_t>& p : adjacents(i, j)) {
                for (const std::pair<size_t, size_t>& q : adjacents(p.first, p.second)) {
                    if (q.first != i || q.second != j) {
                        std::string t;
                        t.push_back(s[i][j]);
                        t.push_back(s[p.first][p.second]);
                        t.push_back(s[q.first][q.second]);

                        x = std::min(x, t);
                    }
                }
            }
        }
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<std::string, 3> s;
    std::cin >> s[0] >> s[1] >> s[2];

    solve(s);

    return 0;
}
