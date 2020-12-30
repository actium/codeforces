#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& w, const std::vector<unsigned>& d)
{
    const size_t n = w.size();

    std::vector<unsigned> x;
    for (size_t i = 0; i < n; ++i)
        x.insert(x.end(), d[i] - 1, w[i]);

    std::sort(x.begin(), x.end());

    std::vector<integer> r(n-1);
    r[0] = std::accumulate(w.cbegin(), w.cend(), 0ull);
    for (unsigned k = 2; k < n; ++k) {
        r[k-1] = r[k-2];

        if (!x.empty()) {
            r[k-1] += x.back();
            x.pop_back();
        }
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> w(n);
    std::cin >> w;

    std::vector<unsigned> d(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        ++d[u-1], ++d[v-1];
    }

    solve(w, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

