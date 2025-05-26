#include <iostream>
#include <string>
#include <vector>

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.size();

    std::vector<size_t> x[2];
    for (size_t i = 0; i < n; ++i)
        x[s[i]-'A'].push_back(i);

    const auto check = [&](size_t a) {
        if (a == 0)
            return x[1].front() == n-1;

        if (a == n-1)
            return x[1].front() != 0;

        for (const size_t b : x[1]) {
            if (b > a)
                return false;
        }
        return true;
    };

    for (const size_t a : x[0]) {
        if (check(a))
            return answer("Alice");
    }

    answer("Bob");
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
