#include <iostream>
#include <string>

std::string s[63];

void initialize()
{
    for (size_t i = 0; i < 63; ++i)
        s[i] = std::to_string(1ull << i);
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& n)
{
    const auto test = [&](const std::string& q) -> unsigned {
        unsigned k = 0;
        for (auto i = n.cbegin(), j = q.cbegin(); i != n.cend() && j != q.cend(); ++i) {
            if (*i == *j) {
                ++k;
                ++j;
            }
        }

        return n.length() - k + q.length() - k;
    };

    unsigned x = ~0u;
    for (const std::string& q : s)
        x = std::min(x, test(q));

    answer(x);
}

void test_case()
{
    std::string n;
    std::cin >> n;

    solve(n);
}

int main()
{
    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
