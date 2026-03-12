fun answer(x:Int)
{
    println("${x}")
}

fun solve(a:Int, b:Int, c:Int, d:Int)
{
    val uc = minOf(c, d)
    val lc = minOf(maxOf(a, b), uc)

    answer(lc - a + lc - b + uc - lc + c - uc + d - uc)
}

fun test_case()
{
    val (a, b, c, d) = readLine()!!.split(" ").map(String::toInt)

    solve(a, b, c, d)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
