#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    size_t x = 0;
    for (size_t j = 0; x != n-1 && j-x <= k; x = j, j = s.find('.', x+1));

    answer(x == n-1);
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

