#include <array>
#include <iostream>
#include <string>

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

template <typename F>
bool check(F&& f)
{
    size_t x = 0, o = 0;
    for (size_t i = 0; i < 5; ++i) {
        switch (f(i)) {
            case 'X': ++x; break;
            case 'O': ++o; break;
        }
    }
    return x == 4 && o == 0;
}

void solve(const std::array<std::string, 10>& g)
{
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            if (i <= 5 && check([&](size_t d) { return g[i+d][j]; }))
                return answer(true);

            if (j <= 5 && check([&](size_t d) { return g[i][j+d]; }))
                return answer(true);

            if (i <= 5 && j <= 5 && check([&](size_t d) { return g[i+d][j+d]; }))
                return answer(true);

            if (i <= 5 && j >= 4 && check([&](size_t d) { return g[i+d][j-d]; }))
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<std::string, 10> g;
    std::cin >> g;

    solve(g);

    return 0;
}
