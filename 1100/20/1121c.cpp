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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> s(n), d(151 * n);
    {
        std::priority_queue<unsigned, std::vector<unsigned>, std::greater<unsigned>> q;
        for (size_t i = 0, t = 0, m = 0; i < n || !q.empty(); ) {
            if (q.size() == k || i == n) {
                t = q.top();
                q.pop();
                d[t] = 100.0 * ++m / n + 0.5;
            }

            if (i < n) {
                s[i] = t;
                q.push(t + a[i++]);
            }
        }

        for (size_t i = 1; i < d.size(); ++i)
            d[i] = std::max(d[i], d[i-1]);
    }

    const auto check = [&](size_t x) {
        for (unsigned i = 0; i < a[x]; ++i) {
            if (d[s[x]+i] == i + 1)
                return 1;
        }
        return 0;
    };

    unsigned c = 0;
    for (size_t i = 0; i < n; ++i)
        c += check(i);

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
