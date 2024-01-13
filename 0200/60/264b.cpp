#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

std::vector<unsigned> factorize(unsigned x)
{
    std::vector<unsigned> factors;
    for (unsigned i = 2; i * i <= x; ++i) {
        if (x % i != 0)
            continue;

        while (x % i == 0)
            x /= i;

        factors.push_back(i);
    }
    if (x != 1)
        factors.push_back(x);

    return factors;
}

void solve(const std::vector<unsigned>& a)
{
    unsigned c[100001] = {}, q = 0;
    for (const unsigned x : a) {
        const std::vector<unsigned> factors = factorize(x);

        unsigned k = 1;
        for (const unsigned f : factors)
            k = std::max(k, c[f] + 1);

        for (const unsigned f : factors)
            c[f] = k;

        q = std::max(q, k);
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
