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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned f[3] = {};
    for (const unsigned x : a)
        ++f[x-1];

    answer(std::min({ f[0] + f[1], f[0] + f[2], f[1] + f[2] }));
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

