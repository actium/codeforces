fun answer(v:Int)
{
    println("${v}")
}

fun solve(a:Int, x:Int, y:Int)
{
    if (x < 0 || y < 0 || x > a || y > a)
        return answer(2)

    if (x > 0 && x < a && y > 0 && y < a)
        return answer(0)

    answer(1)
}

fun main()
{
    val (a, x, y) = readLine()!!.split(" ").map(String::toInt)

    solve(a, x, y)
}

