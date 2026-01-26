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

void solve(const std::vector<unsigned>& a, unsigned s, unsigned x)
{
    unsigned t = 0;
    for (const unsigned v : a)
        t += v;

    answer(t <= s && (s - t) % x == 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned s, x;
    std::cin >> s >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, s, x);
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
