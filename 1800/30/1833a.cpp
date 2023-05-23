#include <iostream>
#include <set>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::set<std::string> w;
    for (size_t i = 1; i < n; ++i)
        w.insert(s.substr(i - 1, 2));

    answer(w.size());
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
