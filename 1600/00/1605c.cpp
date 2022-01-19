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

void solve(std::string& s)
{
    for (const std::string& x : { "aa", "aba", "aca", "abca", "acba", "abbacca", "accabba" }) {
        if (s.find(x) != std::string::npos)
            return answer(x.length());
    }

    no_answer();
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
