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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p)
{
    const auto check = [&](unsigned x) {
        std::pair<unsigned, unsigned> s = { ~0u, ~0u };
        for (const std::pair<unsigned, unsigned>& q : p) {
            if (q.first == x || q.second == x)
                continue;

            if (s.first == ~0u && s.second == ~0u)
                s = q;

            if (q.first == s.first && q.second == s.second || q.first == s.second && q.second == s.first)
                continue;

            if (q.first == s.first || q.second == s.first)
                s.second = ~0u;

            if (q.first == s.second || q.second == s.second)
                s.first = ~0u;

            if (q.first != s.first && q.first != s.second && q.second != s.first && q.second != s.second)
                return false;
        }
        return true;
    };

    answer(p.size() == 1 || check(p[0].first) || check(p[0].second));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> p(m);
    std::cin >> p;

    solve(p);

    return 0;
}
