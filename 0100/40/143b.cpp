#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string x)
{
    bool negative = false;
    if (x.front() == '-') {
        negative = true;
        x.erase(0, 1);
    }

    size_t p = x.find('.');
    if (p == std::string::npos) {
        p = x.length();
        x.push_back('.');
    }

    x.resize(p + 3, '0');

    for (size_t i = 3; i < p; i += 4, ++p)
        x.insert(p - i, 1, ',');

    x.insert(x.begin(), '$');

    if (negative) {
        x.insert(x.begin(), '(');
        x.insert(x.end(), ')');
    }

    answer(x);
}

int main()
{
    std::string x;
    std::cin >> x;

    solve(x);

    return 0;
}

