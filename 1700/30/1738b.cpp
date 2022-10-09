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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, std::vector<int>& s)
{
    const size_t k = s.size();
    if (k == 1)
        return answer(true);

    std::vector<int> a(n);
    for (size_t i = 1; i < k; ++i)
        a[n-k+i] = s[i] - s[i-1];
    
    const long long x = n - k + 1;
    answer(s[0] <= a[x] * x && std::is_sorted(a.begin() + x, a.end()));
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> s(k);
    std::cin >> s;

    solve(n, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
