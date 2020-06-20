#include <algorithm>
#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<size_t>& a, size_t total)
{
    std::sort(a.begin(), a.end());

    size_t count = 0;
    for (size_t s = 0; s <= total; ) {
        total -= a.back(), s += a.back();
        a.pop_back();
        ++count;
    }

    answer(count);
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t total = 0;

    std::vector<size_t> v(n);
    for (size_t& a : v) {
        std::cin >> a;
        total += a;
    }

    solve(v, total);

    return 0;
}

