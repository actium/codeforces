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

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() / 3 << '\n';

    const char* separator = "";
    for (const auto& x : v) {
        std::cout << separator << 1+x.first << ' ' << 1+x.second;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<std::pair<size_t, size_t>> q;

    const auto flip = [&](const std::pair<size_t, size_t>& p) {
        q.push_back(p);
        g[p.first][p.second] ^= 1;
    };

    const auto flip2 = [&](std::vector<std::pair<size_t, size_t>> p[2]) {
        flip(p[1].back());
        flip(p[0].front());
        std::swap(p[1].back(), p[0].front());

        flip(p[0].back());
        p[1].push_back(p[0].back());
        p[0].pop_back();
    };

    const auto flip4 = [&](std::vector<std::pair<size_t, size_t>> p[2]) {
        for (size_t i = 0; i < 3; ++i) {
            flip(p[1].back());
            p[0].push_back(p[1].back());
            p[1].pop_back();
        }
    };

    for (size_t i = 0; i < n-1; ++i) {
        for (size_t j = 0; j < m-1; ++j) {
            std::vector<std::pair<size_t, size_t>> p[2];
            for (size_t di = 0; di < 2; ++di) {
                for (size_t dj = 0; dj < 2; ++dj)
                    p[g[i+di][j+dj] == '1'].emplace_back(i+di, j+dj);
            }

            switch (p[1].size()) {
                case 4: flip4(p);
                case 1: flip2(p);
                case 2: flip2(p);
                case 3: flip4(p);
            }
        }
    }

    answer(q);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

