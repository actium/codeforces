#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<std::string, 4>& s, unsigned k)
{
    unsigned f[9] = {};
    for (const std::string& x : s) {
        for (const char c : x) {
            if (c != '.')
                ++f[c - '1'];
        }
    }

    for (size_t i = 0; i < 9; ++i) {
        if (f[i] > 2 * k)
            return answer(false);
    }

    answer(true);
}

int main()
{
    unsigned k;
    std::cin >> k;

    std::array<std::string, 4> s;
    std::cin >> s;

    solve(s, k);

    return 0;
}

