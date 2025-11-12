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

void encode(const std::vector<unsigned>& a)
{
    std::string s;
    for (const unsigned x : a)
        s.push_back('a' + x - 1);

    std::cout << s << '\n';
}

void decode(const std::string& s)
{
    std::cout << s.size() << '\n';

    const char* separator = "";
    for (const char c : s) {
        std::cout << separator << (c - 'a' + 1);
        separator = " ";
    }
    std::cout << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string mode;
    std::cin >> mode;

    if (mode == "first") {
        size_t n;
        std::cin >> n;

        std::vector<unsigned> a(n);
        std::cin >> a;

        encode(a);
    } else {
        std::string s;
        std::cin >> s;

        decode(s);
    }

    return 0;
}
