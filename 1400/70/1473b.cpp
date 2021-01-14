#include <iostream>
#include <numeric>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::string& s, std::string& t)
{
    const size_t k = std::lcm(s.length(), t.length());

    std::string p;
    while (p.length() < k)
        p += s;

    std::string q;
    while (q.length() < k)
        q += t;

    if (p == q)
        return answer(p);

    no_answer();
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

