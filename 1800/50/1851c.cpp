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

void solve(const std::vector<unsigned>& c, unsigned k)
{
    const size_t n = c.size();

    std::pair<size_t, unsigned> p = { 0, 0 };
    while (p.first < n && p.second < k)
        p.second += (c[p.first++] == c[0]);

    std::pair<size_t, unsigned> s = { n, 0 };
    while (s.first > 0 && s.second < k)
        s.second += (c[--s.first] == c[n-1]);

    if (c[0] == c[n-1])
        return answer(p.second == k);

    answer(p.first <= s.first);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
