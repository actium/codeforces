fun answer(x:Int)
{
    println("${x}")
}

fun solve(a:Int, va:Int, c:Int, vc:Int, b:Int)
{
    answer(va + (vc - va) * (b - a) / (c - a))
}

fun test_case()
{
    val n = readLine()!!.toInt()

    val (a, va) = readLine()!!.split(" ").map(String::toInt)
    val (c, vc) = readLine()!!.split(" ").map(String::toInt)
    val b = readLine()!!.toInt()

    solve(a, va, c, vc, b)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
