#include <iostream>
#include <vector>

void answer(unsigned x, const std::vector<std::vector<unsigned>>& y)
{
    std::cout << x << '\n';

    for (const auto& r : y) {
        const char* separator = "";
        for (const unsigned q : r) {
            std::cout << separator << q;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(size_t n, size_t k)
{
    std::vector<std::vector<unsigned>> t(n, std::vector<unsigned>(n));

    unsigned x = 1;
    for (size_t r = 0; r < n; ++r) {
        for (size_t c = 0; c < k; ++c)
            t[r][c] = x++;
    }
    for (size_t r = 0; r < n; ++r) {
        for (size_t c = k; c < n; ++c)
            t[r][c] = x++;
    }

    unsigned s = 0;
    for (size_t r = 0; r < n; ++r)
        s += t[r][k];

    answer(s, t);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    solve(n, k-1);

    return 0;
}

