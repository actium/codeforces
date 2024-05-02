#include <iostream>
#include <queue>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Data {
    unsigned k;
    unsigned s;
    unsigned x;
    unsigned y;
    unsigned m;
};

std::istream& operator >>(std::istream& input, Data& d)
{
    return input >> d.k >> d.s >> d.x >> d.y >> d.m;
}

struct Task {
    size_t s;
    unsigned i;
    unsigned r;
};

bool operator <(const Task& lhs, const Task& rhs)
{
    return lhs.r > rhs.r;
}

void answer(unsigned u, const std::vector<Task>& v)
{
    std::cout << u << '\n';

    if (v.size() <= 200000) {
        for (const Task& x : v)
            std::cout << x.r << ' ' << 1+x.s << '\n';
    }
}

void solve(const std::vector<Data>& d)
{
    const size_t n = d.size();

    std::vector<Task> t;
    {
        std::priority_queue<Task> q;
        for (size_t i = 0; i < n; ++i)
            q.push({ i, 1, d[i].s });

        while (!q.empty()) {
            std::vector<Task> p;
            if (!t.empty() && q.top().r < t.back().r) {
                while (!q.empty() && q.top().r < t.back().r) {
                    p.push_back(q.top());
                    q.pop();
                }
            }

            if (q.empty()) {
                t.push_back(p[0]);
                p[0] = p.back();
                p.pop_back();
            } else {
                t.push_back(q.top());
                q.pop();
            }

            for (const Task& x : p)
                q.push(x);

            if (const Task& x = t.back(); x.i < d[x.s].k)
                q.push({ x.s, x.i + 1, (1ull * x.r * d[x.s].x + d[x.s].y) % d[x.s].m });
        }
    }

    unsigned k = 0;
    for (size_t i = 1; i < t.size(); ++i)
        k += (t[i-1].r > t[i].r);

    answer(k, t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Data> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}
