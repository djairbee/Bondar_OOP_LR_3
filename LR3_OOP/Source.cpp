#include <iostream>
#include <cmath>
#include <ctime>
#include <locale>

using namespace ::std;

class Vector {
private:
	int* coord;
	int size;

public:
	static int check;
	double result;

	Vector()
	{
		//cout << "������ ������������" << endl;
		Set_coord(3);
	}

	Vector(int n)
	{
		//cout << "������ ������������" << endl;
		Set_coord(n);
	}

	~Vector()
	{
		//cout << endl << endl << "������ �����������"<< this << endl <<endl;
		delete[] coord;
	}

	void Set_coord(int n)
	{
		Set_count(n);
		dyn_coord();
		Set_all_coord();
	}

	void Set_count(int n)
	{
		size = n;
	}

	int Get_size()
	{
		return size;
	}

	void dyn_coord()
	{
		coord = new int[size];
	}

	void Set_all_coord()
	{
		for (int i = 0; i < size; i++)
		{
			coord[i] = rand() % 15;
		}
	}

	void Print()
	{
		cout << "(";
		for (int i = 0; i < size; i++)
		{
			cout << " " << *(coord + i) << " ";
		}
		cout << ")";
	}

	double lenght()
	{
		double len, sq = 0;
		for (int i = 0; i < size; i++)
		{
			sq += (*(coord + i) * *(coord + i));
		}
		len = sqrt(sq);
		result = len;
		return len;
	}

	void lenght_out()
	{
		lenght();
		cout << " = " << "[" << result << "]" << endl;
	}

	bool operator >=(const Vector& other)
	{
		if (this->result < other.result)
		{
			cout << "������� � ������ ������" << endl;
			return false;
		}
		if (this->result >= other.result)
		{
			cout << "������� � ������ ������" << endl;
			return true;
		}
	}

	void operator +(const Vector& other)
	{
		cout << endl << "{";
		for (int i = 0, res = 0; i < size; i++)
		{
			res = this->coord[i] + other.coord[i];
			cout << " " << res << " ";
		}
		cout << "}";
	}

	Vector operator +=(const Vector& other)
	{
		
		
		size += other.size;
		
		this->coord = (int*)realloc(this->coord, size * sizeof(int));
		for (int i = size - 1, j = 0; i > size - 1 - other.size; i--, j++)
		{
			this->coord[i] = other.coord[other.size - 1 - j];
		}
		
		cout << " ";
		check++;
		
		return *this;
	}

	void avg_len()
	{
		cout << "[" << (lenght()) / (double)(check + 1) << "]";
	}

	void operator =(const Vector& other)
	{
		this->size = other.size;
		if (this->coord != nullptr)
		{
			delete[] this->coord;
		}
		this->coord = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->coord[i] = other.coord[i];
		}
	}

	Vector(const Vector& other)
	{
		this->size = other.size;
		this->coord = new int[other.size];

		for (int i = 0; i < size; i++)
		{
			this->coord[i] = other.coord[i];
		}
	}

	void addition(Vector& v1, Vector& v2)
	{
		cout << endl << "{";
		for (int i = 0, res = 0; i < v1.size; i++)
		{
			res = v1.coord[i] + v2.coord[i];
			cout << " " << res << " ";
		}
		cout << "}";
	}

	void difference(Vector& v1, Vector& v2)
	{
		cout << endl << "{";
		for (int i = 0, res = 0; i < v1.size; i++)
		{
			res = v1.coord[i] - v2.coord[i];
			cout << " " << res << " ";
		}
		cout << "}";
	}

	void scal_dob(Vector& v1, Vector& v2)
	{
		int sum = 0;
		for (int i = 0, res = 0; i < v1.size; i++)
		{
			res = v1.coord[i] * v2.coord[i];
			sum += res;
		}
		cout << " " << sum;
	}
	void calcs(Vector& v2)
	{
		cout << endl << endl << "���� �������";
		addition(*this, v2);
		cout << endl << endl << "г����� �������";
		difference(*this, v2);
		cout << endl << endl << "��������� ������� �������" << " =";
		scal_dob(*this, v2);
	}
	
};

int Vector::check = 0;

void sorting(Vector* arr, int n)
{
	int i, k, k2, j, ch = -1;

	k = n, k2 = n - 1;
	double max_len;
	Vector max_vector;
	Vector temp;

	do
	{
		max_len = arr[0].lenght();
		max_vector = arr[0];
		for (i = 0, j = 0, ch = 0; i < k; i++)
		{
			if (arr[i].lenght() > max_len)
			{
				max_len = arr[i].lenght();
				ch = i;
			}

		}
		if ((max_len != arr[n - 1].lenght()))
		{
			temp = arr[k2];
			arr[k2] = arr[ch];
			arr[ch] = temp;
			arr[k2].result = max_len;
		}
		k--;
		k2--;
	} while (k > 0);
}

int operator >> (istream& os, Vector& v)
{
	int n;
	cin >> n;
	v.Set_coord(n);
	return n;
}

void operator << (ostream& os, Vector& v)
{
	cout << "���������� �������" << " : ";
	v.Print();
	cout << endl;
}

int main()
{
	system("chcp 1251");
	int n = 3;

	cout << "\n������ ��������� �����:" << endl;
	srand(time(NULL));
	Vector a(n);
	cout << "���������� �������" << " : ";
	a.Print();
	cout << endl << "������� ������� ";
	a.lenght_out();


	cout << "\n������ ��������� �����: \n";
	Vector b;
	cout << b;
	cout << "������� ������� ";
	b.lenght_out();
	a.calcs(b);
	cout << endl << endl;
	a >= b;
	cout << endl << endl;
	Vector u(n);


	cout << "\n����� ��������� �����:" << endl;
	cout << u;
	cout << endl << "������� ������� ";
	u.lenght_out();


	cout << endl << endl << endl << "�������� ������� : ";
	Vector Cb = (a += b += u);
	Cb.Print();
	Cb.lenght_out();
	cout << endl << "������� ������� ������� �� ������� ������� = ";
	Cb.avg_len();

	cout << endl << endl << endl;

	Vector* arr;
	int v = 5;
	arr = new Vector[v];

	cout << "������� � ����������� ������������" << endl << endl;
	for (int i = 0; i < v; i++)
	{
		arr[i].Print();
		arr[i].lenght_out();
		cout << endl;
	}
	cout << endl << endl;
	sorting(arr, v);
	cout << "������� � ����������� ������������ ���������� �� ��������" << endl << endl;
	for (int j = 0; j < v; j++)
	{
		arr[j].Print();
		arr[j].lenght_out();
		cout << endl;
	}

	cout << endl << "\n����� ����������� �������� ����������� �� ��'���� �����." << endl << endl;

	return 0;
}

/*
1. ������������� �������� >= (��������� ������� �� ��������),
+ (��������� ������� ������� �� �������), ����������� �����
���������� ����� ������� �� ��������� ������ � �������������
��������� ���������� �������, ��������� �������
������� ��� ������� � �����.
*/