#include <iostream>
#include <vector>

using integer = unsigned long long;

integer powers[16];

void initialize()
{
    powers[0] = 1;
    for (size_t i = 1; i < 16; ++i)
        powers[i] = powers[i-1] * 10;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

integer count(integer x)
{
    integer k = 0, c = 1;
    while (powers[c] <= x)
        k += 9 * powers[c-1] * c++;

    return k + (x - powers[c-1] + 1) * c;
}

integer sum(integer x)
{
    if (x < 10)
        return x * (x + 1) / 2;

    integer c = 0;
    for (integer n = x; n > 9; n /= 10)
        ++c;

    std::vector<integer> a(1 + c);
    for (integer i = 1; i <= c; ++i)
        a[i] = a[i-1] * 10 + 45 * powers[i-1];

    const integer b = powers[c], msd = x / b;
    return msd * a[c] + msd * (msd - 1) / 2 * b + msd * (1 + x % b) + sum(x % b);
}

void solve(integer k)
{
    integer lb = 0, ub = k;
    while (ub - lb > 1) {
        const integer mid = (lb + ub) / 2;
        (count(mid) < k ? lb : ub) = mid;
    }

    integer s = sum(ub);
    for (unsigned d = count(ub) - k; d != 0; --d) {
        s -= ub % 10;
        ub /= 10;
    }

    answer(s);
}

void test_case()
{
    integer k;
    std::cin >> k;

    solve(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
