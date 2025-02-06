function decimal_to_binary(n)
    stack = Int[]
    println("Chuyen doi so thap phan: $n sang nhi phan.")
    
    if n == 0
        push!(stack, 0)
        println("Da them phan du '0' vao ngan xep.")
    end

    while n > 0
        remainder = n % 2
        push!(stack, remainder)
        println("Chia $n cho 2, phan du: $remainder → Da them $remainder vao ngan xep.")
        n = div(n, 2)
        println("Thuong moi: $n")
    end

    binary = ""
    println("Chuyen doi ngan xep thanh so nhi phan:")
    while !isempty(stack)
        push!(binary, string(pop!(stack)))
        println("Lay $(last(binary)) tu ngan xep va noi vao ket qua.")
    end

    return join(reverse(binary))
end

# Minh họa
number = 13
binary = decimal_to_binary(number)
println("So thap phan $number chuyen sang nhi phan la $binary")  # Output: 1101
