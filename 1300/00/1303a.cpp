#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t left = s.find('1');
    if (left == std::string::npos)
        return answer(0);

    size_t count = 0;
    for (size_t right = s.rfind('1'); left < right; ++left) {
        if (s[left] == '0')
            ++count;
    }

    answer(count);
}

void test_case()
{
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

