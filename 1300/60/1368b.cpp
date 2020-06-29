#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

integer product(const std::vector<integer>& v)
{
    integer p = 1;
    for (const auto x : v)
        p *= x;

    return p;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(integer k)
{
    const char pattern[] = "codeforces";

    std::vector<integer> v(10, 1);
    for (size_t i = 0; product(v) < k; ++v[i++ % 10]);

    std::string y;
    for (size_t i = 0; i < 10; ++i) {
        y += std::string(v[i], pattern[i]);
    }

    answer(y);
}

int main()
{
    integer k;
    std::cin >> k;

    solve(k);

    return 0;
}

