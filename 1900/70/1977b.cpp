#include <iostream>
#include <vector>

void answer(const std::vector<int>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned x)
{
    std::vector<int> v;
    for (size_t i = 0; x != 0; ++i) {
        if ((x & 1 << i) == 0) {
            v.push_back(0);
            continue;
        }

        x -= 1 << i;

        if (v.empty() || v.back() == 0) {
            v.push_back(1);
            continue;
        }

        if (v.back() == 1)
            x += 2 << i;

        v.back() = -v.back();
        v.push_back(0);
    }

    answer(v);
}

void test_case()
{
    unsigned x;
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
