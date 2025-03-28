#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
typedef struct Node* node;// dinh nghia de rut ngan cu phap
//ham tao
node creat(int x) {
	node tmp = new Node();//khai bao 1 con tro ten tmp kieu node
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
bool check_empty(node a)//(Node* a)
{
	return a == NULL ;//neu phan tu dau tien la rong thi khongo co phan tu phia sau

}
int Size_of_list(node a) {
	int cnt = 0;
	while (a != NULL) {
		a = a->next; //gan a cho dia chi tiep theo ( cau lenh quan trong) 
		cnt++;
	}
	return cnt;
}
void insertFirst(node &a, int x) {
	node tmp = creat(x);
	if (a==NULL){
		a = tmp;
	}
	else {
		tmp->next = a;
		a = tmp;// cap nhat a la gia tri cua tmp
	}  
}
void insertLast(node &a, int x) {// ham nao thay doi gia tri, them , sua , xoa phai co tham chieu
	node tmp = creat(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		node p = a;// dung p vi khong muon thay doi toan bo dia chi node head
		while (p->next != NULL) {
			p= p->next;
		}
		p->next = tmp;
	}
}
void insert_at_ramdom(node& a, int x, int pos) {
	int n = Size_of_list(a);
	node tmp = creat(x);
	if (pos == 0) {
		insertFirst(a, x); return;

	}
	else if (pos == n - 1) {
		insertLast(a, x); return;
	}
	else {
		node p = a;
		for (int i = 0; i < pos - 1; i++) {
			p = p->next;//p luc thoat vong lap la pos-1 thi p->next la pos
		}
		tmp->next = p->next;//tmp tro dung den node pos
		p->next = tmp;//pos-1 tro den tmp
	}

}

void deletefIRST(node& a)
{
	if (a != NULL) {
		a = a->next;
	}
}
void deleteLAST(node& a) {
	node truoc = NULL, sau = a;
	while (a != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL){//danh sach co 1 phan tu 
		a = NULL;
	}
	else {
		truoc->next = NULL;
	}
}
void delete_Random(node& a, int pos) {
	node truoc = NULL, sau = a;
	for (int i = 0; i < pos; i++) {
		truoc = sau;
		sau = sau->next;

	}
	if (truoc == NULL)
	{
		a = a->next;
	}
	else {
		truoc = sau->next;

	}
}
void print(node a) {
	cout << "----------------------\n";
	while (a != NULL)
	{
		cout << a->data << "->" << endl;
		a = a->next ;// khong can tao node p vi kh thay doi gia tri
	}

}
int main() {
	return 0;
}