#include <iostream>
#include <string>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::string& y)
{
    unsigned s = 0, z = 0, e = 0;
    for (const char c : y) {
        const unsigned d = c - '0';
        s += d;
        z += (d == 0);
        e += (d % 2 == 0);
    }

    answer(z == 0 || s % 3 != 0 || e < 2 ? "cyan" : "red");
}

void test_case()
{
    std::string y;
    std::cin >> y;

    solve(y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

