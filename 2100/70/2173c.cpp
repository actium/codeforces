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
    std::cout << v.size() << '\n';

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

void solve(std::vector<unsigned>& a, unsigned k)
{
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    const size_t n = a.size();

    std::vector<unsigned> b;
    {
        std::vector<bool> v(n);
        for (size_t i = 0; i < n; ++i) {
            if (v[i])
                continue;

            unsigned x = a[i];
            for (size_t j = i; j < n && x <= k; ++j) {
                if (a[j] == x) {
                    v[j] = true;
                    x += a[i];
                }
            }

            if (x <= k)
                return no_answer();

            b.push_back(a[i]);
        }
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
