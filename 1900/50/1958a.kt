fun answer(v:Int)
{
    println("${v}")
}

fun solve(n:Int)
{
    answer(if (n < 8) minOf(n % 3, n % 5) else 0)
}

fun test_case()
{
    val n = readLine()!!.toInt()
    solve(n)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
