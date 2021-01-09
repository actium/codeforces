#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::pair<unsigned, size_t>>& q)
{
    const size_t n = q.size();

    std::sort(q.begin(), q.end(), std::greater<std::pair<unsigned, size_t>>());

    integer s[2] = {};
    for (size_t i = 0; i < n; ++i) {
        const size_t x = i % 2;
        if (q[i].second == x)
            s[x] += q[i].first;
    }

    answer(s[0] - s[1]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, size_t>> q(2 * n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> q[i].first;
        q[i].second = 0;
    }
    for (size_t i = 0; i < n; ++i) {
        std::cin >> q[n+i].first;
        q[n+i].second = 1;
    }

    solve(q);

    return 0;
}

