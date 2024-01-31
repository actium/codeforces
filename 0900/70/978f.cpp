#include <algorithm>
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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& r, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    const size_t n = r.size();

    std::vector<unsigned> q(n);
    for (const auto [u, v] : e) {
        q[v-1] -= (r[u-1] < r[v-1]);
        q[u-1] -= (r[v-1] < r[u-1]);
    }

    std::vector<unsigned> c = r;
    std::sort(c.begin(), c.end());

    for (size_t i = 0; i < n; ++i)
        q[i] += std::lower_bound(c.begin(), c.end(), r[i]) - c.begin();

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> r(n);
    std::cin >> r;

    std::vector<std::pair<unsigned, unsigned>> e(k);
    std::cin >> e;

    solve(r, e);

    return 0;
}
