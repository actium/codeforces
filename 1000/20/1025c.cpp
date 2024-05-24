#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t k = 0;
    for (size_t i = 1, j = 0; i < 2 * n; ++i) {
        if (s[i % n] == s[(i - 1) % n])
            j = i;

        k = std::max(k, i - j + 1);
    }

    answer(std::min(k, n));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
