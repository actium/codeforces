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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<int>& a, const std::vector<unsigned>& l)
{
    const size_t n = a.size();

    std::vector<int> b;
    for (size_t i = 0; i < n; ++i) {
        if (l[i] == 0)
            b.push_back(a[i]);
    }

    std::sort(b.begin(), b.end(), std::greater<int>());

    for (size_t i = 0, j = 0; i < n; ++i) {
        if (l[i] == 0)
            a[i] = b[j++];
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<unsigned> l(n);
    std::cin >> l;

    solve(a, l);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

