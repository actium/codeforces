#include <iostream>
#include <set>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& d)
{
    const size_t n = a.size();

    std::multiset<unsigned> s(d.begin(), d.end());
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;

        const auto it = s.find(b[i]);
        if (it == s.end())
            return answer(false);

        s.erase(it);
    }

    for (size_t i = 0; i < n; ++i) {
        if (b[i] == d.back())
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> d(m);
    std::cin >> d;

    solve(a, b, d);
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
