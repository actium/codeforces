#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.size();

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0')
            continue;

        size_t j = i;
        while (i < n && s[i] == '1')
            ++i;

        if (i - j >= k)
            return no_answer();
    }

    std::vector<unsigned> p(n);
    {
        unsigned x = 1;
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == '1')
                p[i] = x++;
        }
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == '0')
                p[i] = x++;
        }
    }

    answer(p);
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
