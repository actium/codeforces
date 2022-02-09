#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

struct Post {
    size_t i;
    size_t lb;
    size_t ub;
};

void solve(size_t n, const std::vector<unsigned>& a)
{
    std::vector<Post> p(n);
    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i) {
        p[i].i = i;
        p[i].lb = i;
        p[i].ub = i;

        x[i] = i;
    }

    for (const unsigned q : a) {
        const size_t i = x[q-1];
        if (i == 0)
            continue;

        Post& u = p[i];
        u.lb = std::min(u.lb, i - 1);
        x[u.i] = i - 1;

        Post& v = p[i-1];
        v.ub = std::max(v.ub, i);
        x[v.i] = i;

        std::swap(u, v);
    }

    std::vector<std::pair<unsigned, unsigned>> y(n);
    for (const Post& q : p) {
        y[q.i].first = 1 + q.lb;
        y[q.i].second = 1 + q.ub;
    }

    answer(y);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a);

    return 0;
}
