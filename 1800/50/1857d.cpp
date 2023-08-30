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

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}


void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size();

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&](size_t i, size_t j) {
        return a[i] - b[i] > a[j] - b[j];
    });

    std::vector<size_t> p;
    for (const size_t i : o) {
        if (a[i] - b[i] == a[o[0]] - b[o[0]])
            p.push_back(i);
    }

    std::sort(p.begin(), p.end());

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
