#include <iostream>
#include <string>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned x, unsigned y)
{
    std::cout << std::string(x, '4') << std::string(y, '7') << '\n';
}

void solve(unsigned n)
{
    for (unsigned l = 0, r = n / 7; 4 * l <= n; ) {
        const unsigned k = 4 * l + 7 * r;
        if (k == n)
            return answer(l, r);

        if (k < n)
            ++l;
        else
            --r;
    }

    no_answer();
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

