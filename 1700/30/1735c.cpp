#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& t)
{
    unsigned p[26], n[26];
    for (size_t i = 0; i < 26; ++i) {
        p[i] = i;
        n[i] = i;
    }

    const auto check = [&](size_t i, size_t j) {
        unsigned k = 0;
        while (i != j && p[i] != i) {
            i = p[i];
            ++k;
        }
        return i != j || k == 25;
    };

    std::string s;
    for (const char c : t) {
        const size_t x = c - 'a';
        if (p[x] == x) {
            size_t i = 0;
            while (n[i] != i || !check(i, x))
                ++i;

            p[x] = i;
            n[i] = x;
        }

        s.push_back('a' + p[x]);
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string t;
    std::cin >> t;

    solve(t);
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
