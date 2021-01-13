#include <iostream>
#include <string>
#include <vector>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, const std::vector<std::string>& s)
{
    unsigned lb = 1, ub = n;

    for (const std::string& q : s) {
        if (q[7] == 'r') {
            const unsigned x = std::stoi(q.substr(16));
            lb = std::max(lb, x + 1);
        } else {
            const unsigned x = std::stoi(q.substr(15));
            ub = std::min(ub, x - 1);
        }
    }

    if (lb > ub)
        return no_answer();

    answer(ub - lb + 1);
}

int main()
{
    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;
    std::cin.ignore();

    std::vector<std::string> s(m);
    for (std::string& q : s)
        std::getline(std::cin, q);

    solve(n, s);

    return 0;
}

