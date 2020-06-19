#include <iostream>
#include <string>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    if (s.back() == 'o')
        return answer("FILIPINO");

    if (s.back() == 'a')
        return answer("KOREAN");

    answer("JAPANESE");
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

