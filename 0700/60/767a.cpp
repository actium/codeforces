#include <bitset>
#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    std::bitset<100000> v;
    size_t ub = n, lb = n;
    for (size_t i = 0; i < n; ++i) {
        size_t s;
        std::cin >> s;
        v.set(s-1);

        const char* separator = "";
        while (ub >= lb && v.test(ub-1)) {
            std::cout << separator << ub--;
            separator = " ";
        }
        std::cout << '\n';

        --lb;
    }

    return 0;
}

