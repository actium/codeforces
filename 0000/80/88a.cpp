#include <algorithm>
#include <array>
#include <iostream>
#include <string>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(std::array<std::string, 3>& s)
{
    constexpr const char* n[12] = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"
    };

    const auto x = [&](const std::string& a) {
        size_t i = 0;
        while (n[i] != a)
            ++i;

        return i;
    };

    std::sort(s.begin(), s.end());

    do {
        const size_t a = x(s[0]), b = x(s[1]), c = x(s[2]);

        if (b == (a + 4) % 12 && c == (b + 3) % 12)
            return answer("major");

        if (b == (a + 3) % 12 && c == (b + 4) % 12)
            return answer("minor");
    } while (std::next_permutation(s.begin(), s.end()));

    answer("strange");
}

int main()
{
    std::array<std::string, 3> s;
    std::cin >> s;

    solve(s);

    return 0;
}

