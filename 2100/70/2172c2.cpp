#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    constexpr const char* s[3] = { "Ajisai", "Mai", "Tie" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    for (unsigned mask = 1 << 19; mask != 0; mask >>= 1) {
        unsigned x = 0;
        for (size_t i = 0; i < n; ++i)
            x ^= (a[i] & mask) ^ (b[i] & mask);

        if (x != 0) {
            size_t p = n-1;
            while ((a[p] & mask) == (b[p] & mask))
                --p;

            return answer(p % 2);
        }
    }

    answer(2);
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
