#include <iostream>
#include <map>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::map<int, int>& c)
{
    for (const auto& e : c) {
        const auto it = c.find(e.first + e.second);
        if (it != c.end() && it->first + it->second == e.first)
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::map<int, int> c;
    for (size_t i = 0; i < n; ++i) {
        int x, d;
        std::cin >> x >> d;

        c.emplace(x, d);
    }

    solve(c);

    return 0;
}

