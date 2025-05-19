#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = i + 1; j < 10; ++j) {
            if (s[j] >= '9' - i && s[j] < s[i])
                std::swap(s[i], s[j]);
        }
    }

    answer(s);
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
