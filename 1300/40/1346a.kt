fun answer(n1:Int, n2:Int, n3:Int, n4:Int)
{
    println("${n1} ${n2} ${n3} ${n4}")
}

fun solve(n:Int, k:Int)
{
    val n1 = n / (1 + k + k * k + k * k * k)
    val n2 = n1 * k
    val n3 = n2 * k
    val n4 = n3 * k

    answer(n1, n2, n3, n4)
}

fun test_case()
{
    val (n, k) = readLine()!!.split(" ").map(String::toInt)
    solve(n, k)
}

fun main()
{
    var t = readLine()!!.toInt()
    repeat (t) {
        test_case()
    }
}

