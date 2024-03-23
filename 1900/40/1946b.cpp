#include <iostream>
#include <vector>

using integer = long long;

constexpr integer M = 1000000007;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

integer raise(integer b, integer p)
{
    integer v = 1;
    while (p != 0) {
        if (p % 2 == 1)
            v = v * b % M;

        b = b * b % M;
        p /= 2;
    }
    return v;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

integer max_subarray_sum(const std::vector<int>& a)
{
    integer gs = 0, ls = 0;
    for (const int x : a) {
        gs = std::max(gs, ls + x);
        ls = std::max(ls + x, 0LL);
    }
    return gs;
}

void solve(const std::vector<int>& a, unsigned k)
{
    const integer b = max_subarray_sum(a) % M;

    integer s = (b * raise(2, k) - b) % M;
    for (const int x : a)
        s += x;

    answer((M + s % M) % M);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);
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
