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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::pair<int, int>>& s, int x1, int x2)
{
    using integer = long long;

    std::set<std::pair<integer, integer>> u;
    for (const std::pair<int, int>& q : s)
        u.emplace(1ll * q.first * x1 + q.second, 1ll * q.first * x2 + q.second);

    std::set<std::pair<integer, integer>> v;
    for (const std::pair<integer, integer>& q : u) {
        for (auto it = v.rbegin(); it != v.rend() && q.second < it->first; ++it) {
            if (q.first > it->second)
                return answer(true);
        }

        v.emplace(q.second, q.first);
    }

    answer(false);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    int x1, x2;
    std::cin >> x1 >> x2;

    std::vector<std::pair<int, int>> s(n);
    std::cin >> s;

    solve(s, x1, x2);

    return 0;
}
