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

void solve(const std::vector<unsigned>& a)
{
    std::multiset<unsigned> s(a.begin(), a.end());

    integer k = 0, p = 0;
    while (s.size() > 1) {
        const unsigned d = *s.begin();
        p += d;
        s.erase(s.begin());
        k += d;

        const unsigned e = *s.rbegin();
        if (p >= e) {
            p -= e;
            s.erase(std::prev(s.end()));
            ++k;

            if (p != 0) {
                s.insert(p);
                k -= p;
                p = 0;
            }
        }
    }
    if (!s.empty()) {
        const unsigned e = *s.rbegin();
        k += (e > 1 ? (e - p + 1) / 2 : 0) + 1;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
