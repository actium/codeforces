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
    for (unsigned x : a) {
        for (unsigned i = 0; i < 7; ++i) {
            s.push_back('a' + x % 26);
            x /= 26;
        }
    }

    std::cout << s << '\n';
}

void decode(const std::string& s)
{
    const size_t n = s.length() / 7;

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 6; ~j != 0; --j)
            a[i] = a[i] * 26 + (s[7 * i + j] - 'a');
    }

    std::cout << n << '\n';

    const char* separator = "";
    for (const unsigned x : a) {
        std::cout << separator << x;
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
