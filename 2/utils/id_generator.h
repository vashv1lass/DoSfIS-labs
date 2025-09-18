#ifndef UTILS_ID_GENERATOR_H_
#define UTILS_ID_GENERATOR_H_

class IDGenerator {
public:
    static int GetCurrentID();
    static int GenerateID();
    static void Reset();
private:
    static int current_id_;
};

#endif // UTILS_ID_GENERATOR_H_