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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<integer>& a, unsigned k)
{
    const auto p = [k](integer x) {
        integer b = 1, c = 0;
        while (b * k <= x) {
            b *= k;
            ++c;
        }
        return std::make_pair(c, x - b);
    };

    std::set<integer> v;
    for (integer x : a) {
        while (x != 0) {
            const auto q = p(x);
            if (v.count(q.first) == 1)
                return answer(false);

            v.insert(q.first);
            x = q.second;
        }
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
