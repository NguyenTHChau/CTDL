using DataStructures

struct Stack
    elements::Deque{Any}  # Sử dụng Deque để lưu trữ phần tử
end

Stack() = Stack(Deque{Any}())  # Constructor khởi tạo ngăn xếp rỗng

# Hàm thêm phần tử vào ngăn xếp
function push!(s::Stack, item)
    push!(s.elements, item)  # Thêm phần tử vào cuối deque
    println("Da them $item vao ngan xep")
end

# Hàm loại bỏ phần tử khỏi ngăn xếp
function pop!(s::Stack)
    if !isempty(s.elements)
        item = pop!(s.elements)  # Loại bỏ phần tử từ cuối deque
        println("Da lay $item ra khoi ngan xep")
        return item
    else
        println("Ngan xep trong")
        return nothing
    end
end

# Hàm xem phần tử ở đỉnh ngăn xếp
function peek(s::Stack)
    if !isempty(s.elements)
        return last(s.elements)  # Lấy phần tử ở đỉnh mà không loại bỏ
    else
        println("Ngan xep trong")
        return nothing
    end
end

# Hàm kiểm tra ngăn xếp có trống không
function is_empty(s::Stack)
    return isempty(s.elements)  # Kiểm tra xem ngăn xếp có trống không
end

# Hàm hiển thị ngăn xếp
function display(s::Stack)
    println("Ngan xep dinh den day: ", collect(reverse(s.elements)))  # In ngăn xếp từ đỉnh đến đáy
end

# Minh họa sử dụng ngăn xếp
function main()
    stack = Stack()
    push!(stack, "Sach A")
    push!(stack, "Sach B")
    push!(stack, "Sach C")
    display(stack)  # Hiển thị ngăn xếp
    top_item = peek(stack)
    println("Phan tu o dinh ngan xep: ", top_item)  # Xuất phần tử ở đỉnh
    pop!(stack)
    display(stack)  # Hiển thị ngăn xếp sau khi pop
    println("Ngan xep co trong khong ", is_empty(stack) ? "Co" : "Khong")  # Kiểm tra trống
end

main()  # Gọi hàm main để chạy chương trình
