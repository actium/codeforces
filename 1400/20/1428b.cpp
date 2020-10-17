#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    s.push_back(s.front());

    unsigned f = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != '-')
            f |= 1 << (s[i] == '>');

        if (s[i] == '-' || s[i+1] == '-')
            ++k;
    }

    answer(f == 3 ? k : n);
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

