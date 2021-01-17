#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const auto& r : v) {
        const char* separator = "";
        for (const unsigned x : r) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n)
{
    if (n % 2 == 0)
        return no_answer();

    std::vector<std::vector<unsigned>> p(3, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; ++i) {
        p[0][i] = i;
        p[1][i] = i;
        p[2][i] = 2 * i % n;
    }

    answer(p);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

