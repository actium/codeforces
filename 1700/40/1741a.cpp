#include <iostream>
#include <string>

void answer(char x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    if (a.back() != b.back())
        return answer(a.back() > b.back() ? '<' : '>');

    const size_t k1 = a.length() - 1, k2 = b.length() - 1;
    if (k1 == k2)
        return answer('=');

    if (a.back() == 'S') {
        answer(k1 > k2 ? '<' : '>');
    } else {
        answer(k1 < k2 ? '<' : '>');
    }
}

void test_case()
{
    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
