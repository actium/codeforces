#include <iostream>
#include <unordered_set>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::unordered_set<unsigned> z;
    for (size_t i = 0; i < n; ++i) {
        size_t x;
        std::cin >> x;

        for (size_t j = 0; j < x; ++j) {
            unsigned y;
            std::cin >> y;

            z.insert(y);
        }
    }

    answer(z.size() == m);

    return 0;
}

