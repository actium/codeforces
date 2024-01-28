#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(size_t n, size_t k)
{
    std::string s;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j)
            s.push_back('a' + j);
    }

    answer(s);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);
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
