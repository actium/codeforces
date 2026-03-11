fun answer(x:Boolean)
{
    println(if (x) "YES" else "NO")
}

fun solve(a1:Int, b1:Int, a2:Int, b2:Int, k:Int)
{
    answer(a1 + a2 < b1 + b2 + k)
}

fun test_case()
{
    val k = readLine()!!.toInt()
    val (a1, b1) = readLine()!!.split(" ").map(String::toInt)
    val (a2, b2) = readLine()!!.split(" ").map(String::toInt)

    solve(a1, b1, a2, b2, k)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
