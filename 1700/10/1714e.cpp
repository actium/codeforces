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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::set<unsigned> s;
    for (unsigned x : a) {
        while (x % 10 != 0 && x % 100 != 2 && x % 100 != 6)
            x += x % 10;

        if (x % 10 == 0)
            s.insert(x);
        else
            s.insert(x % 100);
    }

    answer(s.size() == 1);
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
