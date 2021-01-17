#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << v.size() << '\n';

    for (const std::string x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, size_t p, size_t q)
{
    const size_t n = s.length();

    for (size_t i = 0; i <= n; i += p) {
        if ((n - i) % q == 0) {
            std::vector<std::string> t;

            for (size_t j = 0; j < i; j += p)
                t.push_back(s.substr(j, p));

            for (size_t j = i; j < n; j += q)
                t.push_back(s.substr(j, q));

            return answer(t);
        }
    }

    no_answer();
}

int main()
{
    size_t n, p, q;
    std::cin >> n >> p >> q;

    std::string s;
    std::cin >> s;

    solve(s, p, q);

    return 0;
}

