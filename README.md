Môn: Cấu trúc dữ liệu và giải thuật (DSA)
Năm học: Học Kỳ 2 2025-2026
Họ và tên: Mạnh Trường Sơn
MSSV: 25120430
A.Thuật toán cài đặt tốt nhất lần 1:
1.Problem A: Integer Sort: Quick Sort kết hợp median of three
- Mô tả thuật toán:
+ Chọn pivot bằng median_of_three (left, mid, right)
+ Tách mảng thành 2 phần theo pivot (1 phần <=pivot và 1 phần >pivot) 
+ Đệ quy 2 nửa
- Vì sao đúng:
+ Bước Partition làm cho pivot được đặt đúng vị trí của nó trong mảng (tức là nếu mảng đã được sắp xếp thì nếu vị trí vốn có của nó là k thì sau Partition sẽ đặt nó đúng vị trí đó)
+ Chia bài toán thành 2 bài toán nhỏ và đệ quy 2 phần bên trái và phải
-> Đúng
- Vì sao chọn:
+ Dễ thiết lập
+ Độ phức tạp thấp, chạy nhanh (nlogn do có sử dụng median of three trừ những test anti Quick Sort tạo nhiều pivot xấu)
+ Ít tốn hoặc gần như không tốn bộ nhớ thêm
2.Problem B: Quick Sort kết hợp median of three
- Mô tả thuật toán:
+ Dùng Quick Sort để chia mảng
+ Chọn pivot bằng median_of_three (left, mid, right)
+ Partition mảng theo pivot
+ Đệ quy 2 nửa
- Vì sao chọn:
+ Dễ thiết lập
+ Hoạt động cả đối với string
+ Độ phức tạp thấp, chạy nhanh (nlogn do có sử dụng median of three trừ những test anti Quick Sort tạo nhiều pivot xấu)
+ Ít tốn hoặc gần như không tốn bộ nhớ thêm
3.Problem C: Quick Sort kết hợp hàm cmp để so sánh độ dài string và median of three
- Mô tả thuật toán:
+ 
