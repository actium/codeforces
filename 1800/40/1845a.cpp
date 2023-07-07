#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k, unsigned x)
{
    if (x != 1)
        return answer(std::vector<unsigned>(n, 1));

    if (k > 1 && n % 2 == 0)
        return answer(std::vector<unsigned>(n / 2, 2));

    if (k > 2 && (n - 3) % 2 == 0) {
        std::vector<unsigned> v((n - 3) / 2, 2);
        v.push_back(3);
        return answer(v);
    }

    no_answer();
}

void test_case()
{
    unsigned n, k, x;
    std::cin >> n >> k >> x;

    solve(n, k, x);
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
