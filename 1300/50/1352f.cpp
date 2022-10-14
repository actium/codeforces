#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned n0, unsigned n1, unsigned n2)
{
    std::string s;
    {
        s.append(n0, '0');

        for (unsigned i = 0; i < n1; i += 2)
            s.append("01");

        s.append(n2, '1');

        if (n1 != 0) {
            s.append(n1 % 2 == 0, '0');
        } else {
            s.append(n0 != 0, '0');
            s.append(n2 != 0, '1');
        }
    }

    answer(s);
}

void test_case()
{
    unsigned n0, n1, n2;
    std::cin >> n0 >> n1 >> n2;

    solve(n0, n1, n2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
