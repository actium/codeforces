#include <algorithm>
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

void solve(const std::vector<unsigned>& h, unsigned a, unsigned b, unsigned k)
{
    const size_t n = h.size();

    std::vector<unsigned> q(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned d = h[i] % (a + b);
        if (d == 0)
            d = a + b;

        q[i] = (d - 1) / a;
    }

    std::sort(q.begin(), q.end());

    unsigned c = 0, s = q[0];
    while (c < n && s <= k)
        s += q[++c];

    answer(c);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    unsigned a, b, k;
    std::cin >> a >> b >> k;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h, a, b, k);

    return 0;
}
