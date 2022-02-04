#include <iostream>
#include <vector>

unsigned query(size_t x, size_t y)
{
    std::cout << "? " << 1+x << ' ' << 1+y << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "! ";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n)
{
    const unsigned x1 = query(0, 1);
    const unsigned x2 = query(1, 2);
    const unsigned x3 = query(2, 0);

    std::vector<unsigned> a(n);
    a[0] = (x1 + x3 - x2) / 2;
    a[1] = x1 - a[0];
    a[2] = x3 - a[0];
    for (size_t i = 3; i < n; ++i)
        a[i] = query(0, i) - a[0];

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}
