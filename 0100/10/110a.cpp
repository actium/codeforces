#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned long long n)
{
    size_t count = 0;
    while (n != 0) {
        const unsigned digit = n % 10;
        if (digit == 4 || digit == 7)
            ++count;

        n /= 10;
    }

    answer(count == 4 || count == 7);
}

int main()
{
    unsigned long long n;
    std::cin >> n;

    solve(n);

    return 0;
}

