#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& a)
{
    const size_t n = a.size();

    unsigned k = 0, s = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned q = 0;
        for (size_t j = 0; j < n; ++j) {
            const unsigned d = a[j][(j+i)%n] - '0';
            q += d;
            s += d;
        }

        k = std::max(k, q);
    }

    answer(s - k + n - k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
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
