#include <iostream>
#include <string>

void answer(unsigned x)
{
    if (x != 0)
        std::cout << "Controller " << x << '\n';
    else
        std::cout << "Stowaway" << '\n';
}

void solve(unsigned n, unsigned m, unsigned k, int d, const std::string& s)
{
    const size_t t = s.length();

    for (size_t i = 0; i < t; ++i) {
        if (s[i] == '0') {
            m += (d == -1 ? m > 1 : m < n) * d;
        } else {
            m = 0;
        }

        k += d;

        if (m == k)
            return answer(1 + i);

        if (k == 1 || k == n)
            d = -d;

        if (m == 0 && d == -1)
            m = (k == n ? 1 : n);
        if (m == 0 && d == 1)
            m = (k == 1 ? n : 1);
    }

    answer(0);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, k;
    std::cin >> n >> m >> k;

    std::string _, d, s;
    std::cin >> _ >> d >> s;

    solve(n, m, k, d == "head" ? -1 : 1, s);

    return 0;
}
