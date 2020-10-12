#include <iostream>
#include <vector>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> f;
    for (unsigned i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            f.push_back(i);
            n /= i;
        }
    }

    if (n != 1)
        f.push_back(n);

    if (f.size() < k)
        return no_answer();

    while (f.size() > k) {
        f[0] *= f.back();
        f.pop_back();
    }

    answer(f);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

