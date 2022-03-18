-- mục tiêu quan trọng nhất khi học môn này từ một bài toán thực tế
-- mọi người phân tích dữ liệu và tạo cơ sở dữ liệu
-- với lượng thông tin đấy mình sẽ tạo bao nhiêu bảng(đưa table về dạng chuẩn 3 là đủ)
-- là đủ và mối quan hệ giữ các
-- bảng là gì(1-1, 1-n, n-n)

/* unique(dữ liệu của trường không được phép trùng, trong một bảng có thể có nhiều khóa phụ
vd: số điện thoại, email(tại sao không dùng cái này làm khóa chính)
- check ràng buộc về miền giá trị của một trường (vd tuổi lớn hơn 0, điểm < 10 && >0
tên sinh viên phải lớn hơn 10 ký tự
- not null dữ liệu của trường đấy không đc phép null
- default mặc nhiên khi một dòng đc nhập mà cái cột đó không chèn dữ liệu nó sẽ nhận 
giá trị default, mình có thẻ sét lại giá trị default cho trường dữ liệu mặc định của
database engine là null


--- Khóa Ngoài(Nó là khóa chính của bảng khác(là khóa chính đi xuất ngoại))
giúp liên kết các bảng với nhau 
) 
*/
USE QLBanHang

SELECT * FROM SanPham
select * from CongTy
SELECT * FROM CungUng;

INSERT INTO CungUng VALUES ('SP02', 'CT09', 10)
-- thêm ràng buộc khóa ngoại cho bảng cung ứng
ALTER TABLE CungUng ADD CONSTRAINT FK________
FOREIGN KEY([Mã Sản Phẩm]) REFERENCES SanPham([Mã Sản Phẩm])
/*
vd : Nhu cầu thống kê xem các công ty cung bao nhiêu sản phẩm
-- Để công ty cung ứng sản phẩm ra ngoài thị trường thì hiển nhiên công tý đó
phải tồn tại
=> Lúc này nếu mà trong bảng cung ứng không có ràng buộc (Khóa ngoại) thì dẫn đến
trường hợp(tình huống) không có tính nhất quán(inconsistence) về mặt dữ liệu

*/

CREATE DATABASE TestForeignKey

CREATE TABLE Student(
	StudentID int primary key,
	StudentName nvarchar(20),
	MajorID int foreign key references Major(MajorID)
)

CREATE TABLE StudentV1(
	StudentID int primary key,
	StudentName nvarchar(20),
	MarjorName nvarchar(20)
)



CREATE TABLE Major(
	MajorID int primary key,
	MarjorName nvarchar(20)
)

INSERT INTO StudentV1 VALUES -- (1, N'Nguyễn Văn e', 'Software engineer'),
--(2, N'Nguyễn Văn e', 'Software engineer'),
--(3, N'Nguyễn Văn e', 'Graphic Design'),
--(4, N'Nguyễn Văn e', 'Marketing'),
--(5, N'Nguyễn Văn e', 'Software engineer'),
(6, N'Nguyễn Văn e', 'Kỹ thuật phần mềm'),
(7, N'Nguyễn Văn e', 'KTPM')

INSERT INTO Student VALUES  (5, N'Nguyễn Văn e', 1),
							--(2, N'Nguyễn Văn B', 1),
							--(3, N'Nguyễn Văn C', 2),
							--(4, N'Nguyễn Văn D', 2)

INSERT INTO Major VALUES(1, 'Software engineer'),
						(2, 'Graphic design')
SELECT * FROM Major
select * from StudentV1

-- cho biết trong trường có bao nhiêu sinh viên hoặc ngành kỹ thuật phần mềm
-- => không thể nào thống được số lượng sinh viên học ngành se
-- => toi -> không thể biết đc số sinh viên học se
-- => lúc này mình tách dữ liệu trong bảng ra
-- Tách như nào là hợp lý
-- Khi thông tin của một trường dữ liệu là một trường xác định theo một quy tắc
-- nhất định không được phép nhập một cách tùy tiện mà nó phải theo một quy định
-- hay ràng buộc thống nhất để đảm bảo được tính nhát quán của dữ liệu
-- giải pháp là tách trường tên chuyên ngành là một table khác
-- để đảm bảo đc tính nhất quán -- thống nhất của dữ liệu khi chèn, cập nhật, sửa

CREATE TABLE StudentV2(
	StudentID int primary key,
	StudentName nvarchar(20),
	MajorID char(5)
)
CREATE TABLE MajorV2(
	MajorID char(5) primary key,
	MajorName nvarchar(20)
)

DELETE FROM StudentV2 Where StudentID = 6
INSERT INTO StudentV2 VALUES  (6, N'Nguyễn Văn e', 'MK'),
								(2, N'Nguyễn Văn e', 'SE'),
								(3, N'Nguyễn Văn e', 'SE'),
								(4, N'Nguyễn Văn e', 'GD'),
								(5, N'Nguyễn Văn e', 'GD')
INSERT INTO MajorV2 VALUES('SE', 'Software Engineer'),
							('GD', 'Graphic Design'),
							('MK', 'Marketing')
