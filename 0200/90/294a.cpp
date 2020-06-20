#include <iostream>
#include <vector>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n+2);
    for (size_t i = 1; i <= n; ++i)
        std::cin >> a[i];

    size_t m;
    std::cin >> m;

    for (size_t i = 1; i <= m; ++i) {
        size_t x, y;
        std::cin >> x >> y;

        a[x-1] += y - 1;
        a[x+1] += a[x] - y;
        a[x] = 0;
    }

    for (size_t i = 1; i <= n; ++i)
        std::cout << a[i] << '\n';

    return 0;
}

