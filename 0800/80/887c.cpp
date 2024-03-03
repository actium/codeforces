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

void solve(const std::array<unsigned, 24>& a)
{
    constexpr const char* t[] = {
        "111155223333224466554466",
        "111144223333664422555566",
        "114422225533434315156666",
        "115522224433414135356666",
        "111122553333442255666644",
        "111122443333446655226655",
        "212132326363444455556161",
        "616112122323444455556363",
        "121223233636444455551616",
        "161621213232444455553636",
        "551122223344141453536666",
        "441122223355343451516666",
    };

    const auto check = [&](const char* p) {
        for (size_t i = 0; i < 24; ++i) {
            for (size_t j = 0; j < 24; ++j) {
                if ((p[i] == p[j]) != (a[i] == a[j]))
                    return false;
            }
        }
        return true;
    };

    for (const char* q : t) {
        if (check(q))
            return answer(true);
    }

    answer(false);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::array<unsigned, 24> a;
    std::cin >> a;

    solve(a);

    return 0;
}
