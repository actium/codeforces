#include <bitset>
#include <iostream>

void solve(unsigned n)
{
    std::bitset<1'000'000> s;
    for (size_t i = 1; 2 * i * (i + 1) < 1000000; ++i) {
        for (size_t j = i; 2 * i * j + i + j < 1000000; ++j) {
            s.set(2 * i * j + i + j);
        }
    }

    const char* separator = "";
    for (size_t i = 0, j = 1; i < n; ++i, ++j) {
        std::cout << separator;
        while (s.test(j))
            ++j;

        std::cout << 2 * j + 1;
        separator = " ";
    }
    std::cout << '\n';
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

