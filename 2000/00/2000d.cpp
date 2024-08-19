#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::string& s)
{
    const size_t n = a.size();

    std::vector<integer> ps(1+n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    integer k = 0;
    for (size_t i = s.find('L'), j = s.rfind('R'); i < j && j != std::string::npos; i = s.find('L', i+1), j = s.rfind('R', j-1))
        k += ps[j+1] - ps[i];

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::string s;
    std::cin >> s;

    solve(a, s);
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
