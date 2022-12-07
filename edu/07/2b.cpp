#include <iostream>
#include <utility>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<unsigned> roots(n);
    for (size_t i = 0; i < n; ++i)
        roots[i] = i;

    const auto resolve = [&](size_t x) {
        unsigned root = x;
        while (root != roots[root])
            root = roots[root];

        while (roots[x] != root)
            x = std::exchange(roots[x], root);

        return root;
    };

    std::vector<unsigned> q(n);
    for (size_t i = 0; i < n; ++i) {
        q[i] = resolve(p[i] - 1);
        roots[q[i]] = (q[i] + 1) % n;
    }

    answer(q);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
