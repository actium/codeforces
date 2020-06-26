#include <iostream>
#include <vector>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned y, unsigned k, unsigned n)
{
    unsigned x = k - y % k;
    if (x + y > n)
        return answer(-1);

    std::vector<unsigned> v;
    while (x + y <= n) {
        v.push_back(x);
        x += k;
    }

    answer(v);
}

int main()
{
    unsigned y, k, n;
    std::cin >> y >> k >> n;

    solve(y, k, n);

    return 0;
}

