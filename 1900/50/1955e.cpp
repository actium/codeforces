#include <iostream>
#include <string>

bool check(std::string s, unsigned k)
{
    const size_t n = s.length();

    unsigned d = 0;
    for (size_t i = 0; i < n; ++i) {
        d ^= (i >= k && s[i-k] != '1');

        s[i] += d;
        if (s[i] == '1')
            continue;

        if (i + k > n)
            return false;

        d ^= 1;
    }

    return true;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned k = s.length();
    while (!check(s, k))
        --k;

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
