#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

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

void solve(const std::vector<unsigned>& b)
{
    const size_t n = b.size();
    if (n < 3)
        return answer(0);

    const auto count = [&](int x, int d) {
        unsigned k = (x != b[0]);
        for (size_t i = 1; i < n; ++i) {
            const int v = x + d - b[i];
            if (abs(v) > 1)
                return oo;

            k += abs(v);
            x += d;
        }
        return k;
    };

    unsigned k = oo;
    for (int d1 = -1; d1 <= 1; ++d1) {
        for (int d2 = -1; d2 <= 1; ++d2)
            k = std::min(k, count(b[0] + d1, b[1] - b[0] + d2 - d1));
    }

    k == oo ? no_answer() : answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}
