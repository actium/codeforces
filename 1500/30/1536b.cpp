#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    std::vector<std::string> q = { "" };
    for (size_t i = 0; i < q.size(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            const std::string t = q[i] + c;
            if (s.find(t) == std::string::npos)
                return answer(t);

            q.push_back(t);
        }
    }
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
