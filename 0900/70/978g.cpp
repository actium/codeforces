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

struct Test {
    unsigned s;
    unsigned d;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Test& t)
{
    return input >> t.s >> t.d >> t.c;
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

void solve(size_t n, std::vector<Test>& t)
{
    using queue_t = std::set<std::pair<unsigned, size_t>>;

    const size_t m = t.size();

    queue_t p;
    for (size_t i = 0; i < m; ++i)
        p.emplace(t[i].s, i);

    std::vector<unsigned> s(n);
    {
        queue_t q, r;
        for (size_t i = 0; i < n; ++i) {
            while (!p.empty() && p.begin()->first == i+1) {
                q.emplace(t[p.begin()->second].d, p.begin()->second);
                p.erase(p.begin());
            }

            if (!r.empty() && r.begin()->first == i+1) {
                s[i] = m + 1;
                r.erase(r.begin());
                continue;
            }

            if (!q.empty()) {
                const size_t x = q.begin()->second;
                if (t[x].d == i+1)
                    return no_answer();

                s[i] = x + 1;
                if (--t[x].c == 0) {
                    r.emplace(t[x].d, x);
                    q.erase(q.begin());
                }
            }
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<Test> t(m);
    std::cin >> t;

    solve(n, t);

    return 0;
}
