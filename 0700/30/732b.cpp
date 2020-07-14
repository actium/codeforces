#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, const std::vector<unsigned>& v)
{
    std::cout << x << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    unsigned c = 0;
    for (size_t i = 1; i < n; ++i) {
        const unsigned d = k - std::min(k, a[i-1] + a[i]);
        a[i] += d, c += d;
    }

    answer(c, a);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

