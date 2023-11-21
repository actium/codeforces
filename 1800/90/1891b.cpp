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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& x)
{
    const size_t n = a.size();

    std::vector<size_t> p[31];
    for (size_t i = 0; i < n; ++i)
        p[__builtin_ctz(a[i])].push_back(i);

    for (const unsigned q : x) {
        for (size_t i = q; i < 31; ++i) {
            for (const size_t j : p[i]) {
                a[j] += 1 << q - 1;
                p[q-1].push_back(j);
            }
            p[i].clear();
        }
    }

    answer(a);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n), x(q);
    std::cin >> a >> x;

    solve(a, x);
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
