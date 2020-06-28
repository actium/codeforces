#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    while (n != 0) {
        if (n % 10 == 1) {
            n /= 10;
        } else if (n % 100 == 14) {
            n /= 100;
        } else if (n % 1000 == 144) {
            n /= 1000;
        } else {
            return answer(false);
        }
    }

    answer(true);
}


int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

