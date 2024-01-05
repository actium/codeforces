#include <iostream>
#include <queue>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<integer> c(n);

    std::priority_queue<integer, std::vector<integer>, std::greater<integer>> s;
    integer d = 0;
    for (size_t i = 0; i < n; ++i) {
        s.push(a[i] + d);
        while (!s.empty() && s.top() <= b[i] + d) {
            c[i] += s.top() - d;
            s.pop();
        }
        c[i] += s.size() * b[i];
        d += b[i];
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
