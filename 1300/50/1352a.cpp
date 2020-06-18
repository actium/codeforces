#include <iostream>
#include <vector>

template <typename T>
void answer(const std::vector<T>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const T a : v) {
        std::cout << separator << a;
        separator = " ";
    }

    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> v;
    for (unsigned f = 1; n > 0; n /= 10, f *= 10) {
        const unsigned d = n % 10;
        if (d != 0)
            v.push_back(d * f);
    }

    answer(v);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

