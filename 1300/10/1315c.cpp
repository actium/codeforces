#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
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

void solve(const std::vector<unsigned>& b)
{
    const size_t n = b.size();

    std::set<unsigned> s;
    for (unsigned x = 1; x <= 2 * n; ++x)
        s.insert(x);

    for (const unsigned x : b)
        s.erase(x);

    std::vector<unsigned> a(2 * n);
    for (size_t i = 0; i < n; ++i) {
        const auto it = s.upper_bound(b[i]);
        if (it == s.cend())
            return no_answer();

        a[2*i+0] = b[i];
        a[2*i+1] = *it;
        s.erase(it);
    }

    answer(a);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

