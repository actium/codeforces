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
    size_t x;
    size_t y;
    size_t z;
};

void answer(const std::vector<Operation>& v)
{
    std::cout << v.size() << '\n';

    for (const Operation& o : v)
        std::cout << 1+o.x << ' ' << 1+o.y << ' ' << 1+o.z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    if (a[n-1] < a[n-2])
        return no_answer();

    std::vector<Operation> p;
    if (a[n-1] >= 0) {
        for (size_t i = 0; i < n - 2; ++i)
            p.push_back({ i, n-2, n-1 });
    } else {
        for (size_t i = 1; i < n; ++i) {
            if (a[i] < a[i-1])
                return no_answer();
        }
    }

    answer(p);
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
