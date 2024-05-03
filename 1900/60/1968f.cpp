#include <algorithm>
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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] ^ a[i];

    std::map<unsigned, std::vector<size_t>> x;
    for (size_t i = 0; i <= n; ++i)
        x[p[i]].push_back(i);

    const auto search = [&](unsigned b, size_t s) -> size_t {
        const auto it = x.find(b);
        if (it == x.end())
            return 0;

        const auto jt = std::lower_bound(it->second.begin(), it->second.end(), s);
        return jt != it->second.end() ? *jt : 0;
    };

    for (const std::pair<unsigned, unsigned>& q : r) {
        const unsigned b = p[q.second] ^ p[q.first-1];
        if (b == 0) {
            answer(true);
        } else {
            const size_t s1 = search(p[q.second], q.first), s2 = search(b ^ p[s1], s1 + 1);
            answer(s1 != 0 && s2 != 0 && s2 < q.second);
        }
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
