#include <iostream>
#include <string>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    std::vector<char> p;
    for (const char c : s) {
        if (c == '(' || p.empty() || p.back() == ')')
            p.push_back(c);
        else 
            p.pop_back();
    }

    answer(p.size() / 2);
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

