#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::vector<std::pair<unsigned, unsigned>> f(n);
    for (size_t i = 0; i < n; ++i) {
        for (const char c : s[i]) {
            f[i].first += (c == '0');
            f[i].second += (c == '1');
        }
    }

    std::vector<unsigned> t = { 0, oo, oo, oo };
    for (size_t i = 0; i < n; ++i) {
        t = {
            t[0] + std::min(f[i].first, f[i].second),
            std::min(t[0] + f[i].second, t[1] + f[i].first),
            std::min(t[0] + f[i].first, t[2] + f[i].second),
            std::min(std::min(t[1] + f[i].first, t[2] + f[i].second), t[3] + std::min(f[i].first, f[i].second))
        };
    }

    answer(t[1] == 0 || t[2] == 0 ? 0 : t[3]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
