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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<integer>& p, integer k)
{
    const size_t m = p.size();

    unsigned q = 0;

    integer ub = k + 1;
    for (size_t i = 0; i < m; ) {
        if (p[i] >= ub) {
            const integer d = (p[i] - ub) / k + 1;
            ub += d * k;
        }

        for (const integer r = ub; i < m && p[i] < r; ++i)
            ++ub;

        ++q;
    }

    answer(q);
}

int main()
{
    integer n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    integer k;
    std::cin >> k;

    std::vector<integer> p(m);
    std::cin >> p;

    solve(p, k);

    return 0;
}
