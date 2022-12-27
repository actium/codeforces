#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a)
{
    const size_t n = a.length();

    std::string b;
    for (size_t i = 1, k = 0; i < n; ++i) {
        if (a[i] == '1') {
            b.push_back("+-"[++k % 2]);
        } else {
            b.push_back('+');
        }
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

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
