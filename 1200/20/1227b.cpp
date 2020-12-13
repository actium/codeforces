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

void no_answer()
{
    std::cout << -1 << '\n';
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

void solve(const std::vector<unsigned>& q)
{
    const size_t n = q.size();

    std::vector<unsigned> p(n);
    std::vector<bool> v(n);
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (i == 0 || q[i] != q[i-1]) {
            p[i] = q[i];
        } else {
            while (v[j])
                ++j;

            p[i] = 1+j;
        }

        v[p[i]-1] = true;

        if (std::max(i == 0 ? 0 : q[i-1], p[i]) != q[i])
            return no_answer();
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> q(n);
    std::cin >> q;

    solve(q);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

