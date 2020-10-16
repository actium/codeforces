#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned b[3] = {}, c = 0, d = n + 1;
    for (auto l = s.begin(), r = s.begin(); r != s.end() || c == 3; ) {
        c += (c < 3 && b[*r++ - '1']++ == 0);
        if (c == 3) {
            d = std::min<unsigned>(d, r - l);
            c -= (--b[*l++ - '1'] == 0);
        }
    }

    answer(d > n ? 0 : d);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

