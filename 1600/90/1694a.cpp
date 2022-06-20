#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    std::string s;
    while (a != 0 || b != 0) {
        if (a > 0) {
            s.push_back('0');
            --a;
        }
        if (b > 0) {
            s.push_back('1');
            --b;
        }
    }

    answer(s);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
