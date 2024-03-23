#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a)
{
    std::string b;

    auto it = a.begin(), jt = a.begin();
    while (it != a.end() && jt != a.end()) {
        if (*it % 2 == 1) {
            ++it;
            continue;
        }
        if (*jt % 2 == 0) {
            ++jt;
            continue;
        }
        b.push_back(*it < *jt ? *it++ : *jt++);
    }
    for ( ; it != a.end(); ++it) {
        if (*it % 2 == 0)
            b.push_back(*it);
    }
    for ( ; jt != a.end(); ++jt) {
        if (*jt % 2 == 1)
            b.push_back(*jt);
    }

    answer(b);
}

void test_case()
{
    std::string a;
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
