fun answer(v:String)
{
    println(v)
}

fun solve(n:Int, m:Int, p:Int)
{
    for (i in 1..n) {
        if (p % i == 0 && p / i <= m)
            return answer("Yes")
    }

    answer("No")
}

fun test_case()
{
    val (n, m, p) = readLine()!!.split(" ").map(String::toInt)

    solve(n, m, p)
}

fun main()
{
    var q = readLine()!!.toInt()
    repeat (q) {
        test_case()
    }
}
