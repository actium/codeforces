#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string x = s;
    for (size_t i = 0; i < n; ++i) {
        std::string t(n, '0');
        for (size_t j = 0; j < n; ++j)
            t[j] += (10 + s[(i+j)%n] - s[i]) % 10;

        x = std::min(x, t);
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
