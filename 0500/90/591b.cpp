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

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, const std::vector<std::pair<char, char>>& r)
{
    char t[26];
    for (size_t i = 0; i < 26; ++i) {
        char c = 'a' + i;
        for (const auto& x : r) {
            if (x.first == c || x.second == c)
                c = x.first + x.second - c;
        }
        t[i] = c;
    }

    for (char& c : s)
        c = t[c - 'a'];

    answer(s);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<char, char>> r(m);
    std::cin >> r;

    solve(s, r);

    return 0;
}

