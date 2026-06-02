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
#### Chứng minh đúng:
+ Bước Partition làm cho pivot được đặt đúng vị trí của nó trong mảng (tức là nếu mảng đã được sắp xếp thì nếu vị trí vốn có của nó là k thì sau Partition sẽ đặt nó đúng vị trí đó)
+ Chia bài toán thành 2 bài toán nhỏ và đệ quy 2 phần bên trái và phải
-> Đúng
#### Điểm mạnh:
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
#### Điểm mạnh:
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
+ Dùng cmp để so sánh độ dài trước khi so sánh string
+ Hoạt động như QuickSort thông thường
#### Điểm mạnh:
+ Dễ thiết lập
+ Hoạt động cả đối với string
+ Độ phức tạp thấp, chạy nhanh (nlogn do có sử dụng median of three trừ những test anti QuickSort tạo nhiều pivot xấu)
+ Ít tốn hoặc gần như không tốn bộ nhớ thêm
#### Những điểm nhìn lại còn hạn chế:
- Chi phí so sánh string đắt đặc biệt nếu string có chung preflix
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
#### Chứng minh đúng:
- Các bước QuickSort hoặc HeapSort sẽ giúp mảng đạt được trạng thái gần sắp xếp ở nhiều vùng trên mảng
- Hoàn thiện bằng InsertionSort sẽ đảm bảo kết quả luôn đúng
#### Điểm mạnh:
- Tư duy dễ hiểu
- Độ phức tạp thấp, chạy nhanh (gần như đảm bảo là O(nlogn) do có HeapSort thay thế QuickSort nếu chọn pivot xấu)
- Có constant factor tốt hơn trong thực tế so với nhiều thuật toán O(n log n) khác
- Ít tốn hoặc gần như không tốn bộ nhớ thêm
- Tốt với dữ liệu nhiều duplicates so với các thuật toán khác
- Khi mảng đã gần được sắp xếp thì độ phức tạp gần như là O(n) vì các bước QuickSort lúc này gần như chỉ so sánh chứ không làm gì thêm còn bước cuối dùng InsertionSort sẽ chạy rất nhanh
#### Điểm yếu:
- Không stable
### Problem B: Lexicographic Sort
### Phương án Multikey QuickSort + fast I/O
#### Mô tả thuật toán:
- Dùng QuickSort có cải tiến 3-way partition để chia mảng thành 3 phần (< pivot , = pivot , > pivot)
- Pivot được xác định là số thứ tự của kí tự char trong bảng mã ASCII
- Khi chia mảng bằng swap làm việc với con trỏ thay vì trực tiếp swap 2 xâu
- Chọn pivot bằng median_of_three (left, mid, right) khi duyệt phạm vi ngắn hoặc ninther (bản mở rộng thành 9 phần tử) khi duyệt phạm vi dài hơn
- Tiếp tục lặp lại cho 2 đoạn < pivot và > pivot
- Đoạn = pivot sẽ lặp lại với pivot được lấy ở kí tự tiếp theo
- Khi phạm vi cần duyệt nhỏ thì sẽ dừng lại để cuối cùng chạy InsertionSort một lần cuối để cho ra mảng được sắp xếp
- Đọc và xuất dữ liệu trực tiếp từ buffer
#### Điểm mạnh:
- Độ phức tạp thấp, chạy nhanh (gần như đảm bảo là O(nlogn) do có HeapSort thay thế QuickSort nếu chọn pivot xấu)
- Có constant factor tốt hơn trong thực tế so với nhiều thuật toán O(n log n) khác
- InsertionSort so sánh từ vị trí depth giảm được nhiều chi phí
- Không tốn quá nhiều bộ nhớ như RadixSort
- Tốt với dữ liệu nhiều duplicates so với các thuật toán khác
- Tốt với mảng gần sắp xếp vì có dùng InsertionSort chạy cuối
- Cực tốt với entropy xuất hiện muộn so với các thuật toán khác
- Đọc và xuất dữ liệu nhanh hơn dùng cin và cout thông thường
#### Điểm yếu:
- Tốn bộ nhớ thêm do mảng buffer thường phải đặt lớn hơn mức sử dụng gây lãng phí
- Không stable
- Không hưởng lợi nhiều khi entropy xuất hiện sớm
### Problem C: Length-aware Lexicographic String Sort
### Phương án Introsort kết hợp hàm cmp để so sánh độ dài
#### Mô tả thuật toán:
- Dùng cmp để so sánh độ dài của xâu trước khi bắt đầu so sánh 2 xâu
- Dùng QuickSort có cải tiến 3-way partition để chia mảng thành 3 phần (< pivot , = pivot , > pivot)
- Pivot được xác định bằng median of three (không cần dùng ninther vì n không quá lớn)
- Khi chia mảng bằng swap làm việc với index thay vì trực tiếp swap 2 xâu
- Tiếp tục lặp lại cho 2 đoạn < pivot và > pivot (đoạn = pivot đã đúng vị trí hết rồi nên không cần quan tâm nữa)
- Khi phạm vi cần duyệt nhỏ thì sẽ dừng lại để cuối cùng chạy InsertionSort một lần cuối để cho ra mảng được sắp xếp
#### Điểm mạnh:
- Dễ thiết lập
- Độ phức tạp thấp, chạy nhanh (gần như đảm bảo là O(nlogn) do có HeapSort thay thế QuickSort nếu chọn pivot xấu)
- Có constant factor tốt hơn trong thực tế so với nhiều thuật toán O(n log n) khác
- Ít tốn hoặc gần như không tốn bộ nhớ thêm
- Tốt với test có các xâu khác độ dài nhau (vì so sánh bằng cmp rất rẻ chỉ O(1))
#### Điểm yếu:
- Không stable
- Yếu với test có long preflix + same length
 
