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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned evaluate(const std::vector<unsigned>& a, size_t p, size_t q)
{
    const size_t n = a.size();

    std::vector<unsigned> s;
    while (~p != 0 && q < n && a[p] == a[q]) {
        s.push_back(a[p]);
        --p;
        ++q;
    }

    std::sort(s.begin(), s.end());

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] != i)
            return i;
    }
    return s.size();
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned k = 1;
    for (size_t i = 1; i < n; ++i) {
        if (a[i-1] == a[i])
            k = std::max(k, evaluate(a, i-1, i));
    }
    for (size_t i = 2; i < n; ++i) {
        if (a[i-2] == a[i])
            k = std::max(k, evaluate(a, i-1, i-1));
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
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
