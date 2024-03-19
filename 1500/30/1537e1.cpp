#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    std::string t;
    for (size_t i = 0; i < k; ++i)
        t.push_back(s[i % n]);

    for (size_t p = 1; p < n; ++p) {
        std::string u;
        for (size_t i = 0; i < k; ++i)
            u.push_back(s[i % p]);

        t = std::min(t, u);
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}