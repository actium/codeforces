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

void solve(const std::vector<unsigned>& b)
{
    const size_t n = b.size();

    std::vector<unsigned> a(n);
    {
        std::vector<std::pair<unsigned, unsigned>> r(1 + n);
        for (size_t i = 0, g = 0; i < n; ++i) {
            const unsigned x = b[i];

            if (r[x].second == 0) {
                r[x].first = ++g;
                r[x].second = x;
            }

            a[i] = r[x].first;
            --r[x].second;
        }

        for (size_t i = 1; i <= n; ++i) {
            if (r[i].second != 0)
                return no_answer();
        }
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
