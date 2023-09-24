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

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
}

void solve(const std::vector<integer>& a)
{
    integer s = 0;
    for (const integer x : a)
        s += x;

    std::vector<unsigned> p = { 0 };

    integer ps = 0;
    for (const integer q : a) {
        const unsigned lb = 100 * (ps + 1) / s, ub = 100 * (ps + q) / s;
        for (unsigned i = lb; i <= ub; ++i) {
            const integer x1 = (i * q + 99) / 100, x2 = ((i + 1) * q + 99) / 100 - 1;
            if (x1 <= x2 && 100 * (ps + x1) / s <= i && 100 * (ps + x2) / s >= i && i > p.back())
                p.push_back(i);
        }

        ps += q;
    }

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
