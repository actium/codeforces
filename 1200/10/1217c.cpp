#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0, z = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++z;
            continue;
        }

        unsigned v = 0;
        for (size_t j = i; j < n; ++j) {
            v = v << 1 | (s[j] - '0');
            if (v > z + j - i + 1)
                break;

            ++k;
        }

        z = 0;
    }

    answer(k);
}

void test_case()
{
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
