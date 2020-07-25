#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long h)
{
    std::cout << h << '\n';
}

void solve(std::vector<unsigned>& a, unsigned m, unsigned k)
{
    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    const unsigned c = m / (k + 1);
    const unsigned r = m % (k + 1);

    answer(c * (1ull * a[0] * k + a[1]) + 1ull * r * a[0]);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, k);

    return 0;
}

