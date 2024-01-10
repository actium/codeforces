#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned d, const std::vector<unsigned>& s)
{
    const size_t m = s.size();

    const auto count = [d](unsigned x1, unsigned x2) {
        return x2 > x1 ? (x2 - x1 - 1) / d : 0;
    };

    unsigned k = 1;
    if (s[0] > 1)
        k += count(1, s[0]) + 1;
    for (size_t i = 1; i < m; ++i)
        k += count(s[i-1], s[i]) + 1;
    k += count(s[m-1], n + 1);

    unsigned q = 0;
    if (s[0] > 1)
        q += (count(1, s[0]) + 1 + count(s[0], s[1]) > count(1, s[1]));
    for (size_t i = 1; i + 1 < m; ++i)
        q += (count(s[i-1], s[i]) + 1 + count(s[i], s[i+1]) > count(s[i-1], s[i+1]));
    q += (count(s[m-2], s[m-1]) + 1 + count(s[m-1], n + 1) > count(s[m-2], n + 1));

    q == 0 ? answer(k, m) : answer(k - 1, q);
}

void test_case()
{
    unsigned n, m, d;
    std::cin >> n >> m >> d;

    std::vector<unsigned> s(m);
    std::cin >> s;

    solve(n, d, s);
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
