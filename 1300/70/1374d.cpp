#include <iostream>
#include <map>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void test_case()
{
    size_t n;
    unsigned k;
    std::cin >> n >> k;

    std::map<unsigned, size_t> f;
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        const unsigned r = a % k;
        if (r != 0)
            ++f[r];
    }

    unsigned long long x = 0;
    for (const auto& e : f) {
        x = std::max(x, (e.second - 1ull) * k + (k - e.first) + 1);
    }

    answer(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

