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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> d(n-1);
    for (size_t i = 1; i < n; ++i)
        d[i-1] = a[i] - a[i-1];

    std::sort(d.begin(), d.end());

    unsigned k = 0;
    for (size_t i = 1; i < n && d[i-1] == d.front(); ++i)
        ++k;

    answer(d.front(), k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

