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

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    if (a.back() == 0) {
        std::cout << 1 << ' ' << a[0] << '\n';
        std::cout << 2 << ' ' << a[1] << ' ' << a[2] << '\n';
        std::cout << n-3;
        for (size_t i = 3; i < n; ++i)
            std::cout << ' ' << a[i];
    } else {
        std::cout << 1 << ' ' << a[0] << '\n';
        std::cout << 1 << ' ' << a[n-1] << '\n';
        std::cout << n-2;
        for (size_t i = 1; i < n-1; ++i)
            std::cout << ' ' << a[i];
    }
    std::cout << '\n';
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

