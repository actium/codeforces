#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& b)
{
    const size_t n = b.size();

    std::vector<size_t> p(n);
    p[0] = 0;
    for (size_t i = 1; i < n; ++i)
        p[i] = (b[i] < b[p[i-1]] - (i - p[i-1]) ? p[i-1] : i);

    std::vector<int> s(n);
    s[n-1] = n-1;
    for (size_t i = n-2; ~i != 0; --i)
        s[i] = (b[i] < b[s[i+1]] - (s[i+1] - i) ? s[i+1] : i);

    unsigned v = 0;
    for (size_t i = 1; i + 1 < n; ++i)
        v = std::max<unsigned>(v, b[p[i-1]] + b[i] + b[s[i+1]] - (s[i+1] - p[i-1]));

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b);
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
