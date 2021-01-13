#include <iostream>
#include <vector>

void answer(unsigned x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';

    std::cout << y.size();
    for (const unsigned q : y)
        std::cout << ' ' << q;

    std::cout << '\n';
}

void solve(unsigned n)
{
    const unsigned t = n * (n + 1) / 2;

    std::vector<unsigned> v;
    for (unsigned s = t / 2, i = n; i > 0; --i) {
        if (i <= s) {
            v.push_back(i);
            s -= i;
        }
    }

    answer(t % 2, v);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

