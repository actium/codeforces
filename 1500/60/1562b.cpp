#include <iostream>
#include <string>

void answer(char x)
{
    std::cout << 1 << '\n';
    std::cout << x << '\n';
}

void answer(char x, char y)
{
    std::cout << 2 << '\n';
    std::cout << x << y << '\n';
}

void solve(const std::string& n)
{
    const size_t k = n.length();

    const size_t x = n.find_first_of("14689");
    if (x != std::string::npos)
        return answer(n[x]);

    for (size_t i = 0; i < k; ++i) {
        for (size_t j = 0; j < i; ++j) {
            const unsigned x = (n[j] - '0') * 10 + (n[i] - '0');
            if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
                return answer(n[j], n[i]);
        }
    }
}

void test_case()
{
    size_t k;
    std::cin >> k;

    std::string n;
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
