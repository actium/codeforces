#include <algorithm>
#include <iostream>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

int main()
{
    std::string s;
    std::cin >> s;

    size_t m;
    std::cin >> m;

    for (size_t i = 0; i < m; ++i) {
        unsigned l, r, k;
        std::cin >> l >> r >> k;

        const size_t c = r - l + 1, d = k % c;
        std::rotate(s.begin() + l - 1, s.begin() + r - d, s.begin() + r);
    }

    answer(s);

    return 0;
}

