#include <algorithm>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& v, unsigned l)
{
    const size_t n = v.size();

    std::sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second != rhs.second ? lhs.second < rhs.second : lhs.first < rhs.first;
    });

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        std::multiset<unsigned> q;
        unsigned s = 0;
        for (size_t j = i; j < n; ++j) {
            q.insert(v[j].first);
            s += v[j].first;
            while (s + v[j].second - v[i].second > l && !q.empty()) {
                const auto it = std::prev(q.end());
                s -= *it;
                q.erase(it);
            }

            k = std::max<unsigned>(k, q.size());
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned l;
    std::cin >> l;

    std::vector<std::pair<unsigned, unsigned>> v(n);
    std::cin >> v;

    solve(v, l);
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
