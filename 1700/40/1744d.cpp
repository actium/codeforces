#include <algorithm>
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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    int r = n;
    for (const unsigned x : a)
        r -= __builtin_ctz(x);

    std::vector<unsigned> s;
    for (unsigned i = 2; i <= n; i += 2)
        s.push_back(__builtin_ctz(i));

    std::sort(s.begin(), s.end(), std::greater<unsigned>());

    unsigned k = 0;
    while (k < s.size() && r > 0)
        r -= s[k++];

    r <= 0 ? answer(k) : no_answer();
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
