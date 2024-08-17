#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& s)
{
    const size_t n = s.size();

    std::vector<int> d(n);

    const auto set = [&](size_t begin, size_t end, int delta) {
        if (begin < n)
            d[begin] += delta;

        if (end < n)
            d[end] -= delta;
    };

    integer k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] > d[i]) {
            k += s[i] - d[i] - 1;
        } else {
            set(i+1, i+2, d[i] - s[i] + 1);
        }

        set(i+1, n, d[i]);
        set(i+2, i+s[i]+1, 1);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);
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
