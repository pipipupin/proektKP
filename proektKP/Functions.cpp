#include "Functions.h"

void DataInitialization() {

	//�������� ��������� ����, � ������� ����� �������� ���������� ����������. �.�. �������� �����
	ofstream _buf("Buffer.txt");

	if (!_buf) {
		cout << "������ �������� ��������� �����!" << endl;
		 
		_buf.close();
	}
}

void DataEntry() {

	//���� ������ ������� 

	//��������� ����������
	string _surname;
	int _phoneNum;
	string _city;
	int n;

	cout << "������� ����������� ������: ";
	cin >> n;

	//��������� �������� ���� � ����������� � ���� ������
	ofstream record("Buffer.txt", ios::app);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			cout << "������� ������ �1 (�������):";
			cin >> _surname;

			cout << "������� ������ �2 (����� ��������): ";
			cin >> _phoneNum;

			cout << "������� ������ �3 (������): ";
			cin >> _city;

			record << _surname << endl;
			record << _phoneNum << endl;
			if (i < n - 1)
				record << _city << endl;
			else
				record << _city;

			cout << "_________________" << endl;
		}
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
}

void DataReading(string fileName) {

	//������ ������ �� �����

	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {

			//��������� ����������
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			//��������� ������ �� �����

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;

				reading >> _phoneNum;

				reading >> _city;

				record << _surname << endl;
				record << _phoneNum << endl;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
			cout << "������ �������!" << endl;
		}
		else 
			cout << "������ �������� ������!" << endl;
	}
	else
		cout << "������ �������� �����!" << endl;

	//�������� �����
	reading.close();
	record.close();

}

void Print() {

	ifstream reading("Buffer.txt");

	if (reading) {

		//��������� ����������
		string _surname;
		int _phoneNum;
		string _city;
		int n;

		reading >> n;
		cout << "���������� ������: " << n << endl << endl;

		for (int i = 0; i < n; i++) {
			cout << "������ �� �" << i + 1 << endl;

			reading >> _surname;
			cout << "������ �1 (�������): " << _surname << endl;

			reading >> _phoneNum;
			cout << "������ �2 (����� ��������): " << _phoneNum << endl;

			reading >> _city;
			cout << "������ �3 (�����): " << _city << endl;

			cout << "____________________________________________________" << endl;
		}
	}
	else
		cout << "������ �������� �����!" << endl;

	//��������� ����
	reading.close();
}

bool DataCleaning() {
	//������� ������

	bool clear = false;

	//��������� ����
	fstream _buf("Buffer.txt", ios::out);

	if (!_buf) 
		cout << "������ �������� �����!" << endl;
	
	//�������
	_buf.clear();

	//��������, ��� ���� ����
	if (_buf.peek() == EOF)
		clear = true;
	else
		clear = false;

	_buf.close();

	return clear;
}

void DataChange() {

	//��������� ������

	//�������� ��� ��� ������
	//������� ����� � ����� ������ ���������� ������ � ����
	//������ �� ������������ � ������� ��� ������

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ����������
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;

			//��������� �� ��������� ����� � ����� 
			reading >> n;

			cout << "�������� ����� ����������� �������� (�� 1 �� " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << n << endl;

			if (_n >= 0 && _n < n) {

				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else {
						cout << "������� ������ �1 (�������): ";
						cin >> _surname;

						cout << "������� ������ �2 (����� ��������): ";
						cin >> _phoneNum;

						cout << "������� ������ �1 (�����): ";
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;

						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "������ ���� ��������!" << endl;
			}
			else
				cout << "������ �������� �����!" << endl;
		}
		else
			cout << "������ �������� ��������� �����!" << endl;
		record.close();
		reading.close();

		remove("Buffer_.txt");
	}
}

void Copy() {
	//����������� � ����� ����
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ����������
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			//��������� �� ��������� ����� � �����
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
			}
		}
		else
			cout << "������ �������� �����!" << endl;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	record.close();
	reading.close();
}

int AmountOfData() {
	//������� ���������� ������ �� �����
	ifstream _buf("Buffer.txt");
	int n;

	if (_buf) {
		_buf >> n;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	_buf.close();

	return n;
}

void DeleteData() {
	//�������� ������

	//���������� ������
	//�������������� � �������� �����
	//����� ����������

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading) {
		if (record) {
			//��������� ����������
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;

			//��������� �� ��������� ����� � ����� 
			reading >> n;
			int b = n - 1;

			cout << "�������� ����� ����������� �������� (�� 1 �� " << n << "): ";
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl; 

			if (_n >= 0 && _n < n) {
				for (int i = 0; i < n; i++) {
					if (i != _n) {
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
							record << _city << endl;
						else
							record << _city;
					}
					else {
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "������ �������!" << endl;
			}
			else
				cout << "����� ������ �� �����!" << endl;
		}
		else 
			cout << "������ �������� �����!" << endl;
	}
	else 
		cout << "������ �������� ��������� �����!" << endl;
	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void AddData() {

	//�������� ������ 

	//��������� ����������
	string _surname;
	int _phoneNum;
	string _city;
	int n = AmountOfData() + 1;

	//��������� �������� ����
	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_) {
		record_ << n << endl;
	}
	else
		cout << "������ �������� ��������� �����!" << endl;

	if (record) {
		record << endl;

		cout << "������� ������ �1 (�������): ";
		cin >> _surname;

		cout << "������� ������ �2 (����� ��������): ";
		cin >> _phoneNum;

		cout << "������� ������ �1 (�����): ";
		cin >> _city;

		record << _surname << endl;
		record << _phoneNum << endl;
		record << _city;
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
	record_.close();
}

void SaveData(string fileName) {

	//���������� ������

	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading) {
		if (record) {
			//��������� ����������
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++) {
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
					record << _city << endl;
				else
					record << _city;
				
			}
			cout << "������ ��������� � ����� " << fileName << endl;
		}
		else
			cout << "������ �������� ��������� �����!" << endl;
	}
	else
		cout << "������ �������� �����!" << endl;

	record.close();
	reading.close();
}