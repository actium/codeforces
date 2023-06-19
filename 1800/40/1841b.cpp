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

void solve(const std::vector<unsigned>& x)
{
    const unsigned n = x.size();

    std::string s = "1";
    for (unsigned i = 1, j = 0, b = ~0u; i < n; ++i) {
        if (x[i] < x[j] && b == ~0u && x[i] <= x[0]) {
            j = i;
            b = x[0];
        }

        if (x[i] >= x[j] && x[i] <= b) {
            s.push_back('1');
            j = i;
        } else {
            s.push_back('0');
        }
    }

    answer(s);
}

void test_case()
{
    size_t q;
    std::cin >> q;

    std::vector<unsigned> x(q);
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
