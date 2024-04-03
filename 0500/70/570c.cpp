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

void solve(std::string& s, const std::vector<std::pair<unsigned, char>>& r)
{
    s.push_back(' ');

    unsigned k = 0;
    {
        unsigned c = 0;
        for (const char x : s) {
            if (x == '.') {
                k += 1 - (c++ == 0);
            } else {
                c = 0;
            }
        }
    }

    for (const std::pair<unsigned, char>& q : r) {
        if (q.second == '.' && s[q.first-1] != '.') {
            k += (q.first > 1 && s[q.first-2] == '.');
            k += (s[q.first] == '.');
        }
        if (q.second != '.' && s[q.first-1] == '.') {
            k -= (q.first > 1 && s[q.first-2] == '.');
            k -= (s[q.first] == '.');
        }

        s[q.first-1] = q.second;

        answer(k);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<unsigned, char>> r(m);
    std::cin >> r;

    solve(s, r);

    return 0;
}
