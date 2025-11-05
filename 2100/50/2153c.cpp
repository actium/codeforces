#include <iostream>
#include <map>
#include <vector>

using integer = unsigned long long;

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

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    integer b = 0, c = 0;
    for (const auto& e : f) {
        const integer k = e.second / 2;
        b += k * 2 * e.first;
        c += k;
    }

    std::vector<unsigned> q;
    for (const auto& e : f) {
        if (e.second % 2 == 1)
            q.push_back(e.first);
    }

    if (c == 0 || q.empty())
        return answer(b);

    integer p = (c == 1 ? 0 : b);
    for (size_t i = 0; i < q.size(); ++i) {
        if (b > q[i])
            p = b + q[i];
    }
    for (size_t i = 1; i < q.size(); ++i) {
        if (q[i] < b + q[i-1])
            p = std::max(p, b + q[i-1] + q[i]);
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
