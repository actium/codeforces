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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());
    a.push_back(0);

    integer k = 0;

    int h = a[0];
    for (size_t i = 0; i < n; ++i) {
        k += a[i] - h;
        h -= std::max<int>(h - a[i+1], 1);
        k += h;
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
