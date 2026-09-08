#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p[3];
    for (size_t i = 0; i < n; ++i) {
        const size_t x = (a[i] >= 0) + (a[i] > 0);
        p[x].push_back(i);
    }

    if (!p[0].empty()) {
        for (const size_t x : p[0])
            a[x] = 0;

        if (p[2].empty() || p[0].front() < p[2].front())
            a[p[0].front()] = 1;

        if (p[2].empty() || p[0].back() > p[2].back())
            a[p[0].back()] = 1;
    }        

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
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
