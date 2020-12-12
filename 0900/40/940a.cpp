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

void solve(const std::vector<unsigned>& x, unsigned d)
{
    unsigned f[100] = {};
    for (const unsigned q : x)
        ++f[q-1];

    unsigned c = 0;
    for (size_t i = d+1; i < 100; ++i)
        c += f[i];

    unsigned k = c;
    for (size_t i = d+1; i < 100; ++i) {
        c += f[i-d-1] - f[i];
        k = std::min(k, c);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, d);

    return 0;
}

