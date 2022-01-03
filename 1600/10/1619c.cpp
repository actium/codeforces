#include <iostream>

using integer = long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

bool sub(integer s, integer a, integer& b)
{
    if (s < a)
        return false;

    if (a == 0) {
        b = s;
        return true;
    }

    if (s % 10 >= a % 10 && sub(s / 10, a / 10, b)) {
        b = b * 10 + s % 10 - a % 10;
        return true;
    }

    if (s % 100 < 10)
        return false;

    const integer r = s % 100 - a % 10;
    if (r > 9 || !sub(s / 100, a / 10, b))
        return false;

    b = b * 10 + r;
    return true;
}

void solve(integer a, integer s)
{
    integer b;
    if (sub(s, a, b))
        return answer(b);

    no_answer();
}

void test_case()
{
    integer a, s;
    std::cin >> a >> s;

    solve(a, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
