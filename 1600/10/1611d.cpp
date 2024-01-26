#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& b, const std::vector<unsigned>& p)
{
    const size_t n = b.size();

    std::vector<unsigned> v(n);
    for (size_t i = 0, d = 0; i < n; ++i) {
        const size_t x = p[i] - 1;
        if (b[x] - 1 != x && v[b[x]-1] == 0)
            return no_answer();

        v[x] = ++d;
    }

    std::vector<unsigned> w(n);
    for (size_t i = 0; i < n; ++i)
        w[i] = v[i] - v[b[i]-1];

    answer(w);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n), p(n);
    std::cin >> b >> p;

    solve(b, p);
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
