#include <algorithm>
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

void answer(integer v)
{
    std::cout << v << '\n';
}

integer count(const std::vector<unsigned>& a, unsigned c)
{
    integer k = 0, b = 1;
    for (const unsigned x : a) {
        k += x < b ? b - x : x - b;
        b *= c;
    }
    return k;
}

bool usable(unsigned c, unsigned n)
{
    for (integer x = 1; n-- > 0; x *= c) {
        if (x > 1e15)
            return false;
    }
    return true;
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    integer k = count(a, 1);
    for (unsigned c = 2; usable(c, n); ++c)
        k = std::min(k, count(a, c));

    answer(k);
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

