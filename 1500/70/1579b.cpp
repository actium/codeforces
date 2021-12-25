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

struct Operation {
    size_t l;
    size_t r;
    size_t d;
};

void answer(const std::vector<Operation>& v)
{
    std::cout << v.size() << '\n';

    for (const Operation& x : v)
        std::cout << 1+x.l << ' ' << 1+x.r << ' ' << x.d << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<int> b = a;
    std::sort(b.begin(), b.end());

    std::vector<Operation> v;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;

        const size_t x = std::find(a.cbegin() + i, a.cend(), b[i]) - a.cbegin();
        v.push_back({ i, x, x - i });

        std::rotate(a.begin() + i, a.begin() + x, a.begin() + x + 1);
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
