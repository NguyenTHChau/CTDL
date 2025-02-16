from collections import deque

# Các bước di chuyển hợp lệ của quân mã
moves = [
    (-2, -1), (-2, 1), (2, -1), (2, 1),
    (-1, -2), (-1, 2), (1, -2), (1, 2)
]

def knight_moves(start, end):
    # Chuyển đổi vị trí từ "a1" -> (x, y)
    def to_index(pos):
        return ord(pos[0]) - ord('a'), int(pos[1]) - 1

    sx, sy = to_index(start)
    ex, ey = to_index(end)

    if (sx, sy) == (ex, ey):
        return 0

    queue = deque([(sx, sy, 0)])  # (x, y, bước đi)
    visited = set()
    visited.add((sx, sy))

    while queue:
        x, y, steps = queue.popleft()

        for dx, dy in moves:
            nx, ny = x + dx, y + dy

            if 0 <= nx < 8 and 0 <= ny < 8 and (nx, ny) not in visited:
                if (nx, ny) == (ex, ey):
                    return steps + 1
                queue.append((nx, ny, steps + 1))
                visited.add((nx, ny))

    return -1  # Không thể xảy ra trên bàn cờ 8×8

# Đọc input và xử lý
T = int(input())
for _ in range(T):
    start, end = input().split()
    print(knight_moves(start, end))
