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

std::vector<std::string> parse(const std::string& s)
{
    std::vector<std::string> p(1);
    for (const char c : s) {
        if (!p.back().empty() && isdigit(p.back().back()) != isdigit(c))
            p.emplace_back();

        p.back().push_back(c);
    }

    return p;
}

unsigned convert(const std::string& s)
{
    unsigned v = 0;
    for (const char c : s)
        v = v * 26 + (c - 'A' + 1);

    return v;
}

std::string convert(unsigned v)
{
    std::string r;
    do {
        r.push_back('A' + (v - 1) % 26);
        v = (v - 1) / 26;
    } while (v != 0);

    return std::string(r.rbegin(), r.rend());
}

void solve(const std::vector<std::string>& a)
{
    for (const std::string& q : a) {
        const std::vector<std::string> p = parse(q);

        if (p.size() == 2) {
            std::cout << 'R' << p[1] << 'C' << convert(p[0]) << '\n';
        } else {
            std::cout << convert(std::stoi(p[3])) << p[1] << '\n';
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
