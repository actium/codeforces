#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

bool alcoholic(const std::string& d)
{
    return d == "ABSINTH" || d == "BEER" || d == "BRANDY" || d == "CHAMPAGNE"
        || d == "GIN" || d == "RUM" || d == "SAKE" || d == "TEQUILA" || d == "VODKA"
        || d == "WHISKEY" || d == "WINE";
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& c)
{
    unsigned k = 0;
    for (const std::string& x : c) {
        if (isalpha(x.front()))
            k += alcoholic(x);
        else
            k += (std::stoi(x) < 18);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}

