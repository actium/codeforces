#include <iostream>
#include <string>
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

void solve(const std::vector<std::string>& t)
{
    unsigned k = 0;
    for (const std::string& x : t)
        k += (x == t[0]);

    answer(k);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> t(n);
    std::cin >> t;

    solve(t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
