#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    for (size_t l = 0, r = n-1; s[l] == s[r]; ) {
        size_t k = 0;

        for (const size_t x = l; l < r && s[l] == s[x]; ++l)
            ++k;

        for (const size_t x = r; r > l && s[r] == s[x]; --r)
            ++k;

        if (l == r && k > 0 && s[l] == s[l-1])
            return answer(k + 2);

        if (k < 3)
            return answer(0);
    }

    answer(0);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

