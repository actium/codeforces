#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& d)
{
    unsigned k = 0;
    for (const unsigned q : d)
        k += q * (q - 1) / 2;

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned a, b;
        std::cin >> a >> b;

        ++d[a-1], ++d[b-1];
    }

    solve(d);

    return 0;
}

