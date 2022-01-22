#include <algorithm>
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

void solve(const std::vector<std::string>& s)
{
    unsigned f[3] = {};
    for (const std::string& x : s) {
        if (x.length() % 2 == 0) {
            ++f[std::count(x.cbegin(), x.cend(), '0') % 2];
        } else {
            ++f[2];
        }
    }

    const unsigned d = (f[2] == 0 && f[1] % 2 == 1);

    answer(s.size() - d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
