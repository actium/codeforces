#include <iostream>
#include <vector>

unsigned query()
{
    unsigned a;
    std::cin >> a;
    return a;
}

void answer(const std::pair<size_t, size_t>& p, unsigned b)
{
    std::cout << b << ' ' << 1+p.first << ' ' << 1+p.second << std::endl;
}

void solve(size_t n)
{
    std::vector<std::pair<size_t, size_t>> q[2];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            q[(i+j)%2].emplace_back(i, j);
    }

    while (q[0].size() + q[1].size() != 0) {
        const unsigned a = query();

        if (a != 1 && !q[0].empty()) {
            answer(q[0].back(), 1);
            q[0].pop_back();
            continue;
        }
        if (a != 2 && !q[1].empty()) {
            answer(q[1].back(), 2);
            q[1].pop_back();
            continue;
        }

        if (q[0].empty()) {
            answer(q[1].back(), 3);
            q[1].pop_back();
        } else {
            answer(q[0].back(), 3);
            q[0].pop_back();
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}
