#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.size();

    if (2 * k > n)
        return no_answer();

    unsigned q = 0;
    for (size_t i = 0; i < k; ++i) {
        q += (s[i] != 'R');
        q += (s[n-1-i] != 'L');
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
