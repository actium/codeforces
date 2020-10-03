#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(size_t n)
{
    constexpr const char c[] = { 'W', 'B' };

    std::vector<std::string> b(n, std::string(n, ' '));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            b[i][j] = c[(i + j) % 2];
        }
    }

    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

