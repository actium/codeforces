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

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<integer> p[2];
    for (size_t i = 0; i < 2; ++i)
        p[i].resize(1 + n / 2);

    for (size_t i = 0; i < n; i += 2) {
        p[0][i/2+1] = p[0][i/2] + a[i];
        p[1][i/2+1] = p[1][i/2] + a[i+1];
    }

    std::vector<integer> q(1+n);
    for (size_t i = 0; i < n; ++i)
        q[i+1] = q[i] + a[i];

    std::vector<integer> s(n / 2);
    for (size_t i = 0; 2 * i < n; ++i) {
        s[i] = q[n] - q[n-i] - q[i];

        if (i % 2 == 0) {
            s[i] += p[1][n/2-i/2] - p[1][i/2];
            s[i] -= p[0][n/2-i/2] - p[0][i/2];
        } else {
            s[i] += p[0][n/2-i/2] - p[0][i/2+1];
            s[i] -= p[1][n/2-i/2-1] - p[1][i/2];
        }
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
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
