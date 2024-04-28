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

struct Command {
    unsigned t;
    unsigned k;
    char d;
};

void answer(const std::vector<Command>& v)
{
    std::cout << v.size() << '\n';

    for (const Command& x : v) {
        std::cout << x.t;
        if (x.t == 1)
            std::cout << ' ' << x.k << ' ' << x.d;

        std::cout << '\n';
    }
}

void solve(std::vector<std::pair<int, int>>& p)
{
    std::sort(p.begin(), p.end(), [](const auto& lhs, const auto& rhs) {
        return abs(lhs.first) + abs(lhs.second) < abs(rhs.first) + abs(rhs.second);
    });

    std::vector<Command> c;
    for (const std::pair<int, int>& x : p) {
        if (x.first < 0)
            c.push_back({ 1, -x.first, 'L' });
        if (x.first > 0)
            c.push_back({ 1, x.first, 'R' });
        if (x.second < 0)
            c.push_back({ 1, -x.second, 'D' });
        if (x.second > 0)
            c.push_back({ 1, x.second, 'U' });

        c.push_back({ 2, 0, 0 });

        if (x.first < 0)
            c.push_back({ 1, -x.first, 'R' });
        if (x.first > 0)
            c.push_back({ 1, x.first, 'L' });
        if (x.second < 0)
            c.push_back({ 1, -x.second, 'U' });
        if (x.second > 0)
            c.push_back({ 1, x.second, 'D' });

        c.push_back({ 3, 0, 0 });
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, int>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
