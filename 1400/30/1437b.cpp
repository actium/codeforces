#include <iostream>
#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '1' && s[(i+1)%n] == '1')
            ++k;
    }

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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

