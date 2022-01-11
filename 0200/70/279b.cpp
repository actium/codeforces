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

void solve(const std::vector<unsigned>& a, unsigned t)
{
    const size_t n = a.size();

    unsigned s = 0, k = 0;
    for (size_t i = 0, j = 0; j < n; ) {
        for (s += a[j++]; s > t; s -= a[i++]);

        k = std::max<unsigned>(k, j - i);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned t;
    std::cin >> t;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, t);

    return 0;
}
