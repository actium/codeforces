#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    for (size_t i = 0; i < m; ++i) {
        size_t l, r;
        std::cin >> l >> r;

        char c1, c2;
        std::cin >> c1 >> c2;

        for (size_t i = l; i <= r; ++i) {
            if (s[i-1] == c1)
                s[i-1] = c2;
        }
    }

    answer(s);

    return 0;
}

