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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned d = 360, s = 0;
    for (size_t i = 0, j = 0; i < n; ++i) {
        for (s += a[i]; s >= 180; s -= a[j++])
            d = std::min(d, 2 * s - 360);

        d = std::min(d, 360 - 2 * s);
    }

    answer(d);
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

