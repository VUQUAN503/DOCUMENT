-- Hiểu nó như một ngôn ngữ lập trình
-- vòng lặp, if else, hàm, .....
-- CÂU LỆNH CREATE TẠO DATABASE
CREATE DATABASE Test
on primary(
-- thông tin của file .mdf
	name = 'Test',
	filename = 'D:\Test.mdf',
	size = 5MB,
	maxsize = 20MB,
	filegrowth = 5%
)
log on(
-- thông tin của file log
	name = 'TestLog',
	filename = 'D:\Test.ldf',
	size = 1MB,
	maxsize = 10MB,
	filegrowth = 1%
)
USE Test
-- DROP DATABASE <Tên cơ sở dữ liệu muốn xóa>
DROP DATABASE Test

-- TẠO BẢNG DÙNG CÂU LỆNH CREATE
-- ten, mã số, địa chỉ
--CREATE TABLE SinhVien(
--	-- danh sách cột(danh sách thuộc tính) trong table
--	-- Mã Sinh Viên
--	MaSV char(10), -- kiểu chuỗi[char(10), varchar(), nvarchar()]
--	TenSV nvarchar(20),
--	DiaChi nvarchar(50)
--)
drop table SinhVien

CREATE TABLE SinhVien(
	-- danh sách cột(danh sách thuộc tính) trong table
	-- Mã Sinh Viên -- THÊM RÀNG BUỘC CHO CỘT MÃ SINH VIÊN KHÔNG ĐƯỢC NHẬN GIÁ TRỊ NULL
	[Mã Sinh Viên] char(10) NOT NULL PRIMARY KEY, -- kiểu chuỗi[char(10), varchar(), nvarchar()]
	[Tên Sinh Viên] nvarchar(20),
	[Tuổi] int check([Tuổi] > 0) -- giá trị tuổi phải luôn là một số dương
)
-- Câu lệch select xem bảng
SELECT * FROM SinhVien
-- Mình muốn thêm vào table cột tuổi
-- MUỐN CHỈNH SỬA, THÊM, XÓA TRÊN CẤU TRÚC CỦA TABLE
-- THÌ DÙNG CÂU LỆNH ALTER TABLE <Tên bảng mình muốn sửa đổi>
ALTER TABLE SinhVien ADD [Tuổi] int -- thêm vào table sinhvien cột tuổi
-- Mình muốn xóa cột địa chỉ trong table sinh vien
ALTER TABLE SinhVien DROP COLUMN [Địa Chỉ]-- Xóa cột địa chỉ trong table Sinh Viên

-- Chỉnh Sửa cột age thành kiểu char
ALTER TABLE SinhVien ALTER COLUMN [Tuổi] char(3)

--- Thêm dữ liệu vào trong bảng sinh viên
INSERT INTO SinhVien VALUES('SV02', N'Trần Văn B', 19),
						   ('SV03', N'Lý Thị C', 19)
INSERT INTO SinhVien([Mã Sinh Viên], [Tên Sinh Viên]) VALUES('SV04', N'Trần Xuân D') -- thêm thông tin cột muốn thêm
INSERT INTO SinhVien([Tên Sinh Viên], [Tuổi]) VALUES(N'Tèo thì E', '19')
SELECT * FROM SinhVien

INSERT INTO SinhVien VALUES('SV05', N'Bùi Cao F', 5)

-- 
SELECT * FROM SinhVien
INSERT INTO SinhVien VALUES('SV06', N'Nguyễn Văn A', 19)
-- Ta thấy 2 sinh viên trong bảng có cùng mã với nhau
-- Trong thực tế thì mã số sinh viên không được phép trùng
-- => không hợp lý vì nếu nhỡ có hai sinh viên có trùng thông tin với nhau thì làm
-- sao phân biệt được
-- để phân biệt đc các dòng dữ liệu trên table ta sẽ cho table có một cái khóa chính
-- (primary key trên một table chỉ có duy nhất một khóa chính nó giúp phân được các dòng
-- dữ liệu có trong bảng
-- nếu cột nào trong bảng là khóa chính thì giá trị trong cột đó không được phép trùng nhau)
-- Ta không thích cho ràng buộc khóa chính cho mã sinh viên muốn xóa
-- 
ALTER TABLE SinhVien DROP CONSTRAINT PK__SinhVien__AFE965F232CE118F--Tên cái ràng buộc mình muốn xóa
-- Mình add contraints
ALTER TABLE SinhVien ADD CONSTRAINT AHIHI PRIMARY KEY([Mã Sinh Viên])
SELECT * FROM SinhVien

--DELETE FROM SinhVien WHERE [Mã Sinh Viên] = 'SV06'
-- cho nó ràng buộc về cột tuổi chỉ được nhận giá trị dương(> 0)
-- => nếu mà có một sinh viên tuổi là số âm -> chửi và không cho phép chèn vào
-- => mình dùng ràng buộc check

--ALTER TABLE SinhVien ALTER COLUMN [Mã Sinh Viên] char(10) NOT NULL -- thêm ràng buộc 
-- không đc nhận giá trị null
-- sinh viên không có mã số -> không hợp lý
-- Sinh Viên này mã số bắt buộc phải có vì đã là sinh viên thì ngầm dịnh bao h cũng phải có mã số


-- Ràng buộc về giữ liệu trong bảng


-- 2020606122            Nguyen Van A         Nam Dinh
-- new Student("2020606122", "Nguyen Van A", "Nam Dinh")





