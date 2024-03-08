#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
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

void solve(const std::string& s, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = s.length();

    std::vector<unsigned> f[3];
    for (size_t i = 0; i < 3; ++i)
        f[i].resize(1 + n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < 3; ++j)
            f[j][i+1] = f[j][i];

        ++f[s[i]-'x'][i+1];
    }

    const auto query = [&](size_t b, size_t e) {
        if (e - b < 3)
            return true;

        unsigned x = ~0u;
        for (size_t i = 0; i < 3; ++i)
            x = std::min(x, f[i][e] - f[i][b]);

        for (size_t i = 0; i < 3; ++i) {
            if (f[i][e] - f[i][b] - x > 1)
                return false;
        }
        return true;
    };

    for (const std::pair<unsigned, unsigned>& q : r)
        answer(query(q.first - 1, q.second));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(s, r);

    return 0;
}
