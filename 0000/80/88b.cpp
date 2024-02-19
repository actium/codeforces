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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& b, const std::string& s, unsigned x)
{
    const size_t n = b.size(), m = b[0].size();

    std::vector<std::pair<size_t, size_t>> p[27];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            const size_t u = (b[i][j] == 'S' ? 26 : b[i][j] - 'a');
            p[u].emplace_back(i, j);
        }
    }

    const auto check = [&](size_t i) {
        for (const std::pair<size_t, size_t>& u : p[i]) {
            for (const std::pair<size_t, size_t>& v : p[26]) {
                const unsigned dr = (u.first < v.first ? v.first - u.first : u.first - v.first);
                const unsigned dc = (u.second < v.second ? v.second - u.second : u.second - v.second);
                if (dr * dr + dc * dc <= x * x)
                    return true;
            }
        }
        return false;
    };

    std::string t;
    for (size_t i = 0; i < 26; ++i) {
        if (!check(i))
            t.push_back('A' + i);
    }

    unsigned k = 0;
    for (const char c : s) {
        if (p[std::tolower(c)-'a'].empty())
            return no_answer();

        if (std::isupper(c) && p[26].empty())
            return no_answer();

        if (std::isupper(c) && t.find(c) != std::string::npos)
            ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned x;
    std::cin >> x;

    std::vector<std::string> b(n);
    std::cin >> b;

    size_t q;
    std::cin >> q;

    std::string s;
    std::cin >> s;

    solve(b, s, x);

    return 0;
}