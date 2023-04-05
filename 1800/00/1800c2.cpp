#include <iostream>
#include <set>
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

void solve(const std::vector<unsigned>& s)
{
    integer p = 0;

    std::multiset<unsigned> v;
    for (const unsigned x : s) {
        if (x != 0) {
            v.insert(x);
        } else if (!v.empty()) {
            const auto it = std::prev(v.end());
            p += *it;
            v.erase(it);
        }
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
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
