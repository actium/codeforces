fun answer(v:Long)
{
    println("${v}")
}

fun solve(n:Long, k:Long)
{
    answer(n - k.countTrailingZeroBits())
}

fun test_case()
{
    val (n, k) = readLine()!!.split(" ").map(String::toLong)
    solve(n, k)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
