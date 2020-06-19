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
    std::cout << v << '\n';
}

void solve(std::vector<size_t>& a, int m)
{
    const size_t n = a.size();

    std::sort(a.rbegin(), a.rend());

    size_t count = 0;
    for (size_t i = 0; i < n && m > 0; ++i) {
        m -= a[i];
        ++count;
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}

