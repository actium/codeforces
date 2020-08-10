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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& a)
{
    unsigned k = 0;

    for (const std::string& r : a)
        k += (r.back() != 'D');

    for (const char c : a.back())
        k += (c != 'R');

    answer(k - 2);  // - 2 times 'C'
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
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

