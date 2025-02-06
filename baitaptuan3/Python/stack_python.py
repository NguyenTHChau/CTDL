class Stack:  
    def __init__(self):  
        self.elements = []  

    def push(self, item):  
        self.elements.append(item)  
        print(f"Đã thêm '{item}' vào ngăn xếp.")  

    def pop(self):  
        if not self.is_empty():  
            item = self.elements.pop()  
            print(f"Đã lấy '{item}' ra khỏi ngăn xếp.")  
            return item  
        else:  
            print("Ngăn xếp trống!")  
            return None  

    def peek(self):  
        if not self.is_empty():  
            return self.elements[-1]  
        else:  
            return None  

    def is_empty(self):  
        return len(self.elements) == 0  

    def size(self):  
        return len(self.elements)  

    def display(self):  
        print("Ngăn xếp (đỉnh đến đáy):", self.elements[::-1])  

# Minh họa sử dụng ngăn xếp  
if __name__ == "__main__":  
    stack = Stack()  
    stack.push("Sách A")  
    stack.push("Sách B")  
    stack.push("Sách C")  
    stack.display()  
    top_item = stack.peek()  
    print("Phần tử ở đỉnh ngăn xếp:", top_item)  
    stack.pop()  
    stack.display()  
    print("Ngăn xếp có trống không?", stack.is_empty())