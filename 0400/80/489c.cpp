#include <iostream>
#include <string>

void answer(const std::string& x, const std::string& y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << ' ' << -1 << '\n';
}

void solve(unsigned m, unsigned s)
{
    if (s == 0 && m != 1 || m * 9 < s)
        return no_answer();

    std::string x(m, '0');

    size_t j = m - 1;
    while (s > 9) {
        x[j--] = '9';
        s -= 9;
    }
    x[j] = '0' + s;

    const std::string y(x.rbegin(), x.rend());

    --x[j], ++x[0];

    answer(x, y);
}

int main()
{
    unsigned m, s;
    std::cin >> m >> s;

    solve(m, s);

    return 0;
}
