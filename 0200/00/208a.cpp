#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& remix)
{
    const size_t n = remix.length();

    std::string original;
    for (size_t i = 0; i < n; ) {
        const size_t wub = remix.find("WUB", i);
        if (wub == i) {
            i += 3;
            continue;
        }

        if (!original.empty())
            original.push_back(' ');

        if (wub == std::string::npos) {
            original += remix.substr(i, n - i);
            i = n;
        } else {
            original += remix.substr(i, wub - i);
            i = wub + 3;
        }
    }

    answer(original);
}

int main()
{
    std::string remix;
    std::cin >> remix;

    solve(remix);

    return 0;
}

