#include <iostream>
#include <string>

bool query(const std::string& x)
{
    std::cout << '?' << ' ' << x << std::endl;

    unsigned r;
    std::cin >> r;
    return r == 1;
}

void answer(const std::string& x)
{
    std::cout << '!' << ' ' << x << std::endl;
}

void solve(size_t n)
{
    std::string t;

    const auto check = [&](const std::string& q) {
        if (query(q)) {
            t = q;
            return true;
        }
        return false;
    };

    while (t.length() < n) {
        if (!check(t + '0') && !check(t + '1'))
            break;
    }
    while (t.length() < n) {
        if (!check('0' + t))
            t = '1' + t;
    }

    answer(t);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
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
