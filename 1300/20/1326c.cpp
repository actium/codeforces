#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& p, size_t k)
{
    constexpr unsigned M = 998244353;

    const size_t n = p.size();

    integer s = 0, c = 0;
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (p[i] > n - k) {
            s += p[i];

            if (c == 0)
                c = 1;
            else
                c = (i - j) * c % M;

            j = i;
        }
    }

    answer(s, c);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p, k);

    return 0;
}

