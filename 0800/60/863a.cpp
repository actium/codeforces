#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x)
{
    while (x % 10 == 0 && x != 0)
        x /= 10;

    std::string s;
    while (x != 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }

    const size_t n = s.length();
    for (size_t i = 0; i < n/2; ++i) {
        if (s[i] != s[n-1-i])
            return answer(false);
    }

    answer(true);
}

int main()
{
    unsigned x;
    std::cin >> x;

    solve(x);

    return 0;
}

