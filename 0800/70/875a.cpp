#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    const auto check = [n](unsigned x) {
        for (unsigned q = x; q != 0; q /= 10)
            x += q % 10;

        return x == n;
    };

    std::vector<unsigned> a;
    for (unsigned x = n - std::min<unsigned>(n, 9 * 9); x <= n; ++x) {
        if (check(x))
            a.push_back(x);
    }

    answer(a);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

