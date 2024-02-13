#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& r, size_t k)
{
    const unsigned c = (k + 1) / 2;

    const auto distance = [=](unsigned x) {
        return x < c ? c - x : x - c;
    };

    std::vector<std::vector<bool>> a(1 + k, std::vector<bool>(1 + k));

    const auto check = [&](size_t r, unsigned q) {
        unsigned d = 0, x = 0, v = ~0u;
        for (size_t i = 1, j = 1; i <= k; ++i) {
            if (a[r][i]) {
                d = 0;
                j = i + 1;
                continue;
            }

            d += distance(r) + distance(i);

            if (i - j + 1 == q && d < v) {
                x = j;
                v = d;
            }

            if (i - j + 1 == q)
                d -= distance(r) + distance(j++);
        }
        return std::make_pair(v, x);
    };

    for (const unsigned q : r) {
        unsigned v = ~0u, x = 0, y = 0;
        for (unsigned i = 1; i <= k; ++i) {
            const auto s = check(i, q);
            if (s.first < v) {
                v = s.first;
                x = i;
                y = s.second;
            }
        }
        if (v == ~0u) {
            no_answer();
        } else {
            answer(x, y, y + q - 1);

            for (unsigned i = 0; i < q; ++i)
                a[x][y+i] = true;
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> r(n);
    std::cin >> r;

    solve(r, k);

    return 0;
}
