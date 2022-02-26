
#include "Disk.h"
#include "Square.h"


// is a
// has

/*
public, private:
protected:
(che giấu với tất cả người ngoài nhưng công khai với những thành viên trong gia đình(con))
*/
int main()
{
	/*Rectangle* rec = new Rectangle(3, 5, "PINK", 2.0);
	Square* squa = new Square(3 , "PINK", 2.0);
	Disk* disk = new Disk(3.5, "PINK", 2.0);
	rec->paint();
	squa->paint();
	disk->paint();*/
	Square* squa = new Square(3, "Pink", 2.5);
	squa->paint();
	return 0;
}