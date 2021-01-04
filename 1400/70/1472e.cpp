#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<std::array<unsigned, 3>>& a)
{
    const size_t n = a.size();

    for (auto& p : a) {
        if (p[0] > p[1])
            std::swap(p[0], p[1]);
    }

    const auto c = [](const std::array<unsigned, 3>& a, const std::array<unsigned, 3>& b) {
        return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    };

    std::sort(a.begin(), a.end(), c);

    std::vector<int> p(n, -1);
    for (size_t i = 0, j = 1; j < n; ++j) {
        if (a[i][0] < a[j][0] && a[i][1] < a[j][1])
            p[a[j][2]] = 1 + a[i][2];

        if (a[j][1] < a[i][1])
            i = j;
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::array<unsigned, 3>> a(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned h, w;
        std::cin >> h >> w;

        a[i] = { h, w, i };
    }

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

