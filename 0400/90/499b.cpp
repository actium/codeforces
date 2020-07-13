#include <iostream>
#include <map>
#include <string>

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::map<std::string, std::string> x;
    for (size_t i = 0; i < m; ++i) {
        std::string a, b;
        std::cin >> a >> b;
        x.emplace(a, b);
    }

    const char* separator = "";
    for (size_t i = 0; i < n; ++i) {
        std::string c;
        std::cin >> c;

        const std::string& t = x[c];
        std::cout << separator << (c.length() <= t.length() ? c : t);

        separator = " ";
    }
    std::cout << '\n';

    return 0;
}

