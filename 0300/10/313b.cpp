#include <iostream>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

int main()
{
    std::string s;
    std::cin >> s;

    const size_t n = s.length();

    std::vector<unsigned> p(n);
    for (size_t i = 1; i < n; ++i)
        p[i] = p[i-1] + (s[i-1] == s[i]);

    size_t m;
    std::cin >> m;

    for (size_t i = 0; i < m; ++i) {
        unsigned l, r;
        std::cin >> l >> r;

        answer(p[r-1] - p[l-1]);
    }

    return 0;
}

