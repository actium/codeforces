fun answer(x:Int)
{
    println("${x}")
}

fun solve(x:Int, y:Int)
{
    var c:Int = y % x

    var z:Int = y / x
    while (z != 0) {
        c += z % 10
        z /= 10
    }

    answer(c)
}

fun test_case()
{
    val (x, y) = readLine()!!.split(" ").map(String::toInt)

    solve(x, y)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
