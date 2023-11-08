#include <iostream>
#include <string>

constexpr std::string_view t = "abacaba";

void answer(const std::string& x)
{
    std::cout << "Yes" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    const auto count = [&] {
        unsigned k = 0;
        for (size_t i = 0; i < n; ++i)
            k += (s.compare(i, 7, t) == 0);

        return k;
    };

    const auto check = [&](size_t x) {
        for (size_t i = 0; i < 7; ++i) {
            if (s[x+i] != t[i] && s[x+i] != '?')
                return false;
        }
        return true;
    };

    unsigned k = count();
    for (size_t i = 0; i < n && k == 0; ++i) {
        if (!check(i))
            continue;

        const std::string b = s;
        for (size_t j = 0; j < 7; ++j)
            s[i+j] = t[j];

        k = count();
        if (k != 1) {
            s = b;
            k = 0;
        }
    }

    if (k != 1)
        return no_answer();

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '?')
            s[i] = 'z';
    }
    answer(s);
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
