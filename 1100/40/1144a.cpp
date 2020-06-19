#include <algorithm>
#include <iostream>
#include <set>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    if (std::set<char>(s.cbegin(), s.cend()).size() != n)
        return answer(false);

    answer(*std::max_element(s.cbegin(), s.cend()) - *std::min_element(s.cbegin(), s.cend()) + 1 == n);
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

