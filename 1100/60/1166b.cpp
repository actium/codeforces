#include <iostream>
#include <string>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned k)
{
    constexpr const char v[] = { 'a', 'e', 'i', 'o', 'u' };

    size_t n = sizeof(v);
    while (n * n < k && k % n != 0)
        ++n;

    const size_t m = k / n;
    if (k % n != 0 || m < sizeof(v))
        return no_answer();

    std::string s(k, ' ');
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            s[i * m + j] = v[(i + j) % sizeof(v)];
        }
    }

    answer(s);
}

int main()
{
    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}

