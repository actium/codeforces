#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::string& s)
{
    std::vector<size_t> p;
    for (const std::string& t : { "twone", "one", "two" }) {
        const size_t k = t.length();

        for (size_t x = 0; x = s.find(t, x), x != std::string::npos; x += k) {
            s[x + k / 2] = ' ';
            p.push_back(x + k / 2);
        }
    }

    answer(p);
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
