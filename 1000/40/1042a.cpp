#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned m)
{
    const unsigned n = a.size();

    unsigned k = 0, s = 0;
    for (const unsigned x : a) {
        k = std::max(k, x);
        s += x;
    }

    answer(std::max(k, (s + m + n - 1) / n), k + m);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}

