#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.size();

    std::vector<unsigned> pz(1+n);
    for (size_t i = 0; i < n; ++i)
        pz[i+1] = pz[i] + (s[i] == '0');

    if (s[0] == '1')
        return answer(pz[n]);

    unsigned k = n - pz[n];
    for (size_t i = 1; i < n; ++i) {
        const unsigned po = i - pz[i], sz = pz[n] - pz[i];
        k = std::min(k, po + sz);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
