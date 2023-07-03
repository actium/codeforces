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

void print(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << "YES" << '\n';
    print(x);
    print(y);
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> p(n), q(n), r(1+n, 2);
    for (size_t i = 0; i < n; ++i) {
        const unsigned x = a[i];
        if (r[x] == 0)
            return no_answer();

        (--r[x] == 0 ? q : p)[i] = x;
    }

    std::set<unsigned> pp, qq;
    for (unsigned x = 1; x <= n; ++x) {
        pp.insert(x);
        qq.insert(x);
    }

    for (size_t i = 0; i < n; ++i) {
        pp.erase(p[i]);
        qq.erase(q[i]);
    }

    for (size_t i = 0; i < n; ++i) {
        if (p[i] == 0) {
            auto it = pp.upper_bound(q[i]);
            if (it-- == pp.begin())
                return no_answer();

            p[i] = *it;
            pp.erase(it);
        } else {
            auto it = qq.upper_bound(p[i]);
            if (it-- == qq.begin())
                return no_answer();

            q[i] = *it;
            qq.erase(it);
        }
    }

    answer(p, q);
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
