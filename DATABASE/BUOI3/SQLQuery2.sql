


/*
SELECT
-- THAO TÁC VỚI DỮ LIỆU
SELECT [DISTINCT] FROM BANG WHERE GROUP BY [HAVING] ORDER BY
-- LẬP TRÌNH
*/

USE DeptEmp
SELECT * FROM Department

select * from Employee

-- HIỂN THI DANH SÁCH NHÂN VIÊN CÓ LƯƠNG LỚN 1000
SELECT * FROM Employee WHERE Salary > 1000
-- CHO BIẾT TÊN ĐẦY ĐỦ NHỮNG NHÂN VIÊN Ở PHÒNG 30
SELECT FName + ' ' + LName AS [FulName] FROM Employee where DepartmentNo = 30

-- CHO BIẾT NHỮNG NHÂN VIÊN LỚN HƠN 30
SELECT * FROM Employee WHERE YEAR(GETDATE()) - YEAR(HireDate) >= 30

-- CHO BIẾT NHỮNG NHÂN VIÊN CÓ TÊN(last name) BẮT ĐẦU BẰNG CHỮ H
SELECT * FROM Employee WHERE Lname LIKE 'S%' 

-- CHO BIẾT NHỮNG NHÂN VIÊN CÓ TÊN(last name) CÓ ĐỘ DÀI LÀ 5
SELECT * FROM Employee WHERE Lname LIKE '_____'

-- Cho biết những nhân viên có tên đầy đủ có độ dài nằm trong khoảng từ 9 đến 15
SELECT * FROM Employee WHERE LEN(FName + ' ' + LName) >= 9 AND LEN(FName + ' ' + LName) <= 15
-- mấu chốt quan trọng là làm saoa tính dc độ dài của full name rồi mình so
-- sánh nó với khoảng giá trị
SELECT * FROM Employee WHERE LEN(FName + ' ' + LName) BETWEEN 9 AND 15

-- HIỂN THỊ NHỮNG NHÂN VIÊN CÓ commision là giá trị NULL
SELECT * FROM Employee WHERE Commision IS NULL

-- HIỂN THỊ NHỮNG NHÂN VIÊN CÓ commision không phải giá trị NULL
SELECT * FROM Employee WHERE Commision IS NOT NULL

SELECT * FROM Department

-- HIỂN THỊ RA DANH SÁCH NHÂN VIÊN Ở PHÒNG Sales
SELECT * FROM Employee WHERE DepartmentNo =
					(SELECT DepartmentNo FROM Department WHERE DepartmentName = 'Sales')
 											 
-- HIỂN THỊ RA DANH SÁCH NHÂN VIÊN SINH TRONG THÁNG CHẴN VÀ Ở PHÒNG Sales Hoặc phòng research
SELECT * FROM Employee WHERE MONTH(HireDate) % 2 = 0 AND DepartmentNo IN
					(
						SELECT DepartmentNo FROM Department WHERE DepartmentName = 'Sales' OR DepartmentName = 'Research'
					)


-- CHO BIẾT PHÒNG Sales có bao nhiêu nhân viên
SELECT COUNT(*) AS [Number of Employee] FROM Employee WHERE DepartmentNo = (
		SELECT DepartmentNo FROM Department WHERE DepartmentName = 'Research'
)

-- HIỂN THỊ TÊN PHÒNG VÀ SỐ LƯỢNG NHÂN VIÊN CỦA TỪNG PHÒNG
-- SELECT DepartmentName , COUNT(*) FROM Department

-- CHO BIẾT NHÂN VIÊN NÀO CÓ LƯƠNG CAO NHẤT
SELECT * FROM Employee WHERE Salary = (
		SELECT MAX(Salary) FROM Employee
)

INSERT INTO Employee VALUES(6, 'Dinh', 'Tuan', N'Mõm', '10-20-2002', 1600, NULL, 10)
-- TÌM RA NHỮNG NHÂN VIÊN CÓ LƯƠNG LỚN NHẤT TRONG PHÒNG SALES
SELECT * FROM Employee WHERE Salary IN (
		 SELECT Max(Salary) FROM Employee where DepartmentNo = (
					SELECT DepartmentNo FROM Department WHERE DepartmentName = 'Sales'
					)
)
-- Nhìn có vẻ đúng nhưng thật ra lại sai

-- Câu chuẩn của nó
SELECT * FROM Employee WHERE Salary = (
		SELECT MAX(Salary) FROM Employee WHERE DepartmentNo = (
								SELECT DepartmentNo FROM Department WHERE DepartmentName = 'Sales'
															  )
									  )
		AND DepartmentNo = ( 
				SELECT DepartmentNo FROM Department WHERE DepartmentName = 'Sales'
						   )


-- hiện thị ra danh sách nhân viên ở phòng sales có mức lương lớn
-- hơn mức lương trung bình của phòng research
SELECT * FROM Employee WHERE Salary > (
			SELECT AVG(Salary) FROM Employee WHERE DepartmentNo = (
					SELECT DepartmentNo FROM Department WHERE DepartmentName = 'research'
									)
								)
							AND DepartmentNo = (SELECT DepartmentNo FROM Department WHERE DepartmentName = 'SALES')


-- KẾT NỐI HAI BẢNG LẠI VỚI NHAU THÔNG QUA KHÓA NGOẠI
-- CÚ PHÁP (INNER JOIN, LEFT JOIN, RIGHT JOIN, FULL JOIN)
-- from bảng a inner join bảng b ON (điều kiện kết nối chính khóa ngoại)
-- 
SELECT * FROM Employee INNER JOIN Department ON Employee.DepartmentNo = Department.DepartmentNo

-- HIỂN THỊ TÊN PHÒNG VÀ SỐ LƯỢNG NHÂN VIÊN CỦA TỪNG PHÒNG
SELECT  DepartmentName, COUNT(EmpNo) [Number of Employee] FROM Department LEFT JOIN Employee
	ON Employee.DepartmentNo = Department.DepartmentNo
		GROUP BY DepartmentName

	SELECT * FROM Department

	SELECT  *  FROM Department LEFT JOIN Employee
	ON Employee.DepartmentNo = Department.DepartmentNo


-- hiển thị ra chỉ số của phần tử có giá trị lớn nhất trong mảng = 1, 4, 3, 5, 2, 5
/*
Mấy bước 
+ tìm ra phần tử lớn nhất
+ duyệt lại mảng và xét nếu nó bằng max thì in ra chỉ số của nó
for(int i = 0; i < 5; ++i)
	if(a[i] > max) max = a[i]

for(int i = 0; i < 5; ++i)
	if(a[i] == max) cout << i
*/




-- CHÚ Ý KHI DÙNG HÀM COUNT THÌ CHỈ NÊN COUNT TRÊN MÃ(KHÓA CHÍNH CỦA BẢNG)
-- HOẶC LÀ COUNT TRÊN CẢ DÒNG ĐÓ COUNT(*)
-- TRÁNH TRƯỜNG HỢP CÁC CỘT KHÁC CÓ GIÁ TRỊ NULL => HÀM NÀY SẼ ĐẾM SAI


-- thống kê theo nhóm thường sẽ đi kèm với mệnh đề group by
-- AVG - Lấy giá trị trung bình nhóm
-- MAX - giá trị lớn nhất trong nhóm
-- MIN, SUM
-- COUNT -- ĐẾM SỐ LƯỢNG

