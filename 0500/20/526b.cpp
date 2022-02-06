#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t k = a.size();

    unsigned s = 0;
    for (size_t i = k - 1; i > 0; i -= 2) {
        const unsigned q = std::max(a[i-1], a[i]);
        s += (q - a[i-1]) + (q - a[i]);
        a[i/2-1] += q;
    }

    answer(s);
}

int main()
{
    unsigned n;
    std::cin >> n;

    std::vector<unsigned> a((1 << n + 1) - 1);
    for (size_t i = 1; i < a.size(); ++i)
        std::cin >> a[i];

    solve(a);

    return 0;
}
