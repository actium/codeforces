#include <iostream>
#include <set>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& p)
{
    unsigned t = 0;

    std::set<std::string> r;
    for (const std::string& c : p) {
        if (c.front() == '+') {
            r.insert(c.substr(1));
            continue;
        }
        if (c.front() == '-') {
            r.erase(c.substr(1));
            continue;
        }

        const size_t m = c.find(':') + 1;
        t += (c.length() - m) * r.size();
    }

    answer(t);
}

int main()
{
    std::vector<std::string> p;
    for (std::string c; std::getline(std::cin, c); p.push_back(c));

    solve(p);

    return 0;
}

