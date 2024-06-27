#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned h, unsigned w, unsigned r, unsigned c, const std::string& s)
{
    std::vector<unsigned> q = { 1 };
    {
        std::vector<std::vector<bool>> v(1 + h, std::vector<bool>(1 + w));
        v[r][c] = true;
        for (const char x : s) {
            switch (x) {
                case 'U': r -= (r > 1); break;
                case 'R': c += (c < w); break;
                case 'D': r += (r < h); break;
                case 'L': c -= (c > 1); break;
            }

            q.push_back(!v[r][c]);
            v[r][c] = true;
        }

        for (unsigned i = 1; i <= h; ++i) {
            for (unsigned j = 1; j <= w; ++j)
                q.back() += !v[i][j];
        }
    }
    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned h, w;
    std::cin >> h >> w;

    unsigned r, c;
    std::cin >> r >> c;

    std::string s;
    std::cin >> s;

    solve(h, w, r, c, s);

    return 0;
}
