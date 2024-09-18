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
    char t;
    unsigned x;
};

std::istream& operator >>(std::istream& input, Event& e)
{
    input >> e.t;
    return e.t == '+' ? input : input >> e.x;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<Event>& events)
{
    std::vector<unsigned> s(events.size() / 2);
    {
        std::vector<size_t> q;
        size_t x = 0;
        for (const Event& e : events) {
            if (e.t == '+') {
                q.push_back(x++);
                continue;
            }

            if (q.empty())
                return no_answer();

            s[q.back()] = e.x;
            q.pop_back();
        }
    }
    {
        std::set<unsigned> t;
        size_t x = 0;
        for (const Event& e : events) {
            if (e.t == '+') {
                t.insert(s[x++]);
                continue;
            }

            if (e.x != *t.begin())
                return no_answer();

            t.erase(t.begin());
        }
    }
    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<Event> events(2 * n);
    std::cin >> events;

    solve(events);

    return 0;
}
