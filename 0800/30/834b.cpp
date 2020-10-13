#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, unsigned k)
{
    const size_t n = s.length();

    std::pair<unsigned, unsigned> e[26] = {};
    for (size_t i = 0; i < n; ++i) {
        const size_t d = s[i] - 'A';

        if (e[d].first == 0)
            e[d].first = 1 + i;

        e[d].second = 1 + i;
    }

    for (size_t i = 0; i < n; ++i) {
        const size_t d = s[i] - 'A';

        if (e[d].first == 1 + i && k-- == 0)
            return answer(true);

        if (e[d].second == 1 + i)
            ++k;
    }

    answer(false);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

