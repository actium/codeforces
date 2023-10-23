#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<size_t> t(n);
    for (size_t i = 0; i < n; ++i)
        t[p[i]-1] = i;

    for (size_t ub = n; ub != 0; ub = t[n - ub]) {
        unsigned x = n - ub + 1;
        for (size_t i = t[n - ub]; i < ub; ++i) {
            if (p[i] != x++)
                return answer(false);
        }
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
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
