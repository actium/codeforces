#include <iostream>
#include <vector>

unsigned query(unsigned l, unsigned r)
{
    std::cout << "? " << l << ' ' << r << std::endl;

    unsigned x;
    std::cin >> x;
    return x;
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
    const unsigned x1 = query(1, 2);
    const unsigned x2 = query(2, 3);
    const unsigned x3 = query(1, 3);

    std::vector<unsigned> a(n);
    a[0] = x3 - x2;
    a[1] = x1 - a[0];
    a[2] = x2 - a[1];
    for (size_t i = 3; i < n; ++i)
        a[i] = query(i, i+1) - a[i-1];

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}
