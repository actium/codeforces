#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> a(k - 3, 1);
    n -= k - 3;

    switch (n % 4) {
        case 0:
            a.push_back(n / 2);
            a.push_back(n / 4);
            a.push_back(n / 4);
            break;

        case 2:
            a.push_back(2);
            a.push_back(n / 2 - 1);
            a.push_back(n / 2 - 1);
            break;

        default:
            a.push_back(1);
            a.push_back(n / 2);
            a.push_back(n / 2);
            break;
    }

    answer(a);
}

void test_case()
{
    unsigned n, k;
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
