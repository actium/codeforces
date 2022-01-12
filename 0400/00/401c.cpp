#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned m)
{
    if (2 * n + 2 < m || n > m + 1)
        return no_answer();

    std::string s;
    s.reserve(n + m);
    while (n + m > 0) {
        if (n > m) s.push_back('0'), --n;

        if (n == m) {
            while (n + m > 0) {
                s.push_back('1'), --m;
                s.push_back('0'), --n;
            }
        }

        if (m > 0) s.push_back('1'), --m;
        if (m > 0) s.push_back('1'), --m;
        if (n > 0) s.push_back('0'), --n;
    }

    answer(s);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
