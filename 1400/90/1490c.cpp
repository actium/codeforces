#include <iostream>
#include <set>

using integer = unsigned long long;

std::set<integer> q;

void initialize()
{
    for (integer i = 1; i <= 10000; ++i)
        q.insert(i * i * i);
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(integer x)
{
    for (integer i = 1; i * i * i < x; ++i) {
        if (q.count(x - i * i * i) == 1)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    integer x;
    std::cin >> x;

    solve(x);
}

int main()
{
    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

