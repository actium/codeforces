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

void print(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void answer(const std::vector<unsigned>& v, const std::vector<unsigned>& w)
{
    std::cout << v.size() << ' ' << w.size() << '\n';

    print(v);
    print(w);
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    if (a.front() == a.back())
        return no_answer();

    std::vector<unsigned> b, c;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == a[0])
            b.push_back(a[i]);
        else
            c.push_back(a[i]);
    }

    answer(b, c);
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