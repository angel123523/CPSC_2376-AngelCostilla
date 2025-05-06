#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>


class GradeBook;


class IObserver {
public:
    virtual void update(const std::vector<int>& grades) = 0;
    virtual ~IObserver() = default;
};


class GradeBook {
private:
    std::vector<std::shared_ptr<IObserver>> observers;
    std::vector<int> grades;

public:
    void addObserver(std::shared_ptr<IObserver> observer) {
        observers.push_back(observer);
    }

    void addGrade(int grade) {
        grades.push_back(grade);
        notify();
    }

    void changeGrade(int index, int newGrade) {
        if (index >= 0 && index < static_cast<int>(grades.size())) {
            grades[index] = newGrade;
            notify();
        }
        else {
            std::cout << "Invalid index.\n";
        }
    }

    void notify() {
        for (const auto& observer : observers) {
            observer->update(grades);
        }
    }
};


class Averager : public IObserver {
public:
    void update(const std::vector<int>& grades) override {
        if (!grades.empty()) {
            double sum = std::accumulate(grades.begin(), grades.end(), 0);
            double average = sum / grades.size();
            std::cout << "Updated average: " << average << "\n";
        }
    }
};


class Notifier : public IObserver {
private:
    int threshold;
public:
    Notifier(int threshold = 60) : threshold(threshold) {}

    void update(const std::vector<int>& grades) override {
        for (int grade : grades) {
            if (grade < threshold) {
                std::cout << "Email sent to student@example.com (Grade: " << grade << " below threshold " << threshold << ")\n";
                break;
            }
        }
    }
};

int main() {
    auto gradeBook = std::make_shared<GradeBook>();

    auto averager = std::make_shared<Averager>();
    auto notifier = std::make_shared<Notifier>(60);

    gradeBook->addObserver(averager);
    gradeBook->addObserver(notifier);

    gradeBook->addGrade(80);
    gradeBook->addGrade(90);
    gradeBook->addGrade(55);  
    gradeBook->changeGrade(1, 50); 

    return 0;
}