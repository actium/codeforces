#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

struct Event {
    unsigned time;
    unsigned type;
    unsigned datum;
};

void solve(const std::vector<std::pair<unsigned, unsigned>>& o, const std::vector<std::pair<unsigned, unsigned>>& b, unsigned l)
{
    std::vector<Event> events;
    for (const std::pair<unsigned, unsigned>& x : o)
        events.push_back({ x.first, 0, x.second });

    for (const std::pair<unsigned, unsigned>& x : b)
        events.push_back({ x.first, 1, x.second });

    std::sort(events.begin(), events.end(), [](const Event& lhs, const Event& rhs) {
        return lhs.time != rhs.time ? lhs.time < rhs.time : lhs.type < rhs.type;
    });

    unsigned k = 0, p = 1;
    {
        std::multiset<unsigned> q;
        for (const Event& e : events) {
            if (e.type == 1) {
                q.insert(e.datum);
                continue;
            }

            unsigned x = e.time - 1 + p;
            while (x <= e.datum && !q.empty()) {
                const auto it = std::prev(q.end());
                x += *it;
                p += *it;
                q.erase(it);
                ++k;
            }

            if (x <= e.datum)
                return no_answer();
        }
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned l;
    std::cin >> l;

    std::vector<std::pair<unsigned, unsigned>> o(n), b(m);
    std::cin >> o >> b;

    solve(o, b, l);
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
