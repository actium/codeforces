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

void solve(unsigned m, unsigned l, std::vector<unsigned>& a)
{
    const unsigned n = a.size();
    a.push_back(l);

    std::multiset<unsigned> q;
    for (unsigned i = 0, k = std::min(n + 1, m); i < k; ++i)
        q.insert(0);

    for (unsigned i = 0, t = 0; i <= n; t = a[i++]) {
        for (unsigned dt = a[i] - t; dt != 0; --dt) {
            q.insert(*q.begin() + 1);
            q.erase(q.begin());
        }

        if (i < n) {
            q.erase(std::prev(q.end()));
            if (q.size() < n - i)
                q.insert(0);
        }
    }

    answer(q.empty() ? 0 : *q.rbegin());
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m, l;
    std::cin >> m >> l;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(m, l, a);
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
