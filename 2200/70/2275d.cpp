#include <iostream>
#include <vector>

using integer = long long;

constexpr integer oo = ~0uLL >> 2;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

struct Triple {
    int a;
    int b;
    int c;
};

std::istream& operator >>(std::istream& input, Triple& t)
{
    return input >> t.a >> t.b >> t.c;
}

void solve(const std::vector<Triple>& t, integer k)
{
    const auto check = [&](integer x) {
        integer s = 0;
        for (auto [a, b, c] : t) {
            integer v = 0LL + a + b + c;
            if (v >= x)
                continue;

            if (a == b && b == c)
                return false;

            s += x - v;

            if (a <= b && b <= c) {
                const integer d = std::min(b - a, c - b) + 1;
                s += 2 * d;
            }

            if (s > k)
                return false;
        }
        return true;
    };

    integer lb = -oo, ub = oo;
    while (ub - lb > 1) {
        const auto mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::vector<Triple> t(n);
    std::cin >> t;

    solve(t, k);
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
