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
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> b;
    for (size_t i = 0; i < n; ++i) {
        if (i+1 < n && a[i] == a[i+1]) {
            b.push_back(a[i++]);
            b.push_back(a[i]);
        } else if (i+2 < n && a[i] == a[i+2]) {
            b.push_back(a[i++]);
            b.push_back(a[++i]);
        }
    }

    if (b.empty())
        b.push_back(0);

    answer(b);
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

