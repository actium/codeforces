#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& t)
{
    const size_t n = t.length();

    for (size_t i = 2; i <= n; ++i) {
        if (n % i == 0)
            std::reverse(t.begin(), t.begin() + i);
    }

    answer(t);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string t;
    std::cin >> t;

    solve(t);

    return 0;
}

