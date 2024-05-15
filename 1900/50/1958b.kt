fun answer(v:Int)
{
    println("${v}")
}

fun solve(k:Int, m:Int)
{
    answer(maxOf(2 * k - m % (3 * k), 0))
}

fun test_case()
{
    val (k, m) = readLine()!!.split(" ").map(String::toInt)
    solve(k, m)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
