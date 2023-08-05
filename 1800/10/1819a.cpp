#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<std::pair<size_t, size_t>> p(1 + n);
    for (size_t i = 0; i < n; ++i) {
        const unsigned x = a[i];
        if (x > n)
            continue;

        if (p[x].first == 0)
            p[x].first = 1 + i;

        p[x].second = 1 + i;
    }

    unsigned mex = 0;
    for (size_t i = 0; i < n && p[i].first != 0; ++i)
        ++mex;

    if (mex == n)
        return answer(false);

    const std::pair<size_t, size_t> r = p[mex + 1];
    for (unsigned i = 0; i < mex; ++i) {
        if (p[i].first > r.first && p[i].second < r.second)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
