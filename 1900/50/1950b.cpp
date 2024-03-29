#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(size_t n)
{
    std::vector<std::string> b;
    for (size_t i = 0; i < n; ++i) {
        std::string r;
        for (size_t j = 0; j < n; ++j)
            r.append((i + j) % 2 == 0 ? "##" : "..");

        b.push_back(r);
        b.push_back(r);
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
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
