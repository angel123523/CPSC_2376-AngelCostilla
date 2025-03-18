#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

class Employee {
public:
	std::string name;
	int id;

	Employee(std::string name, int id) : name(name), id(id) {}
	virtual ~Employee() {}

	virtual double calculateSalary() const = 0;

	virtual void displayInfo() const {
		std::cout << "Id: " << id << ", Name:" << name << ",";
	}
};
class SalariedEmployee : public Employee {
public:
	double monthlySalary;
	SalariedEmployee(std::string name, int id, double salary)
		: Employee(name, id), monthlySalary(salary) {
	}
	double calculateSalary() const override {
		return monthlySalary;
	}
	void displayInfo() const override {
		Employee::displayInfo();
		std::cout << "Type: Salaried, Monthly Salary: $" << monthlySalary << std::endl;
	}
};

class HourlyEmployee : public Employee {
public:
	double hourlyRate;
	int hoursWorked;

	HourlyEmployee(std::string name, int id, double rate, int hours)
		: Employee(name, id), hourlyRate(rate), hoursWorked(hours) {
	}

	double calculateSalary() const override {
		return hourlyRate * hoursWorked;
	}

	void displayInfo() const override {
		Employee::displayInfo();
		std::cout << "Type: Hourly, Hours Worked: " << hoursWorked << ", Hourly Rate: $" << hourlyRate
			<< ", Salary: $" << calculateSalary() << std::endl;
	}
};

class CommissionEmployee :public Employee {
public:
	double baseSalary;
	double salesAmount;
	double commissionRate;

	CommissionEmployee(std::string name,int id, double salary, double sales, double commission)
		:Employee(name,id),baseSalary(salary), salesAmount(sales), commissionRate(commission) {}

	double calculateSalary() const override {
		return baseSalary + (salesAmount * commissionRate);
	}
	void displayInfo() const override {
		Employee::displayInfo();
		std::cout<<"type: commision, base salary: $"<<baseSalary<<",sales:$"<<salesAmount
			<< ", Commission Rate: " << commissionRate * 100 << "%, Salary: $" << calculateSalary() << std::endl;
	}
};
void readEmployeesFromFile(const std::string& filename, std::vector<Employee*>& employees) {
	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Error: Could not open the file!" << std::endl;
		return;
	}

	std::string type, name;
	int id;
	double salary, hourlyRate, salesAmount, commissionRate;
	int hoursWorked;

	while (file >> type >> id >> name) {
		if (type == "Salaried") {
			file >> salary;
			employees.push_back(new SalariedEmployee(name, id, salary));
		}
		else if (type == "Hourly") {
			file >> hourlyRate >> hoursWorked;
			employees.push_back(new HourlyEmployee(name, id, hourlyRate, hoursWorked));
		}
		else if (type == "Commission") {
			file >> salary >> salesAmount >> commissionRate;
			employees.push_back(new CommissionEmployee(name, id, salary, salesAmount, commissionRate));
		}
		else {
			std::cerr << "Error: Unknown employee type " << type << std::endl;
		}
	}

	file.close();
}

int main() {
	std::vector<Employee*> employees;
	readEmployeesFromFile("employees.txt", employees);
	for (const auto& employee : employees) {
		employee->displayInfo();
	}
	for (auto& employee : employees) {
		delete employee;
	}
	return 0;
}