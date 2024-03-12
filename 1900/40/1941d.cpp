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

struct Event {
    unsigned r;
    char c;
};

std::istream& operator >>(std::istream& input, Event& e)
{
    return input >> e.r >> e.c;
}

void answer(const std::set<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, const std::vector<Event>& events, unsigned x)
{
    std::set<unsigned> p;
    p.insert(x - 1);
    for (const Event& e : events) {
        std::set<unsigned> q;
        for (const unsigned x : p) {
            if (e.c != '1')
                q.insert((x + e.r) % n);

            if (e.c != '0')
                q.insert((x - e.r + n) % n);
        }

        std::swap(p, q);
    }

    answer(p);
}

void test_case()
{
    unsigned n, m, x;
    std::cin >> n >> m >> x;

    std::vector<Event> events(m);
    std::cin >> events;

    solve(n, events, x);
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
