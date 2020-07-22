#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.size();

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;

        p.push_back(i);
        p.push_back(0);
        p.push_back(i);
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

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

