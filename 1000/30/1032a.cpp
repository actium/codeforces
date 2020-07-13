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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    unsigned f[100] = {};
    for (const unsigned x : a)
        ++f[x-1];

    const unsigned m = *std::max_element(std::begin(f), std::end(f));
    const unsigned z = (m + k - 1) / k;

    unsigned c = 0;
    for (const unsigned x : f) {
        if (x != 0)
            c += z * k - x;
    }

    answer(c);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

