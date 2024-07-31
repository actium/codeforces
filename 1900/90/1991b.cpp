#include <iostream>
#include <vector>

constexpr unsigned oo = (1 << 30) - 1;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& b)
{
    const size_t n = b.size() + 1;

    std::vector<unsigned> a(n);
    a.front() = b.front();
    a.back() = b.back();
    for (size_t i = 1; i + 1 < n; ++i)
        a[i] = b[i-1] | b[i];

    for (size_t i = 1; i < n; ++i) {
        if ((a[i-1] & a[i]) != b[i-1])
            return no_answer();
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n-1);
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
