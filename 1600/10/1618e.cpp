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
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::vector<unsigned>& b)
{
    using integer = unsigned long long;

    const size_t n = b.size();

    integer s = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        s += b[i];
        k += i + 1;
    }

    if (s % k != 0)
        return no_answer();

    s /= k;

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i) {
        const long long x = s + b[i] - b[(i+1)%n];

        if (x <= 0 || x % n != 0)
            return no_answer();

        a[(i+1)%n] = x / n;
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
