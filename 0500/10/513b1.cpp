#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, unsigned m)
{
    const auto f = [n](const std::vector<unsigned>& p) {
        unsigned s = 0;
        for (size_t i = 0; i < n; ++i) {
            unsigned x = p[i];
            for (size_t j = i; j < n; ++j) {
                x = std::min(x, p[j]);
                s += x;
            }
        }
        return s;
    };

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = 1 + i;

    std::vector<std::vector<unsigned>> q;
    unsigned x = 0;
    do {
        const unsigned y = f(p);
        if (y < x)
            continue;

        if (y > x) {
            q.clear();
            x = y;
        }

        q.push_back(p);
    } while (std::next_permutation(p.begin(), p.end()));

    std::sort(q.begin(), q.end());

    answer(q[m-1]);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
