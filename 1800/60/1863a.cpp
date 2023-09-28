#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, const std::string& s)
{
    unsigned p = a, k = a;
    for (const char c : s) {
        if (c == '+') {
            ++a;
            ++p;
            k = std::max(k, a);
        } else {
            --a;
        }
    }

    if (k >= n)
        return answer("YES");

    if (p >= n)
        return answer("MAYBE");

    answer("NO");
}

void test_case()
{
    unsigned n, a, q;
    std::cin >> n >> a >> q;

    std::string s;
    std::cin >> s;

    solve(n, a, s);
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
