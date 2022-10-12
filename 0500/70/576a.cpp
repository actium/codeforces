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

bool check(unsigned x)
{
    unsigned k = 0;
    for (unsigned i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ++k;

            while (x % i == 0)
                x /= i;
        }
    }
    k += (x != 1);
    return k == 1;
}

void solve(unsigned n)
{
    std::vector<unsigned> v;
    for (unsigned i = 2; i <= n; ++i) {
        if (check(i))
            v.push_back(i);
    }

    answer(v);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
