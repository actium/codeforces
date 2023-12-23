#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

bool check(const std::vector<unsigned>& p, const std::vector<int>& q)
{
    const size_t n = p.size();

    std::vector<unsigned> f(n);
    for (const unsigned x : p) {
        if (x > n || f[x-1]++ != 0)
            return false;
    }
    for (size_t i = 1; i < n; ++i) {
        if (p[i] - p[i-1] != q[i-1])
            return false;
    }
    return true;
}

void solve(const std::vector<int>& q)
{
    const size_t n = q.size() + 1;

    long long s = 0, t = 0;
    for (const int x : q) {
        s += x;
        t = std::min(t, s);
    }

    std::vector<unsigned> p(n);
    p[0] = 1 - t;
    for (size_t i = 1; i < n; ++i)
        p[i] = p[i-1] + q[i-1];

    if (!check(p, q))
        return no_answer();

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> q(n-1);
    std::cin >> q;

    solve(q);

    return 0;
}
