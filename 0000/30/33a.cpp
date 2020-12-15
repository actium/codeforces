#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& c, unsigned k)
{
    unsigned s = 0;
    for (const unsigned x : c)
        s += x;

    answer(std::min(s, k));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> c(m, ~0u);
    for (size_t i = 0; i < n; ++i) {
        unsigned r, x;
        std::cin >> r >> x;

        c[r-1] = std::min(c[r-1], x);
    }

    solve(c, k);

    return 0;
}

