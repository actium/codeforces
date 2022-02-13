#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned x, unsigned f)
{
    integer p = 0;
    for (const unsigned s : a) {
        if (s > x)
            p += (s + f - 1) / (x + f) * f;
    }

    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    unsigned x, f;
    std::cin >> x >> f;

    solve(a, x, f);

    return 0;
}
