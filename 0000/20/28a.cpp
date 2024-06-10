#include <iostream>
#include <map>
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

void answer(const std::vector<int>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

unsigned distance(const std::pair<int, int>& s, const std::pair<int, int>& t)
{
    return abs(t.first - s.first) + abs(t.second - s.second);
}

void solve(const std::vector<std::pair<int, int>>& p, const std::vector<unsigned>& r)
{
    const size_t n = p.size(), m = r.size();

    std::map<unsigned, std::vector<unsigned>> s;
    for (size_t i = 0; i < m; ++i)
        s[r[i]].push_back(i + 1);

    const auto check = [&](size_t b, std::vector<int>& x) {
        std::map<unsigned, size_t> c;
        for (size_t i = b; i < n; i += 2) {
            const unsigned d = distance(p[i], p[(i+1)%n]) + distance(p[(i+1)%n], p[(i+2)%n]);

            const auto it = s.find(d);
            if (it == s.end() || c[d] >= it->second.size())
                return false;

            x[i] = -1;
            x[(i+1)%n] = it->second[c[d]++];
            x[(i+2)%n] = -1;
        }
        return true;
    };

    std::vector<int> x(n);
    if (check(0, x) || check(1, x))
        return answer(x);

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> p(n);
    std::cin >> p;

    std::vector<unsigned> r(m);
    std::cin >> r;

    solve(p, r);

    return 0;
}
