#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    unsigned q = 0;
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (s[j] == 'B' && (i + 1 == n || i - j + 1 == k))
            ++q;

        if (s[j] == 'W' || i - j + 1 == k)
            j = i + 1;
    }

    answer(q);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
