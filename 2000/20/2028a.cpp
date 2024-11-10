#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, unsigned a, unsigned b)
{
    const size_t n = s.length();

    unsigned r = 0, c = 0;
    for (size_t i = 0; i < 123; ++i) {
        if (r == b && c == a)
            return answer(true);

        switch (s[i % n]) {
            case 'N': ++r; break;
            case 'E': ++c; break;
            case 'S': --r; break;
            case 'W': --c; break;
        }
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    solve(s, a, b);
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
