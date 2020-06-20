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

    size_t i = 0;
    while (i < n && s[i] != 'G' && s[i] != 'T')
        ++i;

    for (i += k; i < n && s[i] != '#'; i += k) {
        if (s[i] == 'G' || s[i] == 'T')
            return answer(true);
    }

    answer(false);
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

