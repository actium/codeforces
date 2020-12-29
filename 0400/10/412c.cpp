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

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& p)
{
    const size_t n = p.size(), m = p[0].length();

    std::string s(m, ' ');
    for (size_t i = 0; i < m; ++i) {
        for (const std::string& q : p) {
            if (q[i] == '?')
                continue;

            if (s[i] == ' ')
                s[i] = q[i];

            if (s[i] != q[i])
                s[i] = '?';
        }
        if (s[i] == ' ')
            s[i] = 'a';
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

