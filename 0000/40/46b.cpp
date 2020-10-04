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

size_t index(const std::string& s)
{
    if (s == "S") return 0;
    if (s == "M") return 1;
    if (s == "L") return 2;
    if (s == "XL") return 3;
    return 4;   // "XXL"
}

void answer(size_t v)
{
    constexpr const char* s[5] = { "S", "M", "L", "XL", "XXL" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<unsigned>& n, const std::vector<std::string>& s)
{
    constexpr size_t priorities[5][5] = {
        { 0, 1, 2, 3, 4 },
        { 1, 2, 0, 3, 4 },
        { 2, 3, 1, 4, 0 },
        { 3, 4, 2, 1, 0 },
        { 4, 3, 2, 1, 0 },
    };

    for (const std::string& q : s) {
        for (const size_t p : priorities[index(q)]) {
            if (n[p] > 0) {
                answer(p);
                --n[p];
                break;
            }
        }
    }
}

int main()
{
    std::vector<unsigned> n(5);
    std::cin >> n;

    size_t k;
    std::cin >> k;

    std::vector<std::string> s(k);
    std::cin >> s;

    solve(n, s);

    return 0;
}

