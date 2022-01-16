#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    integer s = 0, x = 0;
    for (const auto q : a) {
        s += q;
        x ^= q;
    }

    std::vector<integer> b;

    const auto push = [&](integer q) {
        b.push_back(q);
        s += q;
        x ^= q;
    };

    push(x & 0xAAAAAAAA ^ x);
    push(x & 0x55555555 ^ x);
    push(2 * x | s);

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
