#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.size();

    std::vector<size_t> q;
    std::vector<bool> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '1' || s[i] == '3' || q.empty())
            q.push_back(i);

        if (s[i] == '2' || s[i] == '3') {
            v[q.back()] = true;
            q.pop_back();
        }
    }

    std::vector<unsigned> t;
    for (size_t i = 0; i < n; ++i) {
        if (!v[i])
            t.push_back(1 + i);
    }

    answer(t);
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
