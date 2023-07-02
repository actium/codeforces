#include <iostream>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& c, unsigned x)
{
    unsigned v = 0;

    const auto check = [&](const std::vector<unsigned>& s) {
        for (const unsigned q : s) {
            if ((q | x) != x)
                break;
            
            v |= q;
        }
    };

    check(a);
    check(b);
    check(c);

    answer(v == x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n), b(n), c(n);
    std::cin >> a >> b >> c;

    solve(a, b, c, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
