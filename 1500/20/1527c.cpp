#include <iostream>
#include <map>
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
    const size_t n = a.size();

    std::map<unsigned, std::vector<size_t>> p;
    for (size_t i = 0; i < n; ++i)
        p[a[i]].push_back(i);

    integer k = 0;
    for (const auto& e : p) {
        integer t = 0;
        for (auto it = e.second.begin(); it != e.second.end(); ++it) {
            k += t * (n - *it);
            t += *it + 1;
        }
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
