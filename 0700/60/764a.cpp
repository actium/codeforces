#include <iostream>
#include <numeric>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t m, size_t z)
{
#if false
    size_t count = 0;
    for (size_t i = 1; i * n <= z; ++i) {
        if ((i * n) % m == 0)
            ++count;
    }
    answer(count);
#else
    answer(z / std::lcm(n, m));
#endif
}

int main()
{
    size_t n, m, z;
    std::cin >> n >> m >> z;

    solve(n, m, z);

    return 0;
}

