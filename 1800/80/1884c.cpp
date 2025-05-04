#include <algorithm>
#include <iostream>
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

struct Event {
    unsigned type;
    unsigned time;
    size_t index;
};

bool operator <(const Event& lhs, const Event& rhs)
{
    return lhs.time != rhs.time ? lhs.time < rhs.time : lhs.type < rhs.type;
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& s, unsigned m)
{
    const size_t n = s.size();

    std::vector<Event> events;
    for (size_t i = 0; i < n; ++i) {
        events.push_back({ 1, s[i].first, i });
        events.push_back({ 0, s[i].second + 1, i });
    }

    std::sort(events.begin(), events.end());

    unsigned c[2] = {}, k = 0;
    for (const Event& e : events) {
        if (e.type == 0) {
            if (s[e.index].first != 1)
                --c[0];
            if (s[e.index].second != m)
                --c[1];
        } else {
            if (s[e.index].first != 1)
                k = std::max(k, ++c[0]);
            if (s[e.index].second != m)
                k = std::max(k, ++c[1]);
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s, m);
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
