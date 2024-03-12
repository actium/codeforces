#include <algorithm>
#include <iostream>
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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<integer>& a)
{
    std::sort(a.begin(), a.end());

    const integer x = a.front() * a.back();

    std::vector<integer> b;
    for (integer i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            b.push_back(i);

            if (i * i != x)
                b.push_back(x / i);
        }
    }

    std::sort(b.begin(), b.end());

    b == a ? answer(x) : no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a);
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
