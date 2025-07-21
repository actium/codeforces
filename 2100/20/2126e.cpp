#include <iostream>
#include <numeric>
#include <vector>

using integer = unsigned long long;

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

template <typename Iterator1, typename Iterator2>
bool check(Iterator1 begin, Iterator1 end, Iterator2 x)
{
    integer g = 0;
    for (auto it = begin; it != end; ++it, ++x) {
        g = std::gcd(g, *x);
        if (g != *it)
            return false;
    }
    return true;
}

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& s)
{
    const size_t n = p.size();

    std::vector<integer> q(n);
    for (size_t i = 0; i < n; ++i)
        q[i] = std::lcm<integer>(p[i], s[i]);

    answer(check(p.begin(), p.end(), q.begin()) && check(s.rbegin(), s.rend(), q.rbegin()));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n), s(n);
    std::cin >> p >> s;

    solve(p, s);
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
