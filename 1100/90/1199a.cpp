#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << 1 + v << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned x, unsigned y)
{
    const size_t n = a.size();

    size_t d = 0;
    while (d < n && a[d] != *std::min_element(a.begin() + (x+1 < d ? d-x-1 : d), a.begin() + (d+y+1 < n ? d+y+1 : n)))
        ++d;

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x, y);

    return 0;
}

