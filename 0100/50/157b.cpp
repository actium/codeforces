#include <algorithm>
#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(std::vector<unsigned>& r)
{
    const size_t n = r.size();

    std::sort(r.begin(), r.end(), std::greater<unsigned>());

    unsigned u = 0;
    for (size_t i = 0; i < n; ++i) {
        const unsigned v = r[i] * r[i];
        if (i % 2 == 0)
            u += v;
        else
            u -= v;
    }

    answer(M_PI * u);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}

