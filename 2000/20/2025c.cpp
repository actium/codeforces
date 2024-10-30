#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a, size_t k)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    const std::vector<std::pair<unsigned, unsigned>> b(f.begin(), f.end());

    unsigned c = 0, q = 0;
    for (size_t i = 0, j = 0; j < b.size(); ++j) {
        if (j != i && b[j].first - b[j-1].first > 1) {
            i = j;
            c = 0;
        }

        c += b[j].second;

        if (i + k <= j)
            c -= b[i++].second;

        q = std::max(q, c);
    }

    answer(q);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
