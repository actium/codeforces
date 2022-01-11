#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a)
{
    std::string b;
    for (const char c : a) {
        switch (c) {
            case '4':
                b += "322";
                break;
            case '6':
                b += "53";
                break;
            case '8':
                b += "7222";
                break;
            case '9':
                b += "7332";
                break;
            default:
                if (c != '0' && c != '1')
                    b.push_back(c);
        }
    }

    std::sort(b.begin(), b.end(), std::greater<char>());

    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    solve(a);

    return 0;
}
