#ifndef FOOD_FOOD_H_
#define FOOD_FOOD_H_

class Food {
public:
    Food(double, double, double);

    double GetProteins() const noexcept;

    double GetFats() const noexcept;

    double GetCarbohydrates() const noexcept;

    double GetCalories() const noexcept;
private:
    double proteins_;
    double fats_;
    double carbohydrates_;
};

#endif // FOOD_FOOD_H_