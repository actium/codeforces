#include <iostream>
#include <set>
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

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 1; j < n && a[i][n-j] == 1; ++j)
            ++c[i];
    }

    unsigned x = 0;
    {
        std::multiset<unsigned> s(c.begin(), c.end());
        while (!s.empty()) {
            if (*s.begin() >= x)
                ++x;

            s.erase(s.begin());
        }
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
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
