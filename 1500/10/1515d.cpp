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

void solve(const std::vector<unsigned>& c, size_t l, size_t r)
{
    const size_t n = c.size();

    std::map<unsigned, unsigned> fl;
    for (size_t i = 0; i < l; ++i)
        ++fl[c[i]];

    std::map<unsigned, unsigned> fr;
    for (size_t i = l; i < n; ++i) {
        const auto it = fl.find(c[i]);
        if (it == fl.end() || it->second == 0) {
            ++fr[c[i]];
        } else {
            --it->second;
            --l;
            --r;
        }
    }

    if (l > r) {
        std::swap(fl, fr);
        std::swap(l, r);
    }

    unsigned k = 0;
    for (auto it = fr.begin(); it != fr.end() && r > l; ++it) {
        const unsigned q = std::min<unsigned>(it->second, r - l) / 2;
        r -= 2 * q;
        k += q;
    }

    answer(k + r);
}

void test_case()
{
    size_t n, l, r;
    std::cin >> n >> l >> r;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, l, r);
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
