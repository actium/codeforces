#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

using integer = unsigned long long;

void solve(const std::vector<integer>& a)
{
    integer g = a[0];
    for (const integer x : a)
        g = std::gcd(g, x);

    unsigned k = 0;
    for (integer x = 1; x * x <= g; ++x) {
        if (g % x == 0)
            k += 1 + (x * x != g);
    }

    answer(k);
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

