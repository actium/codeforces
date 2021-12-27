#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        if (x == 0)
            continue;

        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& b)
{
    using integer = unsigned long long;

    integer s = 0;
    for (const unsigned x : b)
        s += x;

    std::sort(b.begin(), b.end());

    for (auto it = b.begin(); it != b.end(); ++it) {
        const integer x = s - 2 * *it;
        if (x > b.back())
            continue;

        const auto c = std::lower_bound(b.begin(), b.end(), x);
        if (c != b.end() && *c == x && c != it) {
            *it = 0;
            *c = 0;
            return answer(b);
        }
    }

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n + 2);
    std::cin >> b;

    solve(b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
