#include <iostream>

void answer(long long v)
{
    std::cout << v << '\n';
}

void solve(size_t a, size_t b, size_t c, size_t d)
{
    if (a <= b)
        return answer(b);

    if (c <= d)
        return answer(-1);

    const long long r = c - d;
    const long long k = (a - b + r - 1) / r;

    answer(b + k * c);
}

void test_case()
{
    size_t a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

