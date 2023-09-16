#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string t1;
    t1.append(n, '(');
    t1.append(n, ')');

    if (t1.find(s) == std::string::npos)
        return answer(t1);

    std::string t2;
    for (size_t i = 0; i < n; ++i)
        t2.append("()");

    if (t2.find(s) == std::string::npos)
        return answer(t2);

    no_answer();
}

void test_case()
{
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
