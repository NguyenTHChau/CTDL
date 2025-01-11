import torch

# Giả sử bạn có một mô hình và dữ liệu đầu vào
model = ...  # Xây dựng mô hình
optimizer = torch.optim.SGD(model.parameters(), lr=0.01)
criterion = torch.nn.CrossEntropyLoss()

epsilon = 1e-5  # Ngưỡng dừng sớm

for epoch in range(1000):
    # Tính toán loss và gradient
    inputs, targets = ...  # Dữ liệu đầu vào và nhãn
    optimizer.zero_grad()
    outputs = model(inputs)
    loss = criterion(outputs, targets)
    loss.backward()

    # Kiểm tra điều kiện dừng sớm
    total_gradient = 0
    for param in model.parameters():
        total_gradient += torch.sum(param.grad ** 2).item()

    if total_gradient < epsilon:
        print(f'Dừng sớm tại epoch {epoch}')
        break

    optimizer.step()
