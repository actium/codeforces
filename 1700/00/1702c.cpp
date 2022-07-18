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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& u, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    const size_t n = u.size();

    std::map<unsigned, size_t> l, r;
    for (size_t i = 0; i < n; ++i) {
        const auto it = l.find(u[i]);
        if (it == l.end())
            l[u[i]] = i;

        r[u[i]] = i;
    }

    for (const auto& x : q) {
        const auto lit = l.find(x.first);
        if (lit == l.cend()) {
            answer(false);
            continue;
        }

        const auto rit = r.find(x.second);
        if (rit == r.cend()) {
            answer(false);
            continue;
        }

        answer(lit->second <= rit->second);
    }
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> u(n);
    std::cin >> u;

    std::vector<std::pair<unsigned, unsigned>> q(k);
    std::cin >> q;

    solve(u, q);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
