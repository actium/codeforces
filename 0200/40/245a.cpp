#include <iostream>
#include <vector>

struct Command {
    size_t t;
    size_t x;
    size_t y;
};

void answer(bool v)
{
    constexpr const char* s[2] = { "DEAD", "LIVE" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<Command>& commands)
{
    std::pair<size_t, size_t> f[2] = {};
    for (const Command& c : commands) {
        f[c.t-1].first += c.x;
        f[c.t-1].second += c.y;
    }

    for (size_t i : { 0, 1 })
        answer(f[i].first >= (f[i].first + f[i].second) / 2);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<Command> commands(n);
    for (Command& c : commands)
        std::cin >> c.t >> c.x >> c.y;

    solve(commands);

    return 0;
}

