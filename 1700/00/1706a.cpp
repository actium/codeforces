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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, size_t m)
{
    std::string s(m, 'B');
    for (unsigned x : a) {
        if (x > m + 1 - x)
            x = m + 1 - x;

        if (s[x-1] == 'B') {
            s[x-1] = 'A';
        } else {
            s[m-x] = 'A';
        }
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
