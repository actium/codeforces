#include <iostream>
#include <string>

void print(char c)
{
    std::cout << "PRINT " << c << '\n';
}

void left()
{
    std::cout << "LEFT\n";
}

void right()
{
    std::cout << "RIGHT\n";
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    if (2 * k <= n) {
        for (size_t i = 1; i < k; ++i) {
            left();
        }
        for (size_t i = 1; i < n; ++i) {
            print(s[i-1]);
            right();
        }
        print(s.back());
    } else {
        for (size_t i = 0; i < n - k; ++i) {
            right();
        }
        for (size_t i = 1; i < n; ++i) {
            print(s[n-i]);
            left();
        }
        print(s.front());
    }
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

