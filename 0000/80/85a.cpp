#include <array>
#include <iostream>
#include <string>

void answer(const std::array<std::string, 4>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(unsigned n)
{
    std::array<std::string, 4> s;

    for (size_t i = 0; i < 4; ++i)
        s[i].resize(n, ' ');

    if (n % 2 == 0) {
        for (size_t i = 0; i < n; i += 2) {
            s[0][i] = s[0][i+1] = 'a' + i % 4;
            s[3][i] = s[3][i+1] = 'b' + i % 4;
        }
        for (size_t i = 1; i < n; i += 2) {
            s[1][i] = s[1][i+1] = 'm' + i % 4;
            s[2][i] = s[2][i+1] = 'n' + i % 4;
        }
        s[1].front() = s[2].front() = 'y';
        s[1].back() = s[2].back() = 'z';
    } else {
        for (size_t i = 0; i < n; i += 2) {
            s[0][i] = s[0][i+1] = 'a' + i % 4;
            s[1][i] = s[1][i+1] = 'b' + i % 4;
        }
        for (size_t i = 1; i < n; i += 2) {
            s[2][i] = s[2][i+1] = 'm' + i % 4;
            s[3][i] = s[3][i+1] = 'n' + i % 4;
        }
        s[0].back() = s[1].back() = 'y';
        s[2].front() = s[3].front() = 'z';
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

