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

void solve(unsigned n)
{
    std::vector<unsigned> s(n-1);
    for (size_t i = 2, x = 1; i <= n; ++i) {
        if (s[i-2] != 0)
            continue;

        for (size_t j = i; j <= n; j += i)
            s[j-2] = x;

        ++x;
    }

    answer(s);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

