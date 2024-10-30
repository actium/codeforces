#include <iostream>
#include <map>
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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    unsigned k = 0;
    {
        std::map<long long, size_t> p;
        p[0] = 0;

        long long s = 0;
        for (size_t i = 0, x = 0; i < n; ++i) {
            s += a[i];

            const auto it = p.find(s);
            if (it != p.end() && it->second >= x) {
                ++k;
                x = i;
            }

            p[s] = i;
        }
    }
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
