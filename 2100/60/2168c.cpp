#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void set_control_bits(unsigned& m)
{
    for (unsigned i = 1; i <= 20; ++i) {
        if (__builtin_popcount(i) == 1 || (m & 1 << i) == 0)
            continue;

        for (unsigned j = i; j != 0; j &= j-1) {
            const unsigned p = 1 << __builtin_ctz(j);
            m ^= 1 << p;
        }
    }
}

void encode(unsigned x)
{
    --x;

    unsigned m = (x & 0x1) << 3 | (x & 0xE) << 4 | (x & 0x7F0) << 5 | (x & 0x7800) << 6;

    set_control_bits(m);

    std::cout << __builtin_popcount(m) << '\n';

    const char* separator = "";
    while (m != 0) {
        std::cout << separator << __builtin_ctz(m);
        separator = " ";
        m &= m-1;
    }
    std::cout << '\n';
}

void decode(const std::vector<unsigned>& s)
{
    unsigned m = 0;
    for (const unsigned x : s)
        m |= 1 << x;

    set_control_bits(m);

    unsigned p = 0;
    for (unsigned i = 1; i < 20; i <<= 1) {
        if ((m & 1 << i) != 0)
            p += i;
    }

    if (p != 0)
        m ^= 1 << p;

    std::cout << (m >> 6 & 0x7800 | m >> 5 & 0x7F0 | m >> 4 & 0xE | m >> 3 & 0x1) + 1 << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string mode;
    std::cin >> mode;

    size_t t;
    std::cin >> t;

    while (t-- > 0) {
        if (mode == "first") {
            unsigned x;
            std::cin >> x;

            encode(x);
        } else {
            size_t n;
            std::cin >> n;

            std::vector<unsigned> s(n);
            std::cin >> s;

            decode(s);
        }
    }

    return 0;
}
