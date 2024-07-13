#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size();

    std::vector<unsigned> b(n);

    const auto update = [&](size_t x, unsigned v) {
        a[x] = v;
        b[(n+x)/2] = a[x&~1] | a[x|1];
        x = (n + x) / 2;

        for (unsigned p = 0; x != 1; p ^= 1) {
            x /= 2;
            b[x] = (p == 0 ? b[x<<1|0] ^ b[x<<1|1] : b[x<<1|0] | b[x<<1|1]);
        }
    };

    for (size_t i = 0; i < n; ++i)
        update(i, a[i]);

    for (const std::pair<unsigned, unsigned>& q : r) {
        update(q.first-1, q.second);
        answer(b[1]);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(1 << n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(a, r);

    return 0;
}
