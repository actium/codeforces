#include <iostream>
#include <string>

void answer(const std::string& x, const std::string& y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::string& x)
{
    const size_t n = x.length();

    std::string a(n, '0'), b(x);
    for (size_t i = 0; i < n; ++i) {
        if (x[i] == '1') {
            a[i] = '1', b[i] = '0';
            break;
        }

        a[i] = b[i] = (x[i] + '0') / 2;
    }

    answer(a, b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string x;
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

