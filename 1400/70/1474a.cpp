#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& b)
{
    const size_t n = b.length();

    std::string a, d;
    for (size_t i = 0; i < n; ++i) {
        d.push_back(b[i] + 1);
        if (i > 0 && d[i] == d[i-1])
            --d[i];

        a.push_back('0' + d[i] - b[i]);
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string b;
    std::cin >> b;

    solve(b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

