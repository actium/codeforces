#include <iostream>
#include <vector>

unsigned ask(unsigned x, unsigned y)
{
    std::cout << "? " << 1+x << ' ' << 1+y << std::endl;

    unsigned k;
    std::cin >> k;

    return k;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "! ";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << std::endl;
}

void solve(unsigned n)
{
    std::vector<unsigned> p(n);

    size_t i = 0;
    for (size_t j = 1; j < n; ++j) {
        const unsigned k1 = ask(i, j);
        const unsigned k2 = ask(j, i);
        if (k1 > k2) {
            p[i] = k1;
            i = j;
        } else {
            p[j] = k2;
        }
    }
    p[i] = n;

    answer(p);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

