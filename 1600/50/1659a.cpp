#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned r, unsigned b)
{
    const unsigned q = r / (b + 1), d = r % (b + 1);

    std::string s;
    for (unsigned i = 0; i <= b; ++i) {
        s.append(q + (i < d), 'R');
        s.append(i < b, 'B');
    }

    answer(s);
}

void test_case()
{
    unsigned n, r, b;
    std::cin >> n >> r >> b;

    solve(n, r, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
