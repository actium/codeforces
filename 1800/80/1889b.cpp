#include <algorithm>
#include <iostream>
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

void solve(const std::vector<integer>& a, unsigned c)
{
    const size_t n = a.size();

    std::vector<size_t> q(n-1);
    for (size_t i = 1; i < n; ++i)
        q[i-1] = i;

    std::sort(q.begin(), q.end(), [&](size_t i, size_t j) {
        return (i + 1ull) * c + a[j] > (j + 1ull) * c + a[i];
    });

    for (integer b = a[0]; !q.empty(); q.pop_back()) {
        if (b + a[q.back()] < (q.back() + 1ull) * c)
            return answer(false);

        b += a[q.back()];
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned c;
    std::cin >> c;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a, c);
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