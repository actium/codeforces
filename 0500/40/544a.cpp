#include <iostream>
#include <string>
#include <vector>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<std::string>& v)
{
    std::cout << "YES" << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(const std::string& q, size_t k)
{
    const size_t n = q.length();

    std::vector<std::string> s;
    for (size_t i = 0, v = 0; i < n; ++i) {
        const unsigned m = 1 << q[i] - 'a';
        if (s.size() < k && (v & m) == 0) {
            s.emplace_back();
            v |= m;
        }

        s.back().push_back(q[i]);
    }

    if (s.size() < k)
        return no_answer();

    answer(s);
}

int main()
{
    size_t k;
    std::cin >> k;

    std::string q;
    std::cin >> q;

    solve(q, k);

    return 0;
}

