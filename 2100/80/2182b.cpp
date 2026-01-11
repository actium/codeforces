#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(unsigned w, unsigned b)
{
    const auto check = [](unsigned& c, unsigned& r) {
        if ((1 << c) > r)
            return false;

        r -= 1 << c++;
        return true;
    };

    unsigned c = 0;
    while (check(c, w) && check(c, b));
    return c;
}

void solve(unsigned a, unsigned b)
{
    answer(std::max(count(a, b), count(b, a)));
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
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
