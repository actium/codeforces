#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& d, unsigned r)
{
    const size_t n = d.size();

    integer k = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        for ( ; d[j] - d[i] > r; ++i)
            k += n - j;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned r;
    std::cin >> r;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d, r);

    return 0;
}

