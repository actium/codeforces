#include <iostream>
#include <vector>

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

void solve(size_t k, const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size(), m = b.size();

    std::vector<unsigned> s;
    s.reserve(n + m);

    const auto push = [&](unsigned c) {
        s.push_back(c);
        k += (c == 0);
    };

    size_t i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > k && b[j] > k)
            return no_answer();

        if (a[i] <= k)
            push(a[i++]);

        if (b[j] <= k)
            push(b[j++]);
    }
    while (i < n) {
        if (a[i] > k)
            return no_answer();

        push(a[i++]);
    }
    while (j < m) {
        if (b[j] > k)
            return no_answer();

        push(b[j++]);
    }

    answer(s);
}

void test_case()
{
    size_t k, n, m;
    std::cin >> k >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(k, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
