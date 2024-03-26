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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<long long> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + a[i];

    std::map<long long, unsigned> f;

    unsigned k = 0, q = 0;
    for (size_t i = n; i > 0; --i) {
        q = std::max(q, ++f[p[i]]);

        if (a[i-1] == 0) {
            k += q;
            f.clear();
            q = 0;
        }
    }

    answer(k + f[0]);
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
