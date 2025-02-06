import Base: push!, pop!  # Import cả hai phương thức
mutable struct Stack  
    elements::Vector{Any}  
end  

function Stack()  
    return Stack(Vector{Any}())  
end  

function push!(s::Stack, item)  
    push!(s.elements, item)  
    println("Đã thêm '$item' vào ngăn xếp.")  
end  

function pop!(s::Stack)  
    if !isempty(s.elements)  
        return pop!(s.elements)  
    else  
        println("Ngăn xếp trống!")  
        return nothing  
    end  
end  

function peek(s::Stack)  
    if !isempty(s.elements)  
        return last(s.elements)  
    else  
        println("Ngăn xếp trống!")  
        return nothing  
    end  
end  

function is_empty(s::Stack)  
    return isempty(s.elements)  
end  

function display(s::Stack)  
    println("Ngăn xếp (đỉnh đến đáy): ", reverse(s.elements))  
end  

# Minh họa sử dụng ngăn xếp  
function main()  
    stack = Stack()  
    push!(stack, "Sách A")  
    push!(stack, "Sách B")  
    push!(stack, "Sách C")  
    display(stack)  
    top_item = peek(stack)  
    println("Phần tử ở đỉnh ngăn xếp: ", top_item)  
    pop!(stack)  
    display(stack)  
    println("Ngăn xếp có trống không? ", is_empty(stack) ? "Có" : "Không")  
end  

main()