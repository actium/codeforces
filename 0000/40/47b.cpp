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

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::array<std::string, 3>& e)
{
    size_t p[3] = {};
    for (const auto& q : e) {
        if (q[1] == '>')
            ++p[q[0] - 'A'];
        else
            ++p[q[2] - 'A'];
    }

    std::string s = "   ";
    for (size_t i = 0; i < 3; ++i) {
        const size_t x = p[i];
        if (s[x] != ' ')
            return answer("Impossible");

        s[x] = 'A' + i;
    }

    answer(s);
}

int main()
{
    std::array<std::string, 3> e;
    std::cin >> e;

    solve(e);

    return 0;
}

