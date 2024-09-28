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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(size_t n, size_t d, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    std::vector<unsigned> pa(1+n), pb(1+n);
    for (const std::pair<unsigned, unsigned>& q : s) {
        ++pa[q.first];
        ++pb[q.second];
    }

    for (size_t i = 1; i <= n; ++i) {
        pa[i] += pa[i-1];
        pb[i] += pb[i-1];
    }

    std::pair<unsigned, unsigned> u = { 0, 0 }, v = { ~0u, 0 };
    for (size_t i = d; i <= n; ++i) {
        const unsigned k = pa[i] - pb[i-d];
        if (k > u.first)
            u = { k, i-d+1 };
        if (k < v.first)
            v = { k, i-d+1 };
    }

    answer(u.second, v.second);
}

void test_case()
{
    size_t n, d, k;
    std::cin >> n >> d >> k;

    std::vector<std::pair<unsigned, unsigned>> s(k);
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
