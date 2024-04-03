#include <iostream>
#include <string>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned m, const std::string& s)
{
    int sr = 1, sc = 1, tr = 1, tc = 1, dr = 0, dc = 0;
    for (const char x : s) {
        if (x == 'U') {
            if (sr + dr - 1 == 0 && tr < n) {
                ++sr;
                ++tr;
            }
            if (sr + dr - 1 > 0) {
                --dr;
                continue;
            }
        }
        if (x == 'R' && sc + dc + 1 <= m) {
            ++dc;
            tc = std::max(tc, sc + dc);
            continue;
        }
        if (x == 'D' && sr + dr + 1 <= n) {
            ++dr;
            tr = std::max(tr, sr + dr);
            continue;
        }
        if (x == 'L') {
            if (sc + dc - 1 == 0 && tc < m) {
                ++sc;
                ++tc;
            }
            if (sc + dc - 1 > 0) {
                --dc;
                continue;
            }
        }
        break;
    }

    answer(sr, sc);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    solve(n, m, s);
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
