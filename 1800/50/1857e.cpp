#include <algorithm>
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

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

struct Item {
    size_t index;
    unsigned value;
    integer sum;
};

void solve(const std::vector<unsigned>& x)
{
    const size_t n = x.size();

    std::vector<Item> s(n);
    for (size_t i = 0; i < n; ++i) {
        s[i].index = i;
        s[i].value = x[i];
    }

    std::sort(s.begin(), s.end(), [](const Item& lhs, const Item& rhs) {
        return lhs.value != rhs.value ? lhs.value < rhs.value : lhs.index < rhs.index;
    });

    s[0].sum = 1;
    for (size_t i = 1; i < n; ++i)
        s[0].sum += s[i].value - s[0].value + 1;

    for (size_t i = 1; i < n; ++i) {
        const auto it = std::upper_bound(s.begin(), s.end(), s[i-1].value, [](unsigned x, const Item& item) {
            return x < item.value;
        });
        const auto jt = std::lower_bound(s.begin(), s.end(), s[i].value, [](const Item& item, unsigned x) {
            return item.value < x;
        });
        const int k = (s.end() - it) - (jt - s.begin());

        s[i].sum = s[i-1].sum - static_cast<integer>(s[i].value - s[i-1].value) * k;
    }

    std::vector<integer> c(n);
    for (size_t i = 0; i < n; ++i)
        c[s[i].index] = s[i].sum;

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x);
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
