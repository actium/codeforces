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

void solve(const std::vector<unsigned>& a)
{
    std::vector<unsigned> t[4];
    for (const unsigned x : a) {
        const auto p2 = (x % 2 == 0), p3 = (x % 3 == 0);
        t[p2*2+p3].push_back(x);
    }

    std::vector<unsigned> b;
    for (const auto i : { 3, 2, 0, 1 })
        b.insert(b.end(), t[i].begin(), t[i].end());

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
