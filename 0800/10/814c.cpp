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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::vector<std::pair<unsigned, char>>& r)
{
    const size_t n = s.length();

    std::vector<std::vector<unsigned>> t(26, std::vector<unsigned>(n + 1));
    for (size_t c = 0; c < 26; ++c) {
        for (size_t i = 0; i < n; ++i) {
            unsigned k = 0;
            for (size_t j = i; j < n; ++j) {
                k += (s[j] - 'a' != c);
                t[c][k] = std::max<unsigned>(t[c][k], j - i + 1);
            }
        }
        for (size_t i = 1; i <= n; ++i)
            t[c][i] = std::max(t[c][i], t[c][i-1]);
    }

    for (const std::pair<unsigned, char>& q : r)
        answer(t[q.second-'a'][q.first]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<unsigned, char>> r(q);
    std::cin >> r;

    solve(s, r);

    return 0;
}
