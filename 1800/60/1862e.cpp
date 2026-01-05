#include <iostream>
#include <set>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a, size_t m, unsigned d)
{
    const size_t n = a.size();

    integer p = 0, q = 0;
    {
        std::multiset<int> s;
        for (size_t i = 0; i < n; ++i) {
            if (a[i] < 0)
                continue;

            p += a[i];
            q = std::max<integer>(q, p - (i + 1LL) * d);

            s.insert(a[i]);
            if (s.size() >= m) {
                p -= *s.begin();
                s.erase(s.begin());
            }
        }
    }

    answer(q);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned d;
    std::cin >> d;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, m, d);
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
