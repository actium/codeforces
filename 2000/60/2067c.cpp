#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    using integer = unsigned long long;

    unsigned k = (n % 10 + 3) % 10;
    for (integer b = 9; b < 10ull * n; b = b * 10 + 9) {
        unsigned c = 0;
        for (integer v = n; std::to_string(v).find('7') == std::string::npos; v += b)
            ++c;

        k = std::min(k, c);
    }

    answer(k);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