-- sinh viên này a thấy học se khó quá tại vì code nhiều quá không hiểu đc
-- có nguyện vọng xin chuyển sang chuyên ngành khác vì không phù hợp
-- với se
-- Thì tạo cái đơn xin đổi chuyên ngành kiến nghị với nhà trường mong muốn của mình
-- Tạo ra cái đơn xin đổi chuyên ngành cho sinh viên a
UPDATE StudentV2 SET MajorID = 'KT' WHERE StudentID = 2
-- TRường mình thấy chuyên ngành SE khó quá sinh viên không theo được muốn xóa chuyên
-- ngành đó đi vì sinh viên không có ai đủ sức để lấy đc bằng ngành này => Xóa ngành se
DELETE FROM MajorV2 where MajorID = 'SE'
/*
Không thể nào xóa được vì chuyên nhành này vẫn còn sinh viên đang học(Học 7, 8 năm rồi 
không lấy nổi bằng) thì phải đợi cho nó học xong đã chứ
-- Nhưng học 7, 8 năm rồi thời gian lâu quá nhà trường không đợi được
-> Cần có một cái thỏa thuận giữa sinh viên và nhà trường để đưa ra một cách giải quyết hợp lý
-> Cần có một giải pháp ở đây
Trong tình huống xóa chuyên ngành đi thì những sinh viên đang còn học thì phải
+ Một là phải chuyển sang một chuyên ngành khác
+ Hai là thôi học(Không học nữa)
*/
/*
Nhà trường chửi vì thằng sinh viên này muốn chuyển sang chuyên ngành mà trường  mình ko dạy
=> chuyển bằng niềm tin à
*/ 

SELECT * FROM MajorV2
select * from StudentV2

ALTER TABLE StudentV2 ADD CONSTRAINT FK_ FOREIGN KEY(MajorID) REFERENCES MajorV2(MajorID)


-- thống kê sinh viên học ngành se

-- khi mình thống kê thì thấy có một sinh viên học chuyên ngành fe
-- mà trong khi chuyên ngành đó trường mình không hề dạy

DELETE FROM MajorV2 where MajorID = 'SE'
/*
Không thể nào xóa được vì chuyên nhành này vẫn còn sinh viên đang học(Học 7, 8 năm rồi 
không lấy nổi bằng) thì phải đợi cho nó học xong đã chứ
-- Nhưng học 7, 8 năm rồi thời gian lâu quá nhà trường không đợi được
-> Cần có một cái thỏa thuận giữa sinh viên và nhà trường để đưa ra một cách giải quyết hợp lý
-> Cần có một giải pháp ở đây
Trong tình huống xóa chuyên ngành đi thì những sinh viên đang còn học thì phải
+ Một là phải chuyển sang một chuyên ngành khác
+ Hai là thôi học(Không học nữa)
*/


CREATE TABLE StudentV3(
	StudentID int primary key,
	StudentName nvarchar(20),
	MajorID char(5) 
)
CREATE TABLE MajorV3(
	MajorID char(5) primary key,
	MajorName nvarchar(20)
)

ALTER TABLE StudentV3 ADD CONSTRAINT FK____ FOREIGN KEY(MajorID) REFERENCES MajorV3(MajorID)

INSERT INTO StudentV3 VALUES  --(6, N'Nguyễn Văn e', 'MK'),
								(2, N'Nguyễn Văn e', 'SE'),
								(3, N'Nguyễn Văn e', 'SE'),
								(4, N'Nguyễn Văn e', 'GD'),
								(5, N'Nguyễn Văn e', 'GD')
INSERT INTO MajorV3 VALUES('SE', 'Software Engineer'),
							('GD', 'Graphic Design'),
							('MK', 'Marketing')

SELECT * FROM MajorV3
select * from StudentV3
DELETE FROM MajorV3 where MajorID = 'SE'

-- Thêm một thỏa thuận trong ràng buộc này
ALTER TABLE StudentV3 ADD CONSTRAINT FK____ FOREIGN KEY(MajorID) REFERENCES MajorV3(MajorID)
			ON DELETE CASCADE
ALTER TABLE StudentV3 ADD CONSTRAINT FK____ FOREIGN KEY(MajorID) REFERENCES MajorV3(MajorID)
			ON DELETE SET NULL
			-- Tao sẽ sét mày sang NULL và sẽ cho mày suy nghĩ để viết đơn
			-- xin đổi chuyên ngành
			-- Tại vì nếu mà lại sét sang một chuyên ngành ko có trong trường mình
			-- => lại ngu người
-- CASCADE Hiệu ứng sụp đổ(dây chuyền) domino
/*
Khi mà nhà trường xóa chuyên ngành se đi thì những sinh viên nào đang học trong chuyên ngàn
đó thì cũng bị xóa luôn(Hiệu ứng sụp đổ dây chuyền)
+ Nhưng mà thằng viên này không muốn bị xóa mà nó muốn chuyển sang chuyên ngành khác
+ thì phải cho nó sang chuyên ngành khác -> hợp lý
-- Khi lúc này mã chuyên ngành về nul thì sinh vien nó sẽ viết dơn đổi chuyên ngành
bằng cách
*/
-- Tạo ra cái đơn xin đổi chuyên ngành cho sinh viên a
UPDATE StudentV3 SET MajorID = 'GD' WHERE StudentID = 2
UPDATE StudentV3 SET MajorID = 'MK' WHERE StudentID = 3
