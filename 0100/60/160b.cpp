#include <algorithm>
#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& number, size_t n)
{
    const auto it = number.begin();
    std::sort(it, it + n);
    std::sort(it + n, it + 2 * n);

    const int start_delta = number[0] - number[n];
    if (start_delta == 0)
        return answer(false);

    for (size_t i = 1; i < n; ++i) {
        const int delta = number[i] - number[i + n];
        if (delta == 0 || delta > 0 != start_delta > 0)
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string number;
    std::cin >> number;

    solve(number, n);

    return 0;
}

