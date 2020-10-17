#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    std::string r;
    for (const char c : s) {
        if (c == 'A' || r.empty())
            r.push_back(c);
        else
            r.pop_back();
    }

    answer(r.length());
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

