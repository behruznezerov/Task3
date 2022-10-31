#include <iostream>
using namespace std;

class Debtor {

#pragma region Fields

	int objectId;
	char* name;
	char* surname;
	char* workAdress;
	char* phoneNumber;
	bool hasLatePayment;
	char* liveAdress;
	double debt;
	static int StaticId;

#pragma endregion

public:

#pragma region Constructors

	Debtor() : name(nullptr), surname(nullptr), workAdress(nullptr), phoneNumber(nullptr), hasLatePayment(true), liveAdress(nullptr), debt(1) {
		objectId = ++StaticId;
	};

	Debtor(const char* name) : Debtor() {
		SetName(name);
	}

	Debtor(const char* name, const char* surname) : Debtor(name) {
		SetSurname(surname);
	}

	Debtor(const char* name, const char* surname, const char* workAdress) : Debtor(name, surname) {
		SetWorkAdress(workAdress);
	}

	Debtor(const char* name, const char* surname, const char* workAdress, const char* phoneNumber) : Debtor(name, surname, workAdress) {
		SetPhoneNumber(phoneNumber);
	}

	Debtor(const char* name, const char* surname, const char* workAdress, const char* phoneNumber, bool hasLatePayment) : Debtor(name, surname, workAdress, phoneNumber) {
		this->hasLatePayment = hasLatePayment;
	}

	Debtor(const char* name, const char* surname, const char* workAdress, const char* phoneNumber, bool hasLatePayment, const char* liveAdress) : Debtor(name, surname, workAdress, phoneNumber, hasLatePayment) {
		SetLiveAdress(liveAdress);
	}

	Debtor(const char* name, const char* surname, const char* workAdress, const char* phoneNumber, bool hasLatePayment, const char* liveAdress, double debt) : Debtor(name, surname, workAdress, phoneNumber, hasLatePayment, liveAdress) {
		this->debt = debt;
	}

	Debtor(const Debtor& other) {
		objectId = other.objectId;
		SetName(other.name);
		SetSurname(other.surname);
		SetWorkAdress(other.workAdress);
		SetPhoneNumber(other.phoneNumber);
		hasLatePayment = other.hasLatePayment;
		SetLiveAdress(other.liveAdress);
		debt = other.debt;
	}
#pragma endregion

#pragma region Setters&Getters

	void SetName(const char* name) {
		delete this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void SetSurname(const char* surname) {
		delete this->surname;
		this->surname = new char[strlen(surname) + 1];
		strcpy_s(this->surname, strlen(surname) + 1, surname);
	}
	void SetWorkAdress(const char* workAdress) {
		delete this->workAdress;
		this->workAdress = new char[strlen(workAdress) + 1];
		strcpy_s(this->workAdress, strlen(workAdress) + 1, workAdress);
	}
	void SetPhoneNumber(const char* phoneNumber) {
		delete this->phoneNumber;
		this->phoneNumber = new char[strlen(phoneNumber) + 1];
		strcpy_s(this->phoneNumber, strlen(phoneNumber) + 1, phoneNumber);
	}
	void SetLiveAdress(const char* liveAdress) {
		delete this->liveAdress;
		this->liveAdress = new char[strlen(liveAdress) + 1];
		strcpy_s(this->liveAdress, strlen(liveAdress) + 1, liveAdress);
	}

	const char* GetName() {
		return name;
	}

	const char* GetSurname() {
		return surname;
	}

	const char* GetWorkAdress() {
		return workAdress;
	}

	const char* GetLiveAdress() {
		return liveAdress;
	}

	const char* GetPhoneNumber() {
		return phoneNumber;
	}

	double GetDebt() {
		return debt;
	}

	bool GetLatePayment() {
		return hasLatePayment;
	}

	int GetObjectId() {
		return objectId;
	}

#pragma endregion

#pragma region Methods

	void ShowDebtor() {
		cout << "Id : " << objectId << endl;
		cout << "Name : " << name << endl;
		cout << "Surname : " << surname << endl;
		cout << "WorkAdress : " << workAdress << endl;
		cout << "LiveAdress : " << liveAdress << endl;
		cout << "Debt : " << debt;
	}





#pragma endregion

};

int Debtor::StaticId = 0;

class Bank {

#pragma region Fields


	int DebtorCount = 3;
	char* name;
	Debtor* debtors = new Debtor[DebtorCount]{
		{"Behruz","Nezerov","Kubinka","0552148210",true,"Qax",780},
		{"Kenan","Esgerov","Yasamal","0554824820",false,"Gence",1670},
		{"Elgun","Eyyubov","20 Yanvar","0705821282",true,"Lerik",1520}
	};
#pragma endregion

public:

#pragma region Methods

	void ShowAllDebtors() {
		cout << "ALL DEBTORS : \n\n";
		for (int i = 0; i < DebtorCount; i++)
		{
			debtors[i].ShowDebtor();
			cout << "\n\n";
		}
	}

	void ShowLateDebtors() {
		cout << "LATE DEBTORS : \n\n";
		for (int i = 0; i < DebtorCount; i++)
		{
			if (debtors[i].GetLatePayment())
			{
				debtors[i].ShowDebtor();
				cout << "\n\n";
			}
		}
	}

	void Show1000Debtor() {
		cout << "1000+ DEBTORS : \n\n";
		for (int i = 0; i < DebtorCount; i++)
		{
			if (debtors[i].GetDebt() > 1000)
			{
				debtors[i].ShowDebtor();
				cout << "\n\n";
			}
		}
	}
#pragma endregion

};

int main() {
	Bank Prius;
	Prius.ShowAllDebtors();
	Prius.Show1000Debtor();
	Prius.ShowLateDebtors();
}