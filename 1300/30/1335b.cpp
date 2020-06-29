#include <iostream>
#include <string>

void answer(const std::string& s)
{
    std::cout << s << '\n';
}

void solve(size_t n, size_t a, size_t b)
{
    std::string s;
    for (size_t i = 0; i < n; ++i) {
        s.push_back('a' + i % b);
    }

    answer(s);
}

void test_case()
{
    size_t n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}


