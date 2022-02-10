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

void solve(const std::vector<unsigned>& a, unsigned b)
{
    unsigned x = b, p = ~0u;
    for (const unsigned q : a) {
        p = std::min(p, q);
        x = std::max(x, b / p * q + b % p);
    }

    answer(x);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned b;
    std::cin >> b;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, b);

    return 0;
}
