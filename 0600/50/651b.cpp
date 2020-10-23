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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned f[1001] = {};
    for (const unsigned x : a)
        ++f[x];

    unsigned p[1001] = {};
    for (unsigned x = 1; x <= 1000; ++x)
        p[x] = std::max(p[x-1], f[x]);

    unsigned k = 0;
    for (unsigned x = 1; x <= 1000; ++x)
        k += std::min(f[x], p[x-1]);

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

