#include <iostream>
#include <string>

void answer(int v)
{
    constexpr const char s[3] = { '<', '=', '>' };
    std::cout << s[v + 1] << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    int d = 0;

    auto x = a.rbegin(), y = b.rbegin();
    while (x != a.rend() || y != b.rend()) {
        char u = '0';
        if (x != a.rend())
            u = *x++;

        char v = '0';
        if (y != b.rend())
            v = *y++;

        if (u != v)
            d = (u < v ? -1 : +1);
    }

    answer(d);
}

int main()
{
    std::string a;
    std::cin >> a;

    std::string b;
    std::cin >> b;

    solve(a, b);

    return 0;
}

