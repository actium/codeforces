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

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& a)
{
    const size_t n = a.size();

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (a[i].first == 1)
            q.push_back(i);
    }

    std::vector<std::pair<size_t, size_t>> e;
    for (size_t i = 0; i < q.size(); ++i) {
        const size_t u = q[i], v = a[u].second;
        if (a[u].first == 0)
            continue;

        e.emplace_back(u, v);

        if (--a[v].first == 1)
            q.push_back(v);

        a[v].second ^= u;
    }

    answer(e);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
