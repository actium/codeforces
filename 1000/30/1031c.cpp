#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }

    std::cout << '\n';
}

void solve(unsigned a, unsigned b)
{
    unsigned d = 0;
    while ((d + 1) * d / 2 <= a + b)
        ++d;

    std::vector<unsigned> p[2];
    for (unsigned t = 0; --d != 0; ) {
        if (t + d <= a) {
            p[0].push_back(d);
            t += d;
        } else {
            p[1].push_back(d);
        }
    }

    answer(p[0]);
    answer(p[1]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
