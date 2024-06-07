#include <iostream>
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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    std::vector<unsigned> p(n);
    for (size_t i = 0, c = a; i < n; i += c) {
        if ((n - i) % c != 0)
            c ^= a ^ b;

        if (i + c > n)
            return no_answer();

        for (size_t j = c - 1; j > 0; --j)
            p[i+j] = i + j;

        p[i] = i + c;
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}
