#include <iostream>
#include <map>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    std::vector<integer> v(n+1, -1);
    {
        integer k = 0;
        for (unsigned i = 0; i <= n; ++i) {
            v[i] = k + (f.find(i) != f.end() ? f[i] : 0);

            auto it = f.upper_bound(i);
            if (it == f.begin())
                break;

            --it;

            k += i - it->first;

            if (--it->second == 0)
                f.erase(it);
        }
    }

    answer(v);
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
