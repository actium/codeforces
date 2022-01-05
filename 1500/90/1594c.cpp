#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    if (!v.empty()) {
        const char* separator = "";
        for (const unsigned x : v) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(const std::string& s, char c)
{
    const size_t n = s.length();

    std::vector<bool> f(1+n);
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == c)
            continue;

        const unsigned z = 1 + i;
        for (unsigned x = 1; x * x <= z; ++x) {
            if (z % x == 0) {
                f[0] = true;
                f[x] = true;
                f[z / x] = true;
            }
        }
    }

    if (!f[0])
        return answer({});

    for (unsigned x = 1; x <= n; ++x) {
        if (!f[x])
            return answer({ x });
    }

    answer({ n-1, n });
}

void test_case()
{
    size_t n;
    std::cin >> n;

    char c;
    std::cin >> c;

    std::string s;
    std::cin >> s;

    solve(s, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
