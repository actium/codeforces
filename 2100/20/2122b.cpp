#include <iostream>
#include <vector>

using integer = unsigned long long;

struct Stack {
    unsigned a;
    unsigned b;
    unsigned c;
    unsigned d;
};

std::istream& operator >>(std::istream& input, Stack& s)
{
    return input >> s.a >> s.b >> s.c >> s.d;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<Stack>& s)
{
    integer k = 0;
    for (Stack& e : s) {
        if (e.b > e.d) {
            k += e.a + (e.b - e.d);
            e.a = 0;
        }
        if (e.a > e.c)
            k += e.a - e.c;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<Stack> s(n);
    std::cin >> s;

    solve(s);
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
