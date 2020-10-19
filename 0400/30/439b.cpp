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

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& c, unsigned x)
{
    std::sort(c.begin(), c.end());

    unsigned long long k = 0;
    for (const unsigned a : c) {
        k += 1ull * a * x;
        x = std::max(x-1, 1u);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, x);

    return 0;
}

