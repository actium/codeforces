fun answer(x:String)
{
    println(x)
}

fun solve(s:String)
{
    answer(s.dropLastWhile { it == '0' }.dropLast(1))
}

fun test_case()
{
    val s = readLine()!!

    solve(s)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}
