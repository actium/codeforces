#include <iostream>
#include <vector>

void answer(const std::vector<std::vector<unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::vector<unsigned>& a : v) {
        const char* separator = "";
        for (const unsigned x : a) {
            std::cout << separator << x;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(size_t n)
{
    std::vector<std::vector<unsigned>> v(n);
    for (size_t i = 0; i < n; ++i) {
        v[0].push_back(1 + i);
    }
    for (size_t i = 1; i < n; ++i) {
        v[i] = v[i-1];
        std::swap(v[i][i-1], v[i][i]);
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
