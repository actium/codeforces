#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned d)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n; ++i) {
        if (d > s[i] - '0')
            return answer(s.substr(0, i) + char('0' + d) + s.substr(i));
    }

    answer(s + char('0' + d));
}

void test_case()
{
    unsigned n, d;
    std::cin >> n >> d;

    std::string s;
    std::cin >> s;

    solve(s, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
