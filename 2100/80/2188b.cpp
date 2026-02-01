#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();
    if (n == 1)
        return answer(1);

    unsigned k = 0;
    for (size_t i = 0, c = 1; i < n; ++i) {
        if (++c == 3)
            s[i] = '1';

        if (s[i] == '1') {
            ++k;
            c = 0;
        }
    }

    k += (s[n-2] == '0' && s[n-1] == '0');

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
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
