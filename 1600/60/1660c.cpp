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

    unsigned k = 0;

    std::set<char> v;
    for (const char c : s) {
        if (v.count(c) == 0) {
            v.insert(c);
        } else {
            k += 2;
            v.clear();
        }
    }

    answer(n - k);
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
