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

void solve(const std::vector<unsigned>& m)
{
    const size_t n = m.size();

    unsigned s = 0;
    for (const unsigned x : m)
        s += x;

    const unsigned q = s / n;

    unsigned k = 0;
    for (const unsigned x : m) {
        if (x < q)
            k += q - x;
    }

    unsigned d = k, r = s % n;
    for (const unsigned x : m) {
        if (x > q) {
            const unsigned b = q + (r != 0), u = std::min(x - b, d);
            k += x - u - b;
            d -= u;
            r -= b - q;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> m(n);
    std::cin >> m;

    solve(m);

    return 0;
}