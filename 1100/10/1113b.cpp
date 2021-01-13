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

void solve(std::vector<unsigned>& a)
{
    unsigned x = ~0u, s = 0;
    for (const unsigned q : a) {
        x = std::min(x, q);
        s += q;
    }

    unsigned d = 0;
    for (const unsigned q : a) {
        for (unsigned i = 2; i * i <= q; ++i) {
            if (q % i == 0)
                d = std::max<int>(d, (q - q / i) - (x * i - x));
        }
    }

    answer(s - d);
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

