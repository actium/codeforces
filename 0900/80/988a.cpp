#include <iostream>
#include <unordered_map>

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::unordered_map<size_t, size_t> a;
    for (size_t i = 1; i <= n; ++i) {
        size_t x;
        std::cin >> x;

        a[x] = i;
    }

    if (a.size() >= k) {
        const char* separator = "YES\n";
        for (const auto& entry : a) {
            std::cout << separator << entry.second;
            separator = " ";

            if (--k == 0)
                break;
        }
        std::cout << '\n';
    } else {
        std::cout << "NO\n";
    }

    return 0;
}

