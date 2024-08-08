#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x.length() << '\n';
    std::cout << x << '\n';
}

void solve(const std::string& a, size_t k)
{
    const size_t n = a.length();

    std::string b = a;
    for (size_t i = k; i < n; ++i)
        b[i] = b[i-k];

    if (b < a) {
        for (size_t i = k-1; b[i]++ == '9'; --i)
            b[i] = '0';

        for (size_t i = k; i < n; ++i)
            b[i] = b[i-k];
    }

    answer(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::string a;
    std::cin >> a;

    solve(a, k);

    return 0;
}
