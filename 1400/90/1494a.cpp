#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a)
{
    const auto check = [&a](const char p[3]) {
        int b = 0;
        for (const char x : a) {
            b += (p[x-'A'] == '(' ? 1 : -1);

            if (b < 0)
                return false;
        }
        return b == 0;
    };

    for (const char* p : { "(()", "())", "()(", ")()", ")((", "))(" }) {
        if (check(p))
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    std::string a;
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

