#include <iostream>
#include <queue>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

struct State {
    unsigned t;
    size_t r;
    size_t c;
};

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<unsigned> t(n, oo);

    std::vector<std::vector<unsigned>> d(n, std::vector<unsigned>(m, oo));
    std::queue<State> q;

    const auto enqueue = [&](unsigned t, size_t r, size_t c) {
        if (a[r % n][c] == 0 && t < d[r % n][c]) {
            d[r % n][c] = t;
            q.push({ t, r, c });
        }
    };

    enqueue(0, 0, 0);
    while (!q.empty()) {
        const State p = q.front();
        q.pop();

        if (p.c + 1 == m) {
            t[(n + p.r - p.t) % n] = p.t;
            continue;
        }

        enqueue(p.t + 1, p.r + 1, p.c + 1);

        if (a[(p.r + 1) % n][p.c] == 0)
            enqueue(p.t + 1, p.r + 2, p.c);
    }

    unsigned x = oo;
    for (size_t i = 0; i < n; ++i) {
        if (t[i] == oo)
            continue;

        x = std::min<unsigned>(x, t[i] + n - 1 - i);
        x = std::min<unsigned>(x, t[i] + i + 1);
    }

    answer(x);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
