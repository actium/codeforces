#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    std::string s;

    if (n % 3 == 1) {
        s.push_back('1');
        --n;
    }

    while (n > 2) {
        s.push_back('2');
        s.push_back('1');
        n -= 3;
    }

    if (n != 0)
        s.push_back('0' + n);

    answer(s);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
