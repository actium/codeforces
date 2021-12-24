#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t z = s.rfind('*');
    if (z == std::string::npos)
        return answer(0);

    unsigned c = 1;
    for (size_t x = s.find('*'); x < z; x = s.rfind('*', x + k))
        ++c;

    answer(c);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
