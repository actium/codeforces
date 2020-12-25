#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& s : v)
        std::cout << s << '\n';
}

void solve(std::vector<std::string>& t)
{
    size_t k = 0, d = 0;
    for (const std::string& s : t)
        k = std::max(k, s.length());

    for (std::string& s : t) {
        const size_t n = s.length();
        if (n == 0) {
            s = '*' + std::string(k, ' ') + '*';
        } else {
            const size_t c = (k - n + d) / 2;
            s = '*' + std::string(c, ' ') + s + std::string(k - n - c, ' ') + '*';

            if (c != k - n - c)
                d ^= 1;
        }
    }

    t.insert(t.begin(), std::string(1+k+1, '*'));
    t.insert(t.end(), std::string(1+k+1, '*'));

    answer(t);
}

int main()
{
    std::vector<std::string> t;
    for (std::string x; std::getline(std::cin, x); t.push_back(x));

    solve(t);

    return 0;
}

