#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a)
{
    std::string b(a.rbegin(), a.rend());
    for (char& c : b) {
        if (c != 'w')
            c = (c == 'p' ? 'q' : 'p');
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
