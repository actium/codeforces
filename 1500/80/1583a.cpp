#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned sum = 0, x = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += a[i];

        if (a[i] % 2 == 1)
            x = i;

        a[i] = 1 + i;
    }

    for (unsigned i = 2; i * i <= sum; ++i) {
        if (sum % i == 0)
            return answer(a);
    }

    a[x] = a.back();
    a.pop_back();
    answer(a);
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
