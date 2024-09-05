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

struct Solution {
    unsigned k;
    size_t begin;
    size_t end;
};

bool operator <(const Solution& lhs, const Solution& rhs)
{
    return lhs.k < rhs.k;
}

void answer(unsigned x, size_t y, size_t z)
{
    std::cout << x << ' ' << 1+y << ' ' << 1+z << '\n';
}

Solution search(const std::vector<size_t>& p)
{
    std::vector<int> a(1, 1);
    for (size_t i = 1; i < p.size(); ++i) {
        if (p[i] != p[i-1] + 1)
            a.push_back(p[i-1] - p[i] + 1);

        a.push_back(1);
    }

    Solution q = { 0, p[0], p[0] }, s = q;
    for (const int x : a) {
        q.end += std::abs(x);

        if (x > 0 || q.k >= -x) {
            q.k += x;
        } else {
            q.k = 0;
            q.begin = q.end;
        }

        s = std::max(s, q);
    }
    return s;
}

void solve(const std::vector<unsigned>& x)
{
    const size_t n = x.size();

    std::map<unsigned, std::vector<size_t>> p;
    for (size_t i = 0; i < n; ++i)
        p[x[i]].push_back(i);

    Solution s = { 1, 0, 1 };
    for (const auto& e : p)
        s = std::max(s, search(e.second));

    answer(x[s.begin], s.begin, s.end-1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x);
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
