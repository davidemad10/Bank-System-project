#include <iostream>
#include <string>
using namespace std;

class Validation {
public:
	static bool isValidName(const string& name) {
		if (name.length() < 5 || name.length() > 20)
			return false;
		for (char c : name) {
			if (!isalpha(c))
				return false;
		}
		return true;
	}
	static bool isValidPassword(const string& password) {
		if (password.length() >= 8 && password.length() <= 20) {
			return true;
		}
		return false;
	}
	static bool isValidBalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}
	static bool isValidsalary(double balance) {
		if (balance < 5000) {
			return false;
		}
		return true;
	}
};
	
class Person {
protected:
	int id;
	string name;
	string password;
public:

	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		if (Validation::isValidName(name)) {
			this->name = name;
		}
		else {
			cout << "Invalid name!" << endl;
			cout << "The name must be alphabetic chars and min size 5 and max size 20" << endl;
		}
	}
	void setPassword(string password) {
		if (Validation::isValidPassword(password)) {
			this->password = password;
		}
		else {
			cout << "Invalid password" << endl;
			cout << "Password must be with min size 8 and max size 20" << endl;
		}
	}
	int getId() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getPassword() {
		return this->password;
	}
};

class Client :public Person {
private:
	double balance;
public:
	void setBalance(double balance) {
		if (Validation::isValidBalance(balance)) {
			this->balance = balance;
		}
		else
			cout << "Min balance must be 1500" << endl;
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		balance += amount;
	}
	void withdrow(double amount) {
		if (amount < balance) {
			balance -= amount;
		}
		else cout << "Insufficient balance!" << endl;
	}
	void transferto(double amount, Client& recipient) {
		if (amount < balance) {
			balance -= amount;
			recipient.deposit(amount);
		}
		else cout << "Insufficient balance!" << endl;
	}
	void checkbalance() {
		cout << "Current balance is: " << balance << endl;
	}
	void display() {
		cout << "ID is: " << id << endl;
		cout << "Name is: " << name << endl;
		cout << "Your Balance is: " << balance << endl;
	}
};

class Employee : public Person {
private:
	double salary;
public:
	void setSalary(double salary) {
		if (Validation::isValidsalary(salary)) {
			this->salary = salary;
		}
		else cout << "Min Salary must be 5000";
	}
	double getSalary() {
		return this->salary;
	}
	void display() {
		cout << "ID: " << id <<endl;
		cout << "Name: " << name << endl;
		cout << "Salary: " << salary << endl;
	}
};

class Admin :public Employee {

};

int main()
{
	int ID ,employeeID , adminID,choise;
	string name ,employee_name, admin_name, password , employeepass, adminpass;
	double balance , salary,adminsalary;
	Client client;
	Employee employee;
	Admin admin;
	cout << "Welcome sir please select number" << endl;
	cout << "\n 1-Client \n 2-Employee \n 3-Admin \n" << endl;
	cin >> choise;
	switch (choise) {
	case 1:
		cout << "please Enter your ID" << endl;
		cin >> ID;
		client.setId(ID);
		cout << "please Enter your Name" << endl;
		while (true) {
			cin >> name;
			if (Validation::isValidName(name)) {
				client.setName(name);
				break;
			}
			else {
				cout << "Wrong Name!!" << endl;
				cout << "The Name must be alphabetic chars with min size 5 and max size 20" << endl;
				cout << "please Enter your Name" << endl;
			}
		}
		cout << "please Enter your password" << endl;
		while (true) {
			cin >> password;
			if (Validation::isValidPassword(password)) {
				client.setPassword(password);
				break;
			}
			else {
				cout << "Password must be with min size 8 and max size 20" << endl;
				cout << "please try anthor password" << endl;
			}
		}
		cout << "please Enter your Balance" << endl;
		while (true) {
			cin >> balance;
			if (Validation::isValidBalance(balance)) {
				client.setBalance(balance);
				break;
			}
			else {
				cout << "Min balance must be 1500" << endl;
				cout << "please try again" << endl;
			}
		}
		client.deposit(1000);
		client.withdrow(1000);
		cout << "=============================" << endl;
		client.display();
		break;
	case 2:
		cout << "please Enter Employee ID" << endl;
		cin >> employeeID;
		employee.setId(employeeID);
		cout << "please Enter Employee Name" << endl;
		while (true) {
			cin >> employee_name;
			if (Validation::isValidName(employee_name)) {
				employee.setName(employee_name);
				break;
			}
			else {
				cout << "Wrong Name!!" << endl;
				cout << "The Name must be alphabetic chars with min size 5 and max size 20" << endl;
				cout << "please Enter Employee Name" << endl;
			}
		}
		cout << "please Enter Employee password" << endl;
		while (true) {
			cin >> employeepass;
			if (Validation::isValidPassword(employeepass)) {
				employee.setPassword(employeepass);
				break;
			}
			else {
				cout << "Password must be with min size 8 and max size 20" << endl;
				cout << "please try anthor password" << endl;
			}
		}
		cout << "please Enter Employee salary" << endl;
		while (true) {
			cin >> salary;
			if (Validation::isValidBalance(salary)) {
				employee.setSalary(salary);
				break;
			}
			else {
				cout << "Min salary must be 5000" << endl;
				cout << "please try again" << endl;
			}
		}
		cout << "=============================" << endl;
		employee.display();
		break;
	case 3:
		cout << "please Enter Admin ID" << endl;
		cin >> adminID;
		admin.setId(adminID);
		cout << "please Enter admin Name" << endl;
		while (true) {
			cin >> admin_name;
			if (Validation::isValidName(admin_name)) {
				admin.setName(admin_name);
				break;
			}
			else {
				cout << "Wrong Name!!" << endl;
				cout << "The Name must be alphabetic chars with min size 5 and max size 20" << endl;
				cout << "please Enter admin Name" << endl;
			}
		}
		cout << "please Enter admin password" << endl;
		while (true) {
			cin >> adminpass;
			if (Validation::isValidPassword(adminpass)) {
				admin.setPassword(adminpass);
				break;
			}
			else {
				cout << "Password must be with min size 8 and max size 20" << endl;
				cout << "please try anthor password" << endl;
			}
		}
		cout << "please Enter admin salary" << endl;
		while (true) {
			cin >> adminsalary;
			if (Validation::isValidBalance(adminsalary)) {
				admin.setSalary(adminsalary);
				break;
			}
			else {
				cout << "Min salary must be 5000" << endl;
				cout << "please try again" << endl;
			}
		}
		cout << "=============================" << endl;
		admin.display();
		break;
	default:
		cout << "wrong choise!" << endl;
	}
}

