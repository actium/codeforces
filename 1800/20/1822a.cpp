#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    std::cout << 1 + x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned t)
{
    const size_t n = a.size();

    size_t x = n;
    for (size_t i = 0; i < n; ++i) {
        if (i + a[i] <= t && (x == n || b[i] > b[x]))
            x = i;
    }

    if (x != n)
        return answer(x);

    no_answer();
}

void test_case()
{
    unsigned n, t;
    std::cin >> n >> t;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
