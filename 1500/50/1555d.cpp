#include <iostream>
#include <string>
#include <vector>

constexpr std::string_view t[6] = { "abc", "acb", "bac", "bca", "cab", "cba" };

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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = s.length();

    std::vector<unsigned> d[6];
    for (size_t i = 0; i < 6; ++i) {
        d[i].resize(1 + n);

        for (size_t j = 0; j < n; ++j)
            d[i][j+1] = d[i][j] + (s[j] != t[i][j%3]);
    }

    for (const std::pair<unsigned, unsigned>& q : r) {
        unsigned v = ~0u;
        for (size_t i = 0; i < 6; ++i)
            v = std::min(v, d[i][q.second] - d[i][q.first-1]);

        answer(v);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(s, r);

    return 0;
}
