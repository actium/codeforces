#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

std::string convert(unsigned d, unsigned m, unsigned y)
{
    char s[11];
    sprintf(s, "%02u-%02u-%04u", d, m, y);
    return s;
}

void solve(const std::string& s)
{
    constexpr unsigned t[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    const auto count = [&](const std::string& q) {
        unsigned k = 0;
        for (size_t x = s.find(q); x != std::string::npos; x = s.find(q, x + 1))
            ++k;

        return k;
    };

    std::pair<unsigned, std::string> v = {};
    for (unsigned y = 2013; y <= 2015; ++y) {
        for (unsigned m = 1; m <= 12; ++m) {
            for (unsigned d = 1; d <= t[m-1]; ++d) {
                const std::string q = convert(d, m, y);
                v = std::max(v, std::make_pair(count(q), q));
            }
        }
    }

    answer(v.second);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s + "-");

    return 0;
}
