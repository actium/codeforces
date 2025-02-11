#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& w)
{
    w.pop_back();
    w.pop_back();
    w.push_back('i');

    answer(w);
}

void test_case()
{
    std::string w;
    std::cin >> w;

    solve(w);
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
