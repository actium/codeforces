#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length();

    int d = 0;
    for (size_t i = 0; i < n-1; ++i) {
        d += (a[i] == '1' ? 1 : -1);

        if ((a[i] == b[i]) != (a[i+1] == b[i+1]) && d != 0)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    a.push_back('0');
    b.push_back('0');

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
