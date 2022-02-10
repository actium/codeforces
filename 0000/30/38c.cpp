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

void solve(const std::vector<unsigned>& a, unsigned l)
{
    unsigned s = 0;
    for (unsigned x = l; x <= 100; ++x) {
        unsigned k = 0;
        for (const unsigned q : a)
            k += q / x;

        s = std::max(s, k * x);
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned l;
    std::cin >> l;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, l);

    return 0;
}
