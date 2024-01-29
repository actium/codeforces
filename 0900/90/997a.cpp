#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a, unsigned x, unsigned y)
{
    const size_t n = a.length();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == '1')
            continue;

        while (i < n && a[i] == '0')
            ++i;

        ++k;
    }

    answer(k == 0 ? 0 : (k - 1) * std::min<integer>(x, y) + y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    std::string a;
    std::cin >> a;

    solve(a, x, y);

    return 0;
}
