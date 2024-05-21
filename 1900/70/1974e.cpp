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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, const std::vector<std::pair<unsigned, unsigned>>& v)
{
    using integer = unsigned long long;

    const size_t m = v.size();

    std::map<unsigned, integer> t;
    t[0] = 0;
    for (size_t i = 0; i < m; ++i) {
        for (auto it = t.rbegin(); it != t.rend(); ++it) {
            if (it->second < v[i].first)
                continue;

            const unsigned q = it->first + v[i].second;
            t[q] = std::max(t[q], it->second - v[i].first);
        }

        for (auto it = t.begin(); it != t.end(); ++it)
            it->second += x;
    }

    answer(t.rbegin()->first);
}

void test_case()
{
    size_t m;
    std::cin >> m;

    unsigned x;
    std::cin >> x;

    std::vector<std::pair<unsigned, unsigned>> v(m);
    std::cin >> v;

    solve(x, v);
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
