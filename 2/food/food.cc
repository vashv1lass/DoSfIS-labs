#include "food.h"

#include <stdexcept>

Food::Food(double proteins, double fats, double carbohydrates) {
    if (proteins < 0 || proteins > 100) {
        throw std::out_of_range("Proteins count value must be between 0 and 100 gramms!");
    }
    if (fats < 0 || fats > 100) {
        throw std::out_of_range("Fats count value must be between 0 and 100 gramms!");
    }
    if (carbohydrates < 0 || carbohydrates > 100) {
        throw std::out_of_range("Carbohydrates count value must be between 0 and 100 gramms!");
    }
    
    proteins_ = proteins;
    fats_ = fats;
    carbohydrates_ = carbohydrates;
}

double Food::GetProteins() const noexcept {
    return proteins_;
}

double Food::GetFats() const noexcept {
    return fats_;
}

double Food::GetCarbohydrates() const noexcept {
    return carbohydrates_;
}

double Food::GetCalories() const noexcept {
    return 4 * proteins_ + 9 * fats_ + 4 * carbohydrates_;
}