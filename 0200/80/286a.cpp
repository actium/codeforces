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

void solve(size_t n)
{
    if (n % 4 == 2 || n % 4 == 3)
        return no_answer();

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n / 2; i += 2) {
        p[i+0] = 2 + i;
        p[i+1] = n - i;

        p[n-1-i] = n - 1 - i;
        p[n-2-i] = 1 + i;
    }

    if (n % 2 == 1)
        p[n / 2] = n / 2 + 1;

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}
