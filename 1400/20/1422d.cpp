#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Position {
    unsigned x;
    unsigned y;

    std::vector<std::pair<Position*, unsigned>> n;

    bool v = false;
};

unsigned operator -(const Position& lhs, const Position& rhs)
{
    return abs(lhs.x - rhs.x) + abs(lhs.y - rhs.y);
}

std::istream& operator >>(std::istream& input, Position& v)
{
    return input >> v.x >> v.y;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void build_graph(Position& s, std::vector<Position>& t, Position& f)
{
    const size_t n = t.size();

    const auto link = [&f](Position& s, Position& t) {
        s.n.emplace_back(&t, std::min(abs(t.x - s.x), abs(t.y - s.y)));
        s.n.emplace_back(&f, f - s);
    };

    std::vector<size_t> order(n);
    for (size_t i = 0; i < n; ++i)
        order[i] = i;

    std::sort(order.begin(), order.end(), [&t](size_t a, size_t b) { return t[a].x < t[b].x; });
    for (size_t i = 1; i < n; ++i) {
        link(t[order[i-1]], t[order[i]]);
        link(t[order[i]], t[order[i-1]]);

        if (s.x >= t[order[i-1]].x && s.x <= t[order[i]].x) {
            link(s, t[order[i-1]]);
            link(s, t[order[i]]);
        }
    }
    if (s.x < t[order.front()].x) {
        link(s, t[order.front()]);
    }
    if (s.x > t[order.back()].x) {
        link(s, t[order.back()]);
    }

    std::sort(order.begin(), order.end(), [&t](size_t a, size_t b) { return t[a].y < t[b].y; });
    for (size_t i = 1; i < n; ++i) {
        link(t[order[i-1]], t[order[i]]);
        link(t[order[i]], t[order[i-1]]);

        if (s.y >= t[order[i-1]].y && s.y <= t[order[i]].y) {
            link(s, t[order[i-1]]);
            link(s, t[order[i]]);
        }
    }
    if (s.y < t[order.front()].y) {
        link(s, t[order.front()]);
    }
    if (s.y > t[order.back()].y) {
        link(s, t[order.back()]);
    }

    s.n.emplace_back(&f, f - s);
}

void solve(Position& s, Position& f, std::vector<Position>& t)
{
    if (t.size() == 0)
        return answer(f - s);

    build_graph(s, t, f);

    struct State {
        Position* p;
        unsigned c;

        State(Position& p, unsigned c) :
            p(&p), c(c)
        {}

        bool operator <(const State& s) const
        {
            return c > s.c;
        }
    };

    std::priority_queue<State> q;
    q.emplace(s, 0);

    while (q.top().p->x != f.x || q.top().p->y != f.y) {
        const State state = q.top();
        q.pop();

        state.p->v = true;

        for (const auto& e : state.p->n) {
            if (!e.first->v)
                q.emplace(*e.first, state.c + e.second);
        }
    }

    answer(q.top().c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    Position s, f;
    std::cin >> s >> f;

    std::vector<Position> t(m);
    std::cin >> t;

    solve(s, f, t);

    return 0;
}

