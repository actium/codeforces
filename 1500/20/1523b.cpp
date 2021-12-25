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
    unsigned t;
    size_t i;
    size_t j;
};

void answer(const std::vector<Operation>& v)
{
    std::cout << v.size() << '\n';

    for (const Operation& x : v)
        std::cout << x.t << ' ' << 1+x.i << ' ' << 1+x.j << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<Operation> v;
    v.reserve(6 * n);

    for (size_t i = 0; i < n; i += 2) {
        v.push_back({ 1, i, i+1 });
        v.push_back({ 2, i, i+1 });
        v.push_back({ 2, i, i+1 });
        v.push_back({ 1, i, i+1 });
        v.push_back({ 2, i, i+1 });
        v.push_back({ 2, i, i+1 });
    }

    answer(v);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
