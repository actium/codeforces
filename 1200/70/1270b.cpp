#include <iostream>
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
    std::cout << "NO" << '\n';
}

void answer(unsigned x, unsigned y)
{
    std::cout << "YES" << '\n';
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    for (size_t i = 1; i < n; ++i) {
        if (abs(a[i] - a[i-1]) > 1)
            return answer(i, i+1);
    }

    no_answer();
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

