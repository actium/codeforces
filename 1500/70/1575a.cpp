#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size(), m = s[0].length();

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    const auto compare = [&](size_t x, size_t y) {
        for (size_t i = 0; i < m; ++i) {
            if (s[x][i] != s[y][i])
                return i % 2 == 0 ? s[x][i] < s[y][i] : s[x][i] > s[y][i];
        }
        return false;
    };

    std::sort(o.begin(), o.end(), compare);

    answer(o);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
