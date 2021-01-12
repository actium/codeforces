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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size(), m = s[0].length();

    unsigned k = ~0u;
    for (size_t j = 0; j < m; ++j) {
        const std::string t = s[0].substr(j) + s[0].substr(0, j);

        unsigned c = j;
        for (size_t i = 1; i < n; ++i) {
            size_t j = 0;
            while (j < m && s[i].substr(j) + s[i].substr(0, j) != t)
                ++j;

            if (j == m)
                return no_answer();

            c += j;
        }

        k = std::min(k, c);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

