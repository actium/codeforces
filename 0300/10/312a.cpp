#include <iostream>
#include <string>
#include <vector>

void solve(const std::vector<std::string>& s)
{
    for (const std::string& p : s) {
        const bool f = (p.rfind("lala.") == p.length() - 5);
        const bool r = (p.find("miao.") == 0);
        if (f == r) {
            std::cout << "OMG>.< I don't know!" << '\n';
        } else {
            std::cout << (f ? "Freda's" : "Rainbow's") << '\n';
        }
    }
}

int main()
{
    size_t n;
    std::cin >> n;
    std::cin.ignore();

    std::vector<std::string> s(n);
    for (size_t i = 0; i < n; ++i)
        std::getline(std::cin, s[i]);

    solve(s);

    return 0;
}

