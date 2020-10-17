#include <iostream>
#include <vector>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    if (n % 2 == 0)
        return no_answer();

    std::vector<unsigned> r(2 * n);
    for (unsigned i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            r[i] = i + 1;
            r[n+i] = r[i] + 1;
        } else {
            r[i] = 2*n - i + 1;
            r[n+i] = r[i] - 1;
        }
    }

    answer(r);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

