#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a)
{
    std::vector<size_t> q;
    for (size_t i = a.size() - 1; ~i != 0; --i) {
        if ((a[i] < 0) != (q.size() % 2 == 0))
            q.push_back(i);
    }

    answer(q);
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
