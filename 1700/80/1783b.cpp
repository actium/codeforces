#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& r : v) {
        const char* separator = "";
        for (const unsigned x : r) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(unsigned n)
{
    std::vector<std::vector<unsigned>> g(n, std::vector<unsigned>(n));
    for (unsigned r = 0, c = 0, v = 1; r < n; ) {
        if ((r + c) % 2 == 0)
            g[r][c] = v;
        else
            g[r][c] = n * n + 1 - v++;

        if (c + 1 < n && g[r][c+1] == 0) {
            ++c;
            continue;
        }
        if (c > 0 && g[r][c-1] == 0) {
            --c;
            continue;
        }
        ++r;
    }

    answer(g);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
