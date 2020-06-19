#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        size_t l, r;
        std::cin >> l >> r;

        a[i] = r;
    }

    size_t k;
    std::cin >> k;

    const auto it = std::lower_bound(a.cbegin(), a.cend(), k);
    std::cout << std::distance(it, a.cend()) << '\n';

    return 0;
}

