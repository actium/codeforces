#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& r, const std::vector<int>& b)
{
    int s1 = 0, b1 = 0;
    for (const int x : r) {
        s1 += x;
        b1 = std::max(b1, s1);
    }

    int s2 = 0, b2 = 0;
    for (const int x : b) {
        s2 += x;
        b2 = std::max(b2, s2);
    }

    answer(b1 + b2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> r(n);
    std::cin >> r;

    size_t m;
    std::cin >> m;

    std::vector<int> b(m);
    std::cin >> b;

    solve(r, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

