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

void solve(const std::vector<unsigned>& a, unsigned q)
{
    const size_t n = a.size();

    std::string s(n, '0');
    for (size_t i = n-1, x = 0; ~i != 0; --i) {
        if (a[i] > x && x == q)
            continue;

        if (a[i] > x)
            ++x;

        s[i] = '1';
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned q;
    std::cin >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, q);
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
