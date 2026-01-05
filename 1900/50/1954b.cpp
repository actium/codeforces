#include <iostream>
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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    a.push_back(0);

    unsigned q = n;
    for (size_t i = 0, k = 0; i <= n; ++i) {
        if (a[i] == a[0]) {
            ++k;
        } else {
            q = std::min<unsigned>(q, k);
            k = 0;
        }
    }

    q < n ? answer(q) : no_answer();
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
