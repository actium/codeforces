#include <algorithm>
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

void solve(std::vector<int>& x, size_t m)
{
    const size_t n = x.size();

    std::sort(x.begin(), x.end(), std::greater<int>());

    unsigned f2 = 0;
    while (!x.empty() && x.back() == -2) {
        ++f2;
        x.pop_back();
    }

    unsigned f1 = 0;
    while (!x.empty() && x.back() == -1) {
        ++f1;
        x.pop_back();
    }

    x.erase(std::unique(x.begin(), x.end()), x.end());

    unsigned v = std::min(x.size() + std::max(f1, f2), m);
    for (size_t i = 0; i < x.size(); ++i) {
        const unsigned lc = std::min<unsigned>(x[i], x.size() - i + f1);
        const unsigned rc = std::min<unsigned>(m - x[i], i + f2);
        v = std::max(v, lc + rc);
    }

    answer(v);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> x(n);
    std::cin >> x;

    solve(x, m);
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
