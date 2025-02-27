#include <iostream>
#include <numeric>
#include <string>
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

void solve(const std::string& s, const std::vector<unsigned>& p)
{
    const size_t n = s.size();

    integer x = 1;
    {
        std::vector<bool> v(n);
        for (size_t i = 0; i < n; ++i) {
            std::string t;
            while (!v[i]) {
                t.push_back(s[i]);
                v[i] = true;
                i = p[i] - 1;
            }

            const size_t m = t.size();
            if (m != 0) {
                unsigned d = 1;
                while (t.compare(d, m - d, t, 0, m - d) != 0 || t.compare(0, d, t, m - d, d) != 0)
                    ++d;

                x = std::lcm(x, d);
            }
        }
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(s, p);
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
