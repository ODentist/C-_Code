#include<iostream>
#include<ctime>
using namespace std;
const int MaxSize = 100;
class RandomNumber {
private:
	int length;
	int s[MaxSize];
public:
	RandomNumber();
	RandomNumber(int x[MaxSize],int n);
	~RandomNumber();
	int Search(int x);
	void Show();
	void Insert(int i, int y);
	void Delete(int i);
};

//�����������
void Found(int x[],int n) {

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		x[i] = rand() % 101;
	}
}

int main() {
	int y[100],x,n;
	int a, b,c;
	cout << "������˳����ĳ���: ";
	cin >> n;
	Found(y,n);
	RandomNumber RandomNumber1(y,n);
	RandomNumber1.Show();
	while (1) {
	cout << "�������ѯ����: " ; 
	cin >> x;
	if (RandomNumber1.Search(x)) {
		cout << "��ѯ�ɹ�!" << endl;
		break;
	}
	else {
		cout << "��ѯʧ��!" << endl;
		cout << "���������!" << endl;
	}
	}
	cout << "���������λ�ú�ֵ" << endl;
	cin >> a >> b;
	RandomNumber1.Insert(a,b);
	RandomNumber1.Show();
	cout << "������ɾ��λ��" << endl;
	cin >> c;
	RandomNumber1.Delete(c);
	RandomNumber1.Show();
	system("pause");
	return 0;
}

RandomNumber::RandomNumber()
{
	//��ʼ��length
	length = 0;
}

//��ʼ��s
RandomNumber::RandomNumber(int x[100],int n)
{
	length = 0;
	for (int i = 0; i < n; i++) {
		s[i] = x[i];
		length++;
	}
}


RandomNumber::~RandomNumber()
{
	//����
}

int RandomNumber::Search(int x)
{
	for (int i = 0; i < length; i++) {
		//cout << "x=" << x << " s[]=" << s[i] << endl;
		if (s[i] == x)
		{
			cout << "(��һ�γ��ֵ�λ��)��ѯ����˳����еĵ�:" << i+1 <<"��"<< endl;
			return 1;
		}

	}
	return 0;
}

void RandomNumber::Show()
{
	cout << "˳���Ϊ: ";
	for (int i = 0; i < length; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	cout << "˳����ĳ���Ϊ: " << length << endl;
}

void RandomNumber::Insert(int i, int y)
{
	if (length == MaxSize)
		throw"����";
	if (i < 0 || i >= length)
		throw"λ�ô���";
	for (int j = length; j >= i; j--) 
	 {
		s[j] = s[j - 1];
	 }
	s[i - 1] = y;
	length++;
}

void RandomNumber::Delete(int i)
{
	if (length <= 0)
		throw"����";
	if (i<0 || i>length)
		throw"λ�ô���";
	for (int j = i; j < length; j++) {
		s[j - 1] = s[j];
	}
	length--;
}
