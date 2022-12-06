#include <iostream>
#include <utility>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> roots(n);
    for (size_t i = 0; i < n; ++i)
        roots[i] = i;

    const auto resolve = [&](unsigned x) -> int {
        unsigned root = x;
        while (root != n && root != roots[root])
            root = roots[root];

        while (x != n && roots[x] != root)
            x = std::exchange(roots[x], root);

        return root == n ? -1 : 1 + root;
    };

    for (size_t i = 0; i < m; ++i) {
        char t;
        std::cin >> t;

        unsigned x;
        std::cin >> x;
        --x;

        if (t == '-')
            roots[x] = x + 1;
        else
            std::cout << resolve(x) << '\n';
    }

    return 0;
}
