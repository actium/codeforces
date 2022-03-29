#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned k = 0;
    for (size_t i = s.find('0'); i != std::string::npos; ) {
        const size_t j = s.find('0', i + 1);
        if (j != std::string::npos && j - i < 3)
            k += 3 - (j - i);

        i = j;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
