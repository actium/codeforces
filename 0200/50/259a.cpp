#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<std::string, 8>& b)
{
    const std::string x = "WBWBWBWB";
    const std::string y = "BWBWBWBW";

    for (const std::string& s : b) {
        if (s != x && s != y)
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::array<std::string, 8> b;
    std::cin >> b;

    solve(b);

    return 0;
}

