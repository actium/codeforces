#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t m;
    std::cin >> m;

    unsigned f[30] = {};

    const auto check = [&](unsigned v) {
        unsigned g[31] = {};
        for (unsigned i = 0; i < 30; ++i) {
            const unsigned b = (v >> i) & 1;
            if (b == 1 && f[i] + g[i] == 0)
                return false;

            g[i+1] = (f[i] + g[i] - b) / 2;
        }
        return true;
    };

    for (size_t i = 0; i < m; ++i) {
        unsigned t, v;
        std::cin >> t >> v;

        if (t == 1)
            ++f[v];
        else
            answer(check(v));
    }

    return 0;
}
