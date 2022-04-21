#include <iostream>

void answer(unsigned x)
{
    std::cout << "Division " << x << '\n';
}

void solve(int r)
{
    if (r < 1400)
        return answer(4);

    if (r < 1600)
        return answer(3);

    if (r < 1900)
        return answer(2);

    answer(1);
}

void test_case()
{
    int r;
    std::cin >> r;

    solve(r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
