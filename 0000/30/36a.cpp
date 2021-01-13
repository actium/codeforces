#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = s.find('1'), j = i+1, d = 0; j < n; ++j) {
        if (s[j] == '0')
            continue;

        if (d == 0)
            d = j - i;

        if (j - i != d)
            return answer(false);

        i = j;
    }

    answer(true);
}

int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

