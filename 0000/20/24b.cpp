#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Pilot {
    unsigned s = 0;
    unsigned p[50] = {};
};

void solve(const std::vector<std::vector<std::string>>& r)
{
    constexpr unsigned t[] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };

    std::map<std::string_view, Pilot> p;
    for (const std::vector<std::string>& u : r) {
        for (size_t i = 0; i < u.size(); ++i) {
            if (i < 10)
                p[u[i]].s += t[i];

            ++p[u[i]].p[i];
        }
    }

    const auto check = [&](std::string_view u, std::string_view v, bool alt) {
        if (alt && p[u].p[0] != p[v].p[0])
            return p[u].p[0] > p[v].p[0];

        if (p[u].s != p[v].s)
            return p[u].s > p[v].s;

        for (size_t i = 0; i < 50; ++i) {
            if (p[u].p[i] != p[v].p[i])
                return p[u].p[i] > p[v].p[i];
        }
        return false;
    };

    std::vector<std::string_view> s;
    for (const auto& e : p)
        s.push_back(e.first);

    for (const bool alt : { false, true }) {
        size_t x = 0;
        for (size_t i = 1; i < s.size(); ++i) {
            if (check(s[i], s[x], alt))
                x = i;
        }

        std::cout << s[x] << '\n';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    std::vector<std::vector<std::string>> r(t);
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        std::cin >> n;

        r[i].resize(n);
        std::cin >> r[i];
    }

    solve(r);

    return 0;
}
