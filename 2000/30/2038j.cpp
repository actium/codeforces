#include <iostream>
#include <vector>

using event_t = std::pair<char, unsigned>;

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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<event_t>& events)
{
    unsigned q = 0;
    for (const event_t& e : events) {
        if (e.first == 'B') {
            answer(q < e.second);
            q -= std::min(q, e.second);
        } else {
            q += e.second;
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<event_t> events(n);
    std::cin >> events;

    solve(events);

    return 0;
}
