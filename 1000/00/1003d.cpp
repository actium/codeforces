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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    unsigned f[32] = {};
    for (const unsigned x : a)
        ++f[__builtin_ctz(x)];

    for (unsigned x : b) {
        unsigned q = 0;
        for (unsigned i = 31; ~i != 0; --i) {
            const unsigned v = 1 << i, k = std::min(f[i], x / v);
            x -= v * k;
            q += k;
        }

        x == 0 ? answer(q) : no_answer();
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n), b(q);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
