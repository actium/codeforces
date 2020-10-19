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

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::vector<char>& c)
{
    bool p[256] = {};
    for (const char x : c)
        p[x] = true;

    unsigned long long k = 0, l = 0;
    for (const char x : s) {
        if (!p[x]) {
            k += l * (l + 1) / 2;
            l = 0;
        } else {
            ++l;
        }
    }

    answer(k + l * (l + 1) / 2);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<char> c(k);
    std::cin >> c;

    solve(s, c);

    return 0;
}

