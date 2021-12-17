#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned h = 1 + a[0];
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == 0 && a[i-1] == 0)
            return answer(-1);

        if (a[i] == 1)
            h += (a[i-1] == 1 ? 5 : 1);
    }

    answer(h);
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
