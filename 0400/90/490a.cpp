#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> t[3];
    for (size_t i = 1; i <= n; ++i) {
        size_t ti;
        std::cin >> ti;

        t[ti-1].push_back(i);
    }

    const size_t w = std::min({ t[0].size(), t[1].size(), t[2].size() });
    std::cout << w << '\n';

    for (size_t i = 0; i < w; ++i) {
        std::cout << t[0].back() << ' ' << t[1].back() << ' ' << t[2].back() << '\n';

        t[0].pop_back();
        t[1].pop_back();
        t[2].pop_back();
    }

    return 0;
}

