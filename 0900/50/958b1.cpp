#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<size_t>>& a)
{
    unsigned k = 0;
    for (const auto& e : a) {
        if (e.size() == 1)
            ++k;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> a(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        a[u-1].push_back(v-1);
        a[v-1].push_back(u-1);
    }

    solve(a);

    return 0;
}

