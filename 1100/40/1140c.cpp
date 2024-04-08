#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& s, size_t k)
{
    std::sort(s.begin(), s.end(), [](const auto& lhs, const auto& rhs) {
        return std::make_pair(lhs.second, lhs.first) > std::make_pair(rhs.second, rhs.first);
    });

    integer u = 0, v = 0;
    {
        std::multiset<unsigned> q;
        for (const std::pair<unsigned, unsigned>& x : s) {
            q.insert(x.first);
            u += x.first;

            if (q.size() > k) {
                const auto it = q.begin();
                u -= *it;
                q.erase(it);
            }

            v = std::max(v, u * x.second);
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s, k);

    return 0;
}
