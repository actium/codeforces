#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    size_t target = n, count = 0;
    unsigned target_t;
    for (size_t i = 0; i < n; ++i) {
        unsigned t;
        std::cin >> t;

        if (target == n || t < target_t) {
            target = i + 1;
            target_t = t;
            count = 0;
        }
        if (t == target_t)
            ++count;
    }

    if (count == 1)
        std::cout << target << '\n';
    else
        std::cout << "Still Rozdil\n";

    return 0;
}

