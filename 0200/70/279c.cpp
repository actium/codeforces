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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size();

    std::vector<size_t> u(n), d(n);
    for (size_t i = 1; i < n; ++i) {
        u[i] = (a[i-1] <= a[i] ? u[i-1] : i);
        d[i] = (a[i-1] >= a[i] ? d[i-1] : i);
    }

    for (const std::pair<unsigned, unsigned>& q : r)
        answer(u[d[q.second-1]] < q.first);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(a, r);

    return 0;
}
