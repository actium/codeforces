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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& s)
{
    const size_t n = s.size();

    std::sort(s.begin(), s.end());

    unsigned d = ~0;
    for (size_t i = 1; i < n; ++i)
        d = std::min(d, s[i] - s[i-1]);

    answer(d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

