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

void solve(unsigned h, const std::vector<unsigned>& a, const std::vector<unsigned>& c)
{
    const size_t n = a.size();

    std::set<std::pair<integer, size_t>> q;
    for (size_t i = 0; i < n; ++i)
        q.emplace(1, i);

    while (a[q.begin()->second] < h) {
        const std::pair<integer, size_t> p = *q.begin();
        q.erase(q.begin());
        h -= a[p.second];
        q.emplace(p.first + c[p.second], p.second);
    }

    answer(q.begin()->first);
}

void test_case()
{
    unsigned h;
    std::cin >> h;

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), c(n);
    std::cin >> a >> c;

    solve(h, a, c);
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
