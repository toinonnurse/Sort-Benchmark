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
- Tốt với dữ liệu gần sắp xếp vì có sử dụng InsertionSort
- Tốt với duplicate do sử dụng 3-way partition
#### Điểm yếu:
- Không stable
- Yếu với test có long preflix + same length
## Phương án sinh test trong test_gen.cpp
### Problem A: Integer Sort
### Test 1: Mảng gần sắp xếp
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- Khi mảng gần được sắp xếp thì chọn pivot sẽ rất đẹp khiến mảng được chia đều đồng thời mỗi vòng lặp cũng ít cần swap vì thường thì phần tử bé hơn đã đúng trước phần tử lớn
- Bước cuối chạy InsertionSort sẽ rất nhanh (gần như là O(n))
### Test 2: Nhiều duplicates
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- 3-way partition giúp chia mảng thành 3 phần < pivot = pivot và > pivot vì thế trong 1 vòng lặp đã vừa làm được 2 chuyện là vừa QuickSort vừa trả pivot và các duplicates về đúng vị trí
- Các thuật toán khác không tận dụng được kiểu dữ liệu này sẽ bị bỏ phí hoặc thậm chí chạy chậm hơn thông thường
### Test 3: n nhỏ nhưng a[i] lại lớn nhỏ xen kẽ
#### Thuật toán bị nhắm tới để tăng thời gian chạy: RadixSort
- n nhỏ nhưng RadixSort không được hưởng lợi vì nó vẫn phải xét hết các chữ số dần dần trực tiếp làm chậm thuật toán
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- n nhỏ giúp thuật toán nhanh chóng chuyển sang bước cuối chạy InsertionSort
- Test này cũng vô tình tạo nhiều duplicates và nó cũng có lợi cho thuật toán của người thực hiện đồ án
### Test 4: Mảng gần sắp xếp + nhiều duplicates
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- Khi mảng gần được sắp xếp thì chọn pivot sẽ rất đẹp khiến mảng được chia đều đồng thời mỗi vòng lặp cũng ít cần swap vì thường thì phần tử bé hơn đã đúng trước phần tử lớn
- 3-way partition giúp chia mảng thành 3 phần < pivot = pivot và > pivot vì thế trong 1 vòng lặp đã vừa làm được 2 chuyện là vừa QuickSort vừa trả pivot và các duplicates về đúng vị trí
- Các thuật toán khác không tận dụng được kiểu dữ liệu này sẽ bị bỏ phí hoặc thậm chí chạy chậm hơn thông thường
- Bước cuối chạy InsertionSort sẽ rất nhanh (gần như là O(n))
### Test 5: Low entropy in high bits
#### Thuật toán bị nhắm tới để tăng thời gian chạy: RadixSort
- Ở các bit cao toàn bộ phần tử rơi vào đúng 1 bucket khiến nhiều pass gần như vô ích nhưng vẫn tốn thời gian copy memory.
### Problem B: Lexicographic Sort
Ở phần này tuy có 5 test khác nhau nhưng người thực hiện đồ án đều xây dựng chung 1 công thức là n = MAXN, nhiều xâu có chung long suffix và xâu rất dài. Mục đích là để tận dụng lợi thế của MKQ khi entropy xuất hiện muộn khiến phần lớn các thuật toán so sánh trực tiếp 2 xâu chạy rất chậm, riêng MSD RadixSort tuy tốc độ cũng ngang ngửa nhưng lại tốn bộ nhớ hơn MKQ. Bản thân MKQ tuy không được lợi với các test như thế này nhưng cũng không gặp bất lợi
### Problem C: Length-aware Lexicographic String Sort
### Test 1: Độ dài phân bố đều, entropy xuất hiện sớm
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- Độ dài phân bố đều giúp dễ tìm được pivot đẹp từ đó 3-way partition sẽ dễ xếp nó vào các nhóm có độ dài giống nhau + entropy xuất hiện sớm giúp so sánh 2 xâu tốn chi phí thấp
### Test 2: Nhiều duplicates
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- 3-way partition giúp chia mảng thành 3 phần < pivot = pivot và > pivot vì thế trong 1 vòng lặp đã vừa làm được 2 chuyện là vừa QuickSort vừa trả pivot và các duplicates về đúng vị trí
### Test 3: Suffix dài nhưng khác length
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- Vì các xâu đa phần là khác độ dài nhau nên so sánh dùng cmp sẽ rất nhanh chỉ O(1)
### Test 4: Mảng gần sắp xếp
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- Khi mảng gần được sắp xếp thì chọn pivot sẽ rất đẹp khiến mảng được chia đều đồng thời mỗi vòng lặp cũng ít cần swap vì thường thì phần tử bé hơn đã đúng trước phần tử lớn
- Bước cuối chạy InsertionSort sẽ rất nhanh (gần như là O(n))
### Test 5: Xâu ngẫu nhiên
#### Điểm có lợi cho thuật toán của người thực hiện đồ án:
- Kí tự ngẫu nhiên làm xác xuất xuất hiện entropy muộn là không cao
- Giúp so sánh xâu trở nên rẻ hơn
### Nhận xét:
Ở Problem C, thuật toán của người thực hiện đồ án không quá nổi trội so với các thuật toán khác. Có một số thuật toán nếu xây test case bất lợi cho nó thì còn tạo bất lợi cho bản thân nhiều hơn chính vì thế thay vì cố nhắm tới xây dựng test case để làm thuật toán khác chạy chậm thì người thực hiện đồ án quyết định xây dựng test case giúp thuật toán của người thực hiện đồ án chạy nhanh.
