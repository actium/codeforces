#include <algorithm>
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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    size_t x = 1;
    while (x < n && a[x] != a[x-1])
        ++x;

    if (x != n) {
        const unsigned b = a[x];

        a.erase(a.begin() + x - 1, a.begin() + x + 1);

        for (size_t i = 1; i + 2 < n; ++i) {
            if (2 * b + a[i-1] > a[i])
                return answer({ b, b, a[i-1], a[i] });
        }
    }

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
