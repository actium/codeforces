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

void solve(unsigned n)
{
    std::vector<unsigned> a;
    while (n != 0) {
        a.push_back(0);
        for (unsigned x = n, p = 1; x != 0; x /= 10, p *= 10) {
            if (x % 10 != 0) {
                a.back() += p;
                n -= p;
            }
        }
    }

    answer(a);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
