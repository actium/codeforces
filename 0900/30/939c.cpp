#include <iostream>
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

void solve(const std::vector<unsigned>& a, unsigned s, unsigned t)
{
    const size_t n = a.size();

    std::vector<unsigned> p(2 * n + 1);
    for (size_t i = 0; i < 2 * n; ++i)
        p[i+1] = p[i] + a[i % n];

    unsigned q = 0, x = ~0u;
    for (size_t i = 0; i < n; ++i) {
        const unsigned k = p[i+t-s] - p[i];
        if (k < q)
            continue;

        const unsigned j = (s > i ? s - i : n + s - i);
        if (k > q) {
            q = k;
            x = j;
        } else {
            x = std::min(x, j);
        }
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    unsigned s, t;
    std::cin >> s >> t;

    solve(a, s, t);

    return 0;
}
