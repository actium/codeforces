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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (const int x : a)
        k += (x == -1);

    unsigned q = 0;
    if (2 * k > n) {
        q = k - n / 2;
        k -= q;
    }

    answer(q + k % 2);
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
