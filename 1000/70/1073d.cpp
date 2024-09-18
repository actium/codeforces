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

void solve(const std::vector<unsigned>& a, integer t)
{
    unsigned x = ~0u;
    for (const unsigned q : a)
        x = std::min(x, q);

    integer k = 0;
    while (t >= x) {
        integer s = 0, c = 0;
        for (const unsigned q : a) {
            if (s + q <= t) {
                s += q;
                c += 1;
            }
        }

        k += t / s * c;
        t %= s;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    integer t;
    std::cin >> t;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, t);

    return 0;
}
