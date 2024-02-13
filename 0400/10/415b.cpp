#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& x, unsigned a, unsigned b)
{
    for (unsigned& q : x) {
        const auto u = 1ull * q * a / b;
        q -= (u * b + a - 1) / a;
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, a, b);

    return 0;
}
