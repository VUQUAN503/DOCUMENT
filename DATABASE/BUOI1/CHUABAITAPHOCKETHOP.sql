/*
a. (2?) T?o csdl QLBanHang g?m 3 b?ng: 
+ CongTy(MaCT,TenCT,TrangThai,ThanhPho)
+ SanPham(MaSP, TenSP, MauSac,Gia,SoluongCo)
+ Cungung(MaCT,MaSP, SoLuongBan)
b. (4?) Thêm các ràng bu?c vào các b?ng trong CSDL Qu?n lý sinh viên:
B?ng s?n ph?m:
- Màu s?c m?c ??nh là màu ??
- Tên s?n ph?m ph?i là duy nh?t
B?ng cung ?ng:
- S? l??ng bán >0
c. (2?) Nh?p d? li?u: 3 công ty, 3 s?n ph?m, 6 cung ?ng
d. (2?) T?o l?nh th?c thi hi?n th? thông tin c?a các b?ng
*/

CREATE DATABASE QLBanHang

USE QLBanHang

CREATE TABLE CongTy(
	[Mã Công Ty] char(10) PRIMARY KEY,
	[Tên Công Ty] nvarchar(20),
	[Tr?ng Thái] int,
	[Thành Ph?] nvarchar(50)
)

CREATE TABLE SanPham(
	[Mã S?n Ph?m] char(10) PRIMARY KEY,
	[Tên S?n Ph?m] nvarchar(20),
	[Màu S?c] nvarchar(20),
	[Giá] money,
	[S? L??ng Có] int
)

CREATE TABLE CungUng(
	[Mã Công Ty] char(10),
	[Mã S?n Ph?m] char(10),
	[S? L??ng Bán] int,
	CONSTRAINT [Ahihi ?? Ng?c] PRIMARY KEY([Mã Công Ty], [Mã S?n Ph?m])
)

-- B
ALTER TABLE SanPham
ADD CONSTRAINT [Ràng Bu?c Màu S?c]
DEFAULT N'??' FOR [Màu S?c]

ALTER TABLE SanPham DROP CONSTRAINT [Ràng Bu?c Màu S?c]
-- Ràng bu?c khóa ph? unique
ALTER TABLE SanPham ADD CONSTRAINT [Tên S?n Ph?m Duy Nh?t] UNIQUE([Tên S?n Ph?m])

ALTER TABLE CungUng ADD CONSTRAINT [S? L??ng Bán > 10] CHECK([S? L??ng Bán] > 0)

INSERT INTO CongTy VALUES('CT01', N'Công Ty 01', 1, N'C?u Gi?y, Hà N?i'),
						  ('CT02', N'Công Ty 02', 1, N'Hai Bà Tr?ng, Hà N?i'),
						  ('CT03', N'Công Ty 02', 0, N'Long Biên, Hà N?i')
SELECT * FROM CongTy
INSERT INTO SanPham VALUES('SP01', N'S?n Ph?m 01', N'Vàng', 10000, 1000),
						  ('SP02', N'S?n Ph?m 02', N'Xanh Lá', 10000, 1000)

SELECT * FROM SanPham
INSERT INTO SanPham([Mã S?n Ph?m], [Tên S?n Ph?m], [Giá], [S? L??ng Có]) VALUES('SP04', N'S?n Ph?m 04', 45000, 100)

