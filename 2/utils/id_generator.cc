#include "id_generator.h"

int IDGenerator::current_id_ = 1;

int IDGenerator::GetCurrentID() {
    return IDGenerator::current_id_;
}

void IDGenerator::Reset() {
    IDGenerator::current_id_ = 1;
}

int IDGenerator::GenerateID() {
    return IDGenerator::current_id_++;
}