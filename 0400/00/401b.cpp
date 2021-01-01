#include <iostream>
#include <vector>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<bool>& v)
{
    const size_t x = v.size();

    unsigned k[2] = {};
    for (size_t i = 1, c = 0; i < x; ++i) {
        c = (v[i] ? 0 : c + 1);

        k[0] += c > 0;
        k[1] += c % 2;
    }

    answer(k[1], k[0]);
}

int main()
{
    unsigned x;
    std::cin >> x;

    size_t k;
    std::cin >> k;

    std::vector<bool> v(x);
    for (size_t i = 0; i < k; ++i) {
        unsigned t;
        std::cin >> t;

        if (t == 1) {
            unsigned a, b;
            std::cin >> a >> b;

            v[a] = v[b] = true;
        } else {
            unsigned a;
            std::cin >> a;

            v[a] = true;
        }
    }

    solve(v);

    return 0;
}

