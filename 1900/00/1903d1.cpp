#include <iostream>
#include <vector>

using integer = unsigned long long;

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

integer search(std::vector<integer> a, integer k)
{
    const auto count = [&](integer x) {
        const integer m = 2 * x - 1;

        integer q = 0;
        for (const integer v : a) {
            if ((v & x) != 0)
                continue;

            q += x - (v & m);
            if (q > k)
                break;
        }
        return q;
    };

    const auto update = [&](integer x) {
        const integer m = 2 * x - 1;

        for (integer& v : a) {
            if ((v & x) == 0)
                v += x - (v & m);
        }
    };

    integer x = 0;
    for (integer i = 1ull << 60; i != 0; i >>= 1) {
        const integer d = count(i);
        if (d <= k) {
            x |= i;
            k -= d;
            update(i);
        }
    }
    return x;
}

void solve(const std::vector<integer>& a, const std::vector<integer>& r)
{
    for (const integer q : r)
        answer(search(a, q));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    std::vector<integer> a(n), r(q);
    std::cin >> a >> r;

    solve(a, r);

    return 0;
}
