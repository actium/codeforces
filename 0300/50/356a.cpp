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

struct Fight {
    unsigned l;
    unsigned r;
    unsigned x;
};

std::istream& operator >>(std::istream& input, Fight& f)
{
    return input >> f.l >> f.r >> f.x;
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

void solve(size_t n, const std::vector<Fight>& f)
{
    std::set<unsigned> s;
    for (unsigned i = 1; i <= n + 1; ++i)
        s.insert(i);

    std::vector<unsigned> v(n);
    for (const Fight& q : f) {
        for (auto it = s.lower_bound(q.l); *it <= q.r; ) {
            if (*it != q.x) {
                v[*it - 1] = q.x;
                it = s.erase(it);
            } else {
                ++it;
            }
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<Fight> f(m);
    std::cin >> f;

    solve(n, f);

    return 0;
}
