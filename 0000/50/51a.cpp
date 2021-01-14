#include <iostream>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& a)
{
    std::vector<std::string> s;

    const auto check = [&s](const std::string& q) {
        for (size_t i = 0; i < 4; ++i) {
            const std::string x = q.substr(i) + q.substr(0, i);

            for (const std::string& y : s) {
                if (y == x)
                    return true;
            }
        }
        return false;
    };

    for (const std::string& x : a) {
        if (!check(x))
            s.push_back(x);
    }

    answer(s.size());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];

        std::string b;
        std::cin >> b;
        a[i].push_back(b.back());
        a[i].push_back(b.front());
        std::cin >> b;
    }

    solve(a);

    return 0;
}

