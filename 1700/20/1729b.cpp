#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& t)
{
    constexpr char b = 'a' - 1;

    const auto d = [](char c) {
        return c - '0';
    };

    std::string s;
    for (auto it = t.crbegin(); it != t.crend(); ++it) {
        if (*it == '0') {
            const unsigned c2 = d(*++it), c1 = d(*++it) * 10;
            s.push_back(b + c1 + c2);
        } else {
            s.push_back(b + d(*it));
        }
    }

    answer(std::string(s.crbegin(), s.crend()));
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
