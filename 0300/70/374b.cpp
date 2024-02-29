#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::string& a)
{
    const size_t n = a.length();

    integer k = 1;
    for (size_t i = 1; i < n; ++i) {
        if (a[i-1] + a[i] != '0' + '9')
            continue;

        size_t x = i + 2;
        while (a[x-1] == a[i-1] && a[x] == a[i])
            x += 2;

        if (a[x-1] == a[i-1])
            k *= (x - i) / 2 + 1;

        i = x - 1;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string a;
    std::cin >> a;

    solve(a);

    return 0;
}
