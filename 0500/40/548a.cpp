#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool p(const std::string& s, size_t b, size_t e)
{
    for (size_t i = 0, k = (e - b) / 2; i < k; ++i) {
        if (s[b + i] != s[e-1 - i])
            return false;
    }
    return true;
}

void solve(const std::string& s, unsigned k)
{
    const size_t n = s.length();
    if (n % k != 0)
        return answer(false);

    const size_t d = n / k;
    for (size_t i = 0; i < n; i += d) {
        if (!p(s, i, i + d))
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::string s;
    std::cin >> s;

    unsigned k;
    std::cin >> k;

    solve(s, k);

    return 0;
}

