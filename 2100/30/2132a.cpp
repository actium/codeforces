#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& a, const std::string& b, const std::string& c)
{
    for (auto it = c.begin(), jt = b.begin(); it != c.end(); ++it, ++jt) {
        if (*it == 'D')
            a = a + *jt;
        else
            a = *jt + a;
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::string b;
    std::cin >> b;

    std::string c;
    std::cin >> c;

    solve(a, b, c);
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
