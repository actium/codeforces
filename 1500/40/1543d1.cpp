#include <iostream>

void solve(unsigned, unsigned)
{
    const auto query = [](unsigned y) {
        std::cout << y << std::endl;

        unsigned r;
        std::cin >> r;
        return r;
    };

    for (unsigned x = 0, q = 0; query(x^q) != 1; x = q++);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
