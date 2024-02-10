#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k = 0;

    std::vector<unsigned> p;
    for (unsigned i = 0, x = 1; i < 2 * n; ++i) {
        std::string c;
        std::cin >> c;

        if (c == "add") {
            unsigned u;
            std::cin >> u;

            p.push_back(u);
        } else {
            if (!p.empty() && p.back() != x) {
                p.clear();
                ++k;
            }

            if (!p.empty())
                p.pop_back();

            ++x;
        }
    }

    answer(k);

    return 0;
}
