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

void solve(const std::vector<unsigned>& a, const std::vector<int>& b, unsigned k)
{
    const size_t n = a.size();

    int s = -1;
    for (size_t i = 0; i < n; ++i) {
        if (b[i] != -1)
            s = a[i] + b[i];
    }

    if (s == -1) {
        unsigned min = a[0], max = a[0];
        for (size_t i = 1; i < n; ++i) {
            min = std::min(min, a[i]);
            max = std::max(max, a[i]);
        }

        return answer(min + k - max + 1);
    }

    for (size_t i = 0; i < n; ++i) {
        if (b[i] != -1 && a[i] + b[i] != s)
            return answer(0);

        if (b[i] == -1 && (a[i] > s || a[i] + k < s))
            return answer(0);
    }

    answer(1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<int> b(n);
    std::cin >> b;

    solve(a, b, k);
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
