#include <iostream>
#include <string>

void answer(size_t v)
{
    constexpr const char* s[3] = { "EQUAL", "BLUE", "RED" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& r, const std::string& b)
{
    const size_t n = r.length();

    unsigned kr = 0, kb = 0;
    for (size_t i = 0; i < n; ++i) {
        kr += (r[i] > b[i]);
        kb += (b[i] > r[i]);
    }

    answer((kr != kb) + (kr > kb));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string r, b;
    std::cin >> r >> b;

    solve(r, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

