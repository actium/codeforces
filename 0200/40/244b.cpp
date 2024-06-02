#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void search(integer x, unsigned a, unsigned b, unsigned n, std::vector<integer>& v)
{
    if (x == 0 || x > n)
        return;

    v.push_back(x);

    search(x * 10 + a, a, b, n, v);
    search(x * 10 + b, a, b, n, v);
}

void solve(unsigned n)
{
    std::vector<integer> v;
    for (unsigned a = 0; a <= 9; ++a) {
        for (unsigned b = 0; b < a; ++b) {
            search(integer(a), a, b, n, v);
            search(integer(b), a, b, n, v);
        }
    }

    std::sort(v.begin(), v.end());

    answer(std::unique(v.begin(), v.end()) - v.begin());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
