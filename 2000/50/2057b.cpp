#include <algorithm>
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

void solve(std::vector<unsigned>& a, unsigned k)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    std::sort(a.begin(), a.end(), [&](unsigned lhs, unsigned rhs) {
        return f[lhs] != f[rhs] ? f[lhs] > f[rhs] : lhs < rhs;
    });

    for (unsigned i = 0; i < k && a.back() != a.front(); ++i) {
        --f[a.back()];
        ++f[a.front()];
        a.pop_back();
    }

    unsigned q = 0;
    for (const auto& e : f)
        q += (e.second != 0);

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

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
