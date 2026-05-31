- Môn: Cấu trúc dữ liệu và giải thuật (DSA)
- Năm học: Học Kỳ 2 2025-2026
- Họ và tên: Mạnh Trường Sơn
- MSSV: 25120430
# Đồ án Sort Benchmark
## Thuật toán cài đặt tốt nhất lần 1:
### Problem A: Integer Sort 
### Phương án QuickSort kết hợp median of three
#### Mô tả thuật toán:
+ Chọn pivot bằng median_of_three (left, mid, right)
+ Tách mảng thành 2 phần theo pivot (1 phần <= pivot và 1 phần > pivot) 
+ Đệ quy 2 nửa
#### Vì sao đúng:
+ Bước Partition làm cho pivot được đặt đúng vị trí của nó trong mảng (tức là nếu mảng đã được sắp xếp thì nếu vị trí vốn có của nó là k thì sau Partition sẽ đặt nó đúng vị trí đó)
+ Chia bài toán thành 2 bài toán nhỏ và đệ quy 2 phần bên trái và phải
-> Đúng
#### Vì sao chọn:
+ Dễ thiết lập
+ Độ phức tạp thấp, chạy nhanh (O(nlogn) do có sử dụng median of three trừ những test anti QuickSort tạo nhiều pivot xấu)
+ Ít tốn hoặc gần như không tốn bộ nhớ thêm
#### Những điểm nhìn lại còn hạn chế:
- Thuật toán median of three chọn pivot còn đơn giản có thể dễ dàng bị phá với nhiều test đặc thù
- Khi liên tục chọn pivot xấu không có phương án thay thế
- Khi mảng nhỏ hoặc gần sort chưa có phương án tối ưu O(n)
### Problem B: Lexicographic Sort
### Phương án QuickSort kết hợp median of three
#### Mô tả thuật toán:
+ Dùng QuickSort để chia mảng
+ Chọn pivot bằng median_of_three (left, mid, right)
+ Tách mảng thành 2 phần theo pivot (1 phần <= pivot và 1 phần > pivot) 
+ Đệ quy 2 nửa
#### Vì sao chọn:
+ Dễ thiết lập
+ Hoạt động cả đối với string
+ Độ phức tạp thấp, chạy nhanh (nlogn do có sử dụng median of three trừ những test anti QuickSort tạo nhiều pivot xấu)
+ Ít tốn hoặc gần như không tốn bộ nhớ thêm
#### Những điểm nhìn lại còn hạn chế:
- Chi phí so sánh string đắt đặc biệt nếu string có chung preflix
- Thuật toán median of three chọn pivot còn đơn giản có thể dễ dàng bị phá với nhiều test đặc thù
- Khi liên tục chọn pivot xấu không có phương án thay thế
- Khi mảng nhỏ hoặc gần sort chưa có phương án tối ưu O(n)
- Swap tốn chi phí đặc biệt khi string dài 
### Problem C: Length-aware Lexicographic String Sort
### Phương án QuickSort kết hợp hàm cmp để so sánh độ dài string và median of three
#### Mô tả thuật toán:
+ Hàm cmp được triển khai để so sánh độ dài trước khi so sánh string
+ Hoạt động như QuickSort thông thường
#### Vì sao chọn:
+ Dễ thiết lập
+ Hoạt động cả đối với string
+ Độ phức tạp thấp, chạy nhanh (nlogn do có sử dụng median of three trừ những test anti QuickSort tạo nhiều pivot xấu)
+ Ít tốn hoặc gần như không tốn bộ nhớ thêm
#### Những điểm nhìn lại còn hạn chế:
- Chi phí so sánh string đắt đặc biệt nếu string có chung preflix
- Thuật toán median of three chọn pivot còn đơn giản có thể dễ dàng bị phá với nhiều test đặc thù
- Khi liên tục chọn pivot xấu không có phương án thay thế
- Khi mảng nhỏ hoặc gần sort chưa có phương án tối ưu O(n)
- Swap tốn chi phí đặc biệt khi string dài
### Nhận xét của người thực hiện đồ án:
- Những thuật toán này được thiết lập tuy có kết quả không quá tệ và vẫn hoàn thành đúng yêu cầu đồ án nhưng em thừa nhận bản thân chưa có nhiều đầu tư thời gian để tìm hiểu và tìm ra phương án tốt hơn
## Thuật toán cài đặt tốt nhất lần 2:
### Problem A: Integer Sort 
### Phương án Introsort tự viết với 3-way partition
#### Mô tả thuật toán:
+ Dùng QuickSort có cải tiến 3-way partition để chia mảng thành 3 phần (< pivot , = pivot , > pivot)
+ Chọn pivot bằng median_of_three (left, mid, right) khi duyệt phạm vi ngắn hoặc ninther (bản mở rộng thành 9 phần tử) khi duyệt phạm vi dài hơn
+ Tiếp tục lặp lại cho 2 đoạn < pivot và > pivot (đoạn = pivot đã đúng vị trí hết rồi nên không cần quan tâm nữa)
+ Nếu QuickSort quá nhiều mà không hiệu quả thì chuyển sang HeapSort
+ Khi phạm vi cần duyệt nhỏ thì sẽ dừng lại để cuối cùng chạy InsertionSort một lần cuối để cho ra mảng được sắp xếp
#### Vì sao đúng:
- Các bước QuickSort hoặc HeapSort để giúp mảng đạt được trạng thái gần sắp xếp ở nhiều vùng trên mảng
- Hoàn thiện bằng InsertionSort sẽ đảm bảo kết quả luôn đúng
#### Vì sao chọn:
- Tư duy dễ hiểu
- Độ phức tạp thấp, chạy nhanh (gần như đảm bảo là O(nlogn) do có HeapSort thay thế QuickSort nếu chọn pivot xấu)
- Có constant factor tốt hơn trong thực tế so với nhiều thuật toán O(n log n) khác
- Ít tốn hoặc gần như không tốn bộ nhớ thêm
- Tốt với dữ liệu nhiều duplicates so với các thuật toán khác
- Khi mảng đã gần được sắp xếp thì độ phức tạp gần như là O(n) vì các bước QuickSort lúc này gần như chỉ so sánh chứ không làm gì thêm còn bước cuối dùng InsertionSort sẽ chạy rất nhanh
#### Những điểm còn hạn chế của thuật toán:
- Không stable
### Problem B: Lexicographic Sort
### Phương án Multikey QuickSort + fast I/O
#### Mô tả thuật toán:
- Dùng QuickSort có cải tiến 3-way partition để chia mảng thành 3 phần (< pivot , = pivot , > pivot)
- Khi chia mảng bằng swap làm việc với con trỏ thay vì trực tiếp swap 2 xâu
- Pivot được xác định là số thứ tự của kí tự char trong bảng mã ASCII
- Chọn pivot bằng median_of_three (left, mid, right) khi duyệt phạm vi ngắn hoặc ninther (bản mở rộng thành 9 phần tử) khi duyệt phạm vi dài hơn
- Tiếp tục lặp lại cho 2 đoạn < pivot và > pivot
- Đoạn = pivot sẽ lặp lại với pivot được lấy ở kí tự tiếp theo
- Khi phạm vi cần duyệt nhỏ thì sẽ dừng lại để cuối cùng chạy InsertionSort một lần cuối để cho ra mảng được sắp xếp
- Đọc và xuất dữ liệu trực tiếp từ buffer
#### Vì sao chọn:
- 
 
