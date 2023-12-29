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

void solve(const std::vector<unsigned>& a)
{
    using integer = long long;

    const size_t n = a.size();

    std::set<integer> p;
    integer s = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 0)
            s += a[i];
        else
            s -= a[i];

        if (s == 0 || !p.insert(s).second)
            return answer(true);
    }

    answer(false);
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
