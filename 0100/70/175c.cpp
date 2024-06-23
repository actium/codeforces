#include <algorithm>
#include <iostream>
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

void solve(std::vector<std::pair<unsigned, unsigned>>& q, const std::vector<integer>& p)
{
    const size_t n = q.size(), m = p.size();

    std::sort(q.begin(), q.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });

    integer k = 0, x = 1, v = 0;
    for (size_t i = 0, j = 0; i < n; ) {
        if (j == m || k + q[i].first < p[j]) {
            v += x * q[i].first * q[i].second;
            k += q[i++].first;
        } else {
            const integer d = p[j++] - k;
            v += x++ * d * q[i].second;
            q[i].first -= d;
            k += d;
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> q(n);
    std::cin >> q;

    size_t t;
    std::cin >> t;

    std::vector<integer> p(t);
    std::cin >> p;

    solve(q, p);

    return 0;
}
