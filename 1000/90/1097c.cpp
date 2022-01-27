#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    std::map<int, unsigned> x;

    const auto count = [&x](int b) {
        if (x[b] == 0) {
            ++x[-b];
            return 0;
        }
        --x[b];
        return 1;
    };

    unsigned k = 0;
    for (const std::string& t : s) {
        unsigned d = 0;

        std::string a;
        for (const char c : t) {
            if (c == '(') {
                a.push_back(c);
            } else if (a.empty()) {
                ++d;
            } else {
                a.pop_back();
            }
        }

        if (d != 0 && a.empty())
            k += count(d);

        if (d == 0 && !a.empty())
            k += count(-a.size());

        if (d == 0 && a.empty())
            k += count(0);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
