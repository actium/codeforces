#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

unsigned query(unsigned i, unsigned j)
{
    std::cout << '?' << ' ' << i << ' ' << j << std::endl;

    int r;
    std::cin >> r;
    return r;
}

void answer(bool v)
{
    constexpr char s[2] = { 'A', 'B' };
    std::cout << '!' << ' ' << s[v] << std::endl;
}

void solve(const std::vector<unsigned>& x)
{
    const size_t n = x.size();

    std::vector<bool> v(1+n);
    for (const unsigned i : x)
        v[i] = true;

    for (size_t i = 1; i <= n; ++i) {
        if (!v[i])
            return answer(query(i, i < n ? n : 1) != 0);
    }

    size_t i = 0, j = 0;
    for (size_t k = 1; k < n; ++k) {
        if (x[k] < x[i])
            i = k;

        if (x[k] > x[j])
            j = k;
    }

    const unsigned s = query(1+i, 1+j);
    answer(s >= n - 1 && query(1+j, 1+i) == s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x);
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
