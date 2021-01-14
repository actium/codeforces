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

void solve(unsigned n, unsigned k, const std::vector<unsigned>& a)
{
    unsigned t = 0, p = 0;
    for (const unsigned x : a) {
        p += (x - t - 1) / k + 1;
        t = x;
    }

    answer(p + (n - t) / k);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    size_t c;
    std::cin >> c;

    std::vector<unsigned> a(c);
    std::cin >> a;

    solve(n, k, a);

    return 0;
}

