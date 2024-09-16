#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

struct Event {
    integer x;
    unsigned t;
};

bool operator <(const Event& lhs, const Event& rhs)
{
    return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.t < rhs.t;
}

void solve(const std::vector<std::pair<integer, integer>>& s)
{
    const size_t n = s.size();

    std::vector<Event> events(n + n);
    for (size_t i = 0; i < n; ++i) {
        events[2*i+0] = { s[i].first, 1 };
        events[2*i+1] = { s[i].second + 1, 0 };
    }

    std::sort(events.begin(), events.end());

    std::vector<integer> c(n);
    for (size_t i = 1, k = 1; i < n + n; ++i) {
        if (k != 0)
            c[k-1] += events[i].x - events[i-1].x;

        k += (events[i].t == 1 ? 1 : -1);
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<integer, integer>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
