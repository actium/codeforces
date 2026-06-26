#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& z, unsigned k)
{
    const size_t n = s.size();

    integer b[3] = {};
    for (size_t i = 0; i < n; ++i) {
        b[0] += (s[i] == '1');
        b[1] += (s[i] ^ z[i]);
        b[2] += (z[i] == '1');
    }

    const integer x = ((1 << k) + 2) / 3, d = (k % 2 == 0 ? b[1] * (n - b[1]) : 0);

    answer(x * (b[0] * (n - b[0]) + b[1] * (n - b[1]) + b[2] * (n - b[2])) - d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::string s, z;
    std::cin >> s >> z;

    solve(s, z, k);
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
