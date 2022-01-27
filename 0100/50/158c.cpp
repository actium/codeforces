#include <iostream>
#include <string>
#include <vector>

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> d;;

    const auto cd = [&d](const std::string& x) {
        if (x != "..")
            d.push_back(x);
        else
            d.pop_back();
    };

    const auto pwd = [&d] {
        for (const std::string& x : d)
            std::cout << x << '/';

        std::cout << '\n';
    };

    for (cd({}); n-- > 0; ) {
        std::string x;
        std::cin >> x;

        if (x == "pwd") {
            pwd();
        } else {
            std::cin >> x;

            if (x.front() == '/')
                d.clear();

            for (size_t i = 0, n = x.length(); i < n; ) {
                const size_t k = x.find('/', i) - i;
                cd(x.substr(i, k));
                i += k + (k <= n);
            }
        }
    }

    return 0;
}
