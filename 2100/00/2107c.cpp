#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    std::cout << "Yes" << '\n';

    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

void solve(const std::string& s, const std::vector<int>& a, integer k)
{
    const size_t n = a.size();

    std::vector<integer> p(1+n);
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '1' && p[i] + a[i] > 0)
            p[i+1] = p[i] + a[i];
    }

    std::vector<integer> q(n+1);
    for (size_t i = n; i > 0; --i) {
        if (s[i-1] == '1' && q[i] + a[i-1] > 0)
            q[i-1] = q[i] + a[i-1];
    }

    std::vector<integer> b(a.begin(), a.end());
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0')
            b[i] = -k;
    }

    const size_t x = s.find('0');
    if (x != std::string::npos)
        b[x] = k - (p[x] + q[x+1]);

    integer u = 0, v = 0;
    for (const integer x : b) {
        u = std::max(x, u + x);
        v = std::max(v, u);
    }

    v == k ? answer(b) : no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    std::vector<int> a(n);
    std::cin >> a;

    solve(s, a, k);
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
