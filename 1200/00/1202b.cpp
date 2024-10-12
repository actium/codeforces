#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

std::vector<std::vector<unsigned>> prepare(unsigned x, unsigned y)
{
    std::vector<std::vector<unsigned>> d(10, std::vector<unsigned>(10, oo));
    for (unsigned s = 0; s < 10; ++s) {
        for (unsigned cx = 0; cx < 10; ++cx) {
            for (unsigned cy = 0; cy < 10; ++cy) {
                const unsigned t = (s + x * cx + y * cy) % 10;
                d[s][t] = std::min(d[s][t], cx + cy - 1);
            }
        }
    }
    return d;
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned f[10][10] = {};
    for (size_t i = 1; i < n; ++i)
        ++f[s[i-1]-'0'][s[i]-'0'];

    const auto count = [&](const std::vector<std::vector<unsigned>>& d) {
        int c = 0;
        for (unsigned s = 0; s < 10; ++s) {
            for (unsigned t = 0; t < 10; ++t) {
                if (f[s][t] == 0)
                    continue;

                if (d[s][t] == oo)
                    return -1;

                c += f[s][t] * d[s][t];
            }
        }
        return c;
    };

    for (unsigned x = 0; x < 10; ++x) {
        for (unsigned y = 0; y < 10; ++y)
            std::cout << count(prepare(x, y)) << " \n"[y==9];
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
