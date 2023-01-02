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

void solve(size_t n, const std::vector<std::pair<size_t, size_t>>& e)
{
    if (e.empty())
        return answer(true);

    std::vector<unsigned> d(n);
    for (const std::pair<size_t, size_t>& q : e) {
        ++d[q.first - 1];
        ++d[q.second - 1];
    }

    std::map<unsigned, unsigned> f;
    for (const unsigned x : d)
        ++f[x];

    const unsigned k = f.rbegin()->second;
    if (k != f.rbegin()->first + 1 || k * (k - 1) != 2 * e.size())
        return answer(false);

    answer(f.size() == 2 && f.begin()->first == 0 || f.size() == 1);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<size_t, size_t>> e(m);
    std::cin >> e;

    solve(n, e);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
