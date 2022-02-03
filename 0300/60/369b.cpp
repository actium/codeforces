#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, unsigned k, unsigned sn, unsigned sk)
{
    const unsigned q = n - k, sq = sn - sk;

    std::vector<unsigned> s(n);

    for (size_t i = 0; i < k; ++i)
        s[i] = sk / k + (i < sk % k);

    for (size_t i = 0; i < q; ++i)
        s[k + i] = sq / q + (i < sq % q);

    answer(s);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    unsigned l, r;
    std::cin >> l >> r;

    unsigned sn, sk;
    std::cin >> sn >> sk;

    solve(n, k, sn, sk);

    return 0;
}
