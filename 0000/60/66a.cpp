#include <iostream>
#include <string>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const std::string& x)
{
    if (x.length() < 20) {
        const unsigned long long q = std::stoull(x);

        if (q < 128)
            return answer("byte");

        if (q < 32768)
            return answer("short");

        if (q < 2147483648ull)
            return answer("int");

        if (q < 9223372036854775808ull)
            return answer("long");
    }

    answer("BigInteger");
}

int main()
{
    std::string x;
    std::cin >> x;

    solve(x);

    return 0;
}

