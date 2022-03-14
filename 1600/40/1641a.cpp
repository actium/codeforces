#include <algorithm>
#include <iostream>
#include <set>
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

void solve(std::vector<unsigned>& a, unsigned x)
{
    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    std::multiset<unsigned long long> s;
    for (const unsigned q : a) {
        const auto it = s.find(1ull * q * x);
        if (it != s.end()) {
            s.erase(it);
        } else {
            s.insert(q);
        }
    }

    answer(s.size());
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
