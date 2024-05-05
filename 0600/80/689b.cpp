#include <iostream>
#include <queue>
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
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> d(n, ~0u);
    std::queue<size_t> q;

    const auto enqueue = [&](size_t u, unsigned v) {
        if (u < n && v < d[u]) {
            d[u] = v;
            q.emplace(u);
        }
    };

    enqueue(0, 0);
    while (!q.empty()) {
        const size_t p = q.front();
        q.pop();

        enqueue(p - 1, d[p] + 1);
        enqueue(p + 1, d[p] + 1);
        enqueue(a[p] - 1, d[p] + 1);
    }

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
