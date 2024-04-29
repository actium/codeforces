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

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size(), m = a[0].size();

    std::vector<size_t> t(n, n);
    t[0] = 0;
    for (size_t j = 0; j < m; ++j) {
        for (size_t i = 1, x = 0; i < n; ++i) {
            if (a[i][j] < a[i-1][j])
                x = i;

            t[i] = std::min(t[i], x);
        }
    }

    for (const std::pair<unsigned, unsigned>& q : r)
        answer(t[q.second-1] < q.first);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    size_t k;
    std::cin >> k;

    std::vector<std::pair<unsigned, unsigned>> r(k);
    std::cin >> r;

    solve(a, r);

    return 0;
}
