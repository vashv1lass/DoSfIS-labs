#include "id_generator.h"

int IDGenerator::current_id_ = 1;

int IDGenerator::GetCurrentID() {
    return current_id_;
}

int IDGenerator::GenerateID() {
    return current_id_++;
}

void IDGenerator::Reset() {
    current_id_ = 1;
}