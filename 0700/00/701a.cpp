#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, size_t>> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i+1;
    }

    std::sort(a.begin(), a.end());

    for (size_t i = 0; i < n/2; ++i)
        std::cout << a[i].second << ' ' << a[n-1 - i].second << '\n';

    return 0;
}

