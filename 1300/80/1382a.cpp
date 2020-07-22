#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << "YES" << '\n';
    std::cout << 1 << ' ' << v << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();
    const size_t m = b.size();

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (size_t i = 0, j = 0; i < n && j < m; ) {
        if (a[i] == b[j])
            return answer(a[i]);

        if (a[i] < b[j])
            ++i;
        else
            ++j;
    }

    no_answer();
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

