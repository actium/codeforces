#include <iostream>
#include <map>
#include <vector>

constexpr unsigned M = 1'000'000'007;

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

void solve(const std::vector<int>& a)
{
    std::map<int, unsigned> c[2];

    const auto count = [&](size_t p, int x) {
        const auto it = c[p].find(x);
        return it != c[p].end() ? it->second : 0;
    };

    const auto update = [&](size_t p, int x, unsigned d) {
        if (d != 0)
            c[p][x] = (c[p][x] + d) % M;
    };

    c[0][0] = 1;
    for (const int x : a) {
        const unsigned t[3] = { c[0][0], c[1][0], c[1][-1] };

        update(0, 0, count(1, x));
        update(1, 0, count(0, -x));

        if (x != -1) {
            update(1, -1, count(0, -1-x));
            update(0, -1 - x, t[2]);
        }

        update(0, -x, t[1]);
        update(1, x, t[0]);
    }

    answer((count(0, 0) + count(1, 0)) % M);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
