#include <iostream>
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
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const auto simulate = [&](size_t x) {
        while (a[x] != 0) {
            const size_t y = (x + 1) % n;
            a[y] -= std::min(a[y], a[x]);
            x = y;
        }
        return x;
    };

    const auto damage = [](unsigned u, unsigned v) {
        const unsigned k = u / v;
        return (2 * u - (k + 1ull) * v) * k / 2;
    };

    const size_t x = simulate(0);

    std::vector<std::pair<size_t, size_t>> q;
    q.emplace_back(x + 1, x + n);
    while (!q.empty()) {
        size_t b = q[0].first % n, e = q[0].second % n;
        while (b != e && a[b] == 0)
            b = (b + 1) % n;

        unsigned k = (n + e - b) % n;
        while (k > 3) {
            const size_t x = simulate(b);
            if (x != e) {
                q.emplace_back(x + 1, e);
                e = x;
                k = (n + e - b) % n;
            }
        }

        if (k == 3 && damage(a[(b+1)%n], a[b]) >= a[(b+2)%n])
            a[(b+2)%n] = 0;

        if (k > 1)
            a[(b+1)%n] = 0;

        q[0] = q.back();
        q.pop_back();
    }

    std::vector<unsigned> p;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != 0)
            p.push_back(i + 1);
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
