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
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& c, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = c.size();

    std::vector<unsigned long long> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + c[i];

    std::vector<unsigned> s(1 + n);
    for (size_t i = 0; i < n; ++i)
        s[i+1] = s[i] + (c[i] == 1);

    for (const std::pair<unsigned, unsigned>& q : r)
        answer(q.first != q.second && p[q.second] - p[q.first-1] > s[q.second] - s[q.first-1] + q.second - q.first);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(c, r);
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
