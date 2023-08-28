#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& x)
{
    size_t n = x.length();

    size_t p = n;
    for (size_t i = n - 1; i > 0; --i) {
        if (x[i] - '0' > 4) {
            ++x[i-1];
            p = i;
        }
    }

    if (x[0] > '4') {
        x = '1' + x;
        p = 1;
        ++n;
    }

    for (size_t i = p; i < n; ++i)
        x[i] = '0';

    answer(x);
}

void test_case()
{
    std::string x;
    std::cin >> x;

    solve(x);
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
