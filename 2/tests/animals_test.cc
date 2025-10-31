#ifndef ANIMALS_TEST_CC_
#define ANIMALS_TEST_CC_

#include <UnitTest++/UnitTest++.h>

#include "animals/animals.h"
#include "staff/staff.h"
#include "utils/utils.h"
#include "infrastructure/infrastructure.h"

#include <regex>

using namespace animals;
using namespace animals::medical;
using namespace staff;
using namespace utils;
using namespace utils::exceptions;
using namespace infrastructure;

struct AnimalFixture {
  AnimalFixture()
      : diver_feeder(std::string("Default DiverFeeder"), 3000.0, 50.0),
        trainer(std::string("Default trainer"), 2500.0) {};
  
  ~AnimalFixture() = default;

  DiverFeeder diver_feeder;
  Trainer trainer;
};

class TestAnimal : public Animal {
public:
    explicit TestAnimal(std::string name)
        : Animal(std::move(name)) {}

    void Move() const noexcept override {}
    std::string GetSpecies() const noexcept override { return "TestAnimal"; }

protected:
    void Eat() const noexcept override {}
};

struct MedicalDepartmentFixture {
    infrastructure::MedicalDepartment department;
    staff::Veterinarian vet{"Dr. Smith", 3000.0};
    std::unique_ptr<TestAnimal> animal;

    MedicalDepartmentFixture() {
        animal = std::make_unique<TestAnimal>("Lucky");

        auto book = std::make_unique<animals::medical::MedicalRecordBook>(animal->GetName());
        department.RegisterBook(animal->GetName(), std::move(book));
    }
};

SUITE(AnimalTests) {
  SUITE(BasicAnimalTests) {
    TEST_FIXTURE(MedicalDepartmentFixture, AnimalConstructor) {
      CHECK_EQUAL("Lucky", animal->GetName());
      CHECK_EQUAL("TestAnimal", animal->GetSpecies());
    }
  }

  SUITE(FishTests) {
    SUITE(BasicFishTests) {
      TEST(FishContructor) {
        Fish fish("Nemo", 3.5);
        CHECK_EQUAL("Nemo", fish.GetName());
        CHECK_EQUAL("Fish", fish.GetSpecies());
        CHECK_EQUAL(3.5, fish.GetSwimSpeed());

        CHECK_THROW(Fish invalid_fish("BadFish", -2.0), std::out_of_range);
        CHECK_THROW(Fish invalid_fish2("", 1.0), std::invalid_argument);
      }

      TEST(Fish_Getters) {
        Fish fish("Dory", 4.0);

        CHECK_EQUAL("Dory", fish.GetName());
        CHECK_EQUAL("Fish", fish.GetSpecies());
        CHECK_EQUAL(4.0, fish.GetSwimSpeed());
      }

      TEST(Fish_Setters) {
        Fish fish("Marlin", 5.0);
        
        fish.SetSwimSpeed(6.0);
        CHECK_EQUAL(6.0, fish.GetSwimSpeed());

        CHECK_THROW(fish.SetSwimSpeed(-3.0), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, FishBehavior) {
        Fish fish("Bubbles", 2.5);
        
        fish.Move();
        diver_feeder.Feed(fish);
      }
    }

    SUITE(SharkTests) {
      TEST(SharkContructor) {
        Shark shark("Jaws", 12.5);
        CHECK_EQUAL("Jaws", shark.GetName());
        CHECK_EQUAL("Shark", shark.GetSpecies());
        CHECK_EQUAL(12.5, shark.GetSwimSpeed());

        CHECK_THROW(Shark invalid_shark("BadShark", -3.0), std::out_of_range);
        CHECK_THROW(Shark invalid_shark2("", 1.0), std::invalid_argument);
      }

      TEST(Shark_Getters) {
        Shark shark("Bruce", 10.0);

        CHECK_EQUAL("Bruce", shark.GetName());
        CHECK_EQUAL("Shark", shark.GetSpecies());
        CHECK_EQUAL(10.0, shark.GetSwimSpeed());
      }

      TEST(Shark_Setters) {
        Shark shark("Jaws", 15.0);
        
        shark.SetSwimSpeed(20.0);
        CHECK_EQUAL(20.0, shark.GetSwimSpeed());

        CHECK_THROW(shark.SetSwimSpeed(-5.0), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, SharkBehavior) {
        Shark shark("Chomper", 14.0);
        shark.Move();
        diver_feeder.Feed(shark);
      }
    }

    SUITE(StingrayTests) {
      TEST(StingrayConstructor) {
        Stingray stingray("Stingy", 5.0, true, 1.5);
        CHECK_EQUAL("Stingy", stingray.GetName());
        CHECK_EQUAL("Stingray", stingray.GetSpecies());
        CHECK_EQUAL(true, stingray.IsVenomous());
        CHECK_EQUAL(1.5, stingray.GetFinSpan());
        CHECK_EQUAL(5.0, stingray.GetSwimSpeed());

        CHECK_THROW(Stingray invalid_stingray("BadRay", 4.0, false, -2.0),
                    std::out_of_range);
        CHECK_THROW(Stingray invalid_stingray2("BadRay", -4.0, false, 2.0),
                    std::out_of_range);
        CHECK_THROW(Stingray invalid_stingray3("", 4.0, false, 2.0),
                    std::invalid_argument);
      }

      TEST(Stingray_Getters) {
        Stingray stingray("Stingy", 5.0, true, 1.5);
        CHECK_EQUAL("Stingy", stingray.GetName());
        CHECK_EQUAL("Stingray", stingray.GetSpecies());
        CHECK_EQUAL(true, stingray.IsVenomous());
        CHECK_EQUAL(1.5, stingray.GetFinSpan());
        CHECK_EQUAL(5.0, stingray.GetSwimSpeed());
      }

      TEST(Stingray_Setters) {
        Stingray stingray("Ray", 7.0, true, 2.0);

        stingray.SetSwimSpeed(9.0);
        CHECK_EQUAL(9.0, stingray.GetSwimSpeed());

        stingray.SetFinSpan(3.0);
        CHECK_EQUAL(3.0, stingray.GetFinSpan());

        CHECK_THROW(stingray.SetFinSpan(-1.0), std::out_of_range);
        CHECK_THROW(stingray.SetFinSpan(15.0), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, StingrayBehavior) {
        Stingray stingray("Glider", 6.0, false, 2.5);
        stingray.Move();
        diver_feeder.Feed(stingray);
      }
    }
  }

  SUITE(MammalTests) {
    SUITE(BasicMammalTests) {
      TEST(MammalContructor) {
        Mammal mammal("GenericMammal", 5.0);
        CHECK_EQUAL("GenericMammal", mammal.GetName());
        CHECK_EQUAL("Mammal", mammal.GetSpecies());
        CHECK_EQUAL(5.0, mammal.GetMilkProduction());

        CHECK_THROW(Mammal invalid_mammal("BadMammal", -3.0),
                    std::out_of_range);
        CHECK_THROW(Mammal invalid_mammal2("", 2.0),
                    std::invalid_argument);
      }

      TEST(Mammal_Getters) {
        Mammal mammal("Manny", 6.0);

        CHECK_EQUAL("Manny", mammal.GetName());
        CHECK_EQUAL("Mammal", mammal.GetSpecies());
        CHECK_EQUAL(6.0, mammal.GetMilkProduction());
      }

      TEST(Mammal_Setters) {
        Mammal mammal("Maggie", 4.0);
        
        mammal.SetMilkProduction(7.0);
        CHECK_EQUAL(7.0, mammal.GetMilkProduction());

        CHECK_THROW(mammal.SetMilkProduction(-2.0), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, MammalBehavior) {
        Mammal mammal("Generic", 3.0);
        
        mammal.Move();
        diver_feeder.Feed(mammal);
      }
    }

    SUITE(BasicSeaMammalTests) {
      TEST(SeaMammalContructor) {
        SeaMammal sea_mammal("GenericSeaMammal", 4.0, 100.0, 200.0);
        CHECK_EQUAL("GenericSeaMammal", sea_mammal.GetName());
        CHECK_EQUAL("Sea Mammal", sea_mammal.GetSpecies());
        CHECK_EQUAL(4.0, sea_mammal.GetMilkProduction());
        CHECK_EQUAL(100.0, sea_mammal.GetDiveDepth());
        CHECK_EQUAL(200.0, sea_mammal.GetBreathHoldTime());

        CHECK_THROW(SeaMammal invalid_sea_mammal("BadSeaMammal", -3.0, 100.0, 200.0),
                    std::out_of_range);
        CHECK_THROW(SeaMammal invalid_sea_mammal2("BadSeaMammal", 3.0, -100.0, 200.0),
                    std::out_of_range);
        CHECK_THROW(SeaMammal invalid_sea_mammal3("BadSeaMammal", 3.0, 100.0, -200.0),
                    std::out_of_range);
        CHECK_THROW(SeaMammal invalid_sea_mammal4("", 3.0, 100.0, 200.0),
                    std::invalid_argument);
      }

      TEST(SeaMammal_Getters) {
        SeaMammal sea_mammal("Sammy", 5.0, 120.0, 250.0);

        CHECK_EQUAL("Sammy", sea_mammal.GetName());
        CHECK_EQUAL("Sea Mammal", sea_mammal.GetSpecies());
        CHECK_EQUAL(5.0, sea_mammal.GetMilkProduction());
        CHECK_EQUAL(120.0, sea_mammal.GetDiveDepth());
        CHECK_EQUAL(250.0, sea_mammal.GetBreathHoldTime());
      }

      TEST(SeaMammal_Setters) {
        SeaMammal sea_mammal("Sally", 6.0, 130.0, 300.0);
        
        sea_mammal.SetMilkProduction(8.0);
        CHECK_EQUAL(8.0, sea_mammal.GetMilkProduction());

        CHECK_THROW(sea_mammal.SetMilkProduction(-4.0), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, SeaMammalBehavior) {
        SeaMammal sea_mammal("GenericSea", 4.0, 110.0, 220.0);
        
        sea_mammal.Move();
        diver_feeder.Feed(sea_mammal);
      }
    }

    SUITE(DolphinTests) {
      TEST(DolphinContructor) {
        Dolphin dolphin("Dolly", 4, 80.0, 120.0, 130);
        CHECK_EQUAL("Dolly", dolphin.GetName());
        CHECK_EQUAL("Dolphin", dolphin.GetSpecies());
        CHECK_EQUAL(4, dolphin.GetMilkProduction());
        CHECK_EQUAL(80.0, dolphin.GetDiveDepth());
        CHECK_EQUAL(120.0, dolphin.GetBreathHoldTime());
        CHECK_EQUAL(130, dolphin.GetIQ());

        CHECK_THROW(Dolphin invalid_dolphin("BadDolphin", 4, 80.0, 120.0, -10),
                    std::out_of_range);
        CHECK_THROW(Dolphin invalid_dolphin2("", 4, 80.0, 120.0, 100),
                    std::invalid_argument);
        CHECK_THROW(Dolphin invalid_dolphin3("BadDolphin", -2, 80.0, 120.0, 100),
                    std::out_of_range);
        CHECK_THROW(Dolphin invalid_dolphin4("BadDolphin", 4, -80.0, 120.0, 100),
                    std::out_of_range);
        CHECK_THROW(Dolphin invalid_dolphin5("BadDolphin", 4, 80.0, -120.0, 100),
                    std::out_of_range);
      }

      TEST(Dolphin_Getters) {
        Dolphin dolphin("Dolly", 4, 80.0, 120.0, 130);
        CHECK_EQUAL("Dolly", dolphin.GetName());
        CHECK_EQUAL("Dolphin", dolphin.GetSpecies());
        CHECK_EQUAL(4, dolphin.GetMilkProduction());
        CHECK_EQUAL(80.0, dolphin.GetDiveDepth());
        CHECK_EQUAL(120.0, dolphin.GetBreathHoldTime());
        CHECK_EQUAL(130, dolphin.GetIQ());
      }

      TEST(Dolphin_Setters) {
        Dolphin dolphin("Duke", 5, 90.0, 150.0, 140);

        dolphin.SetMilkProduction(6);
        CHECK_EQUAL(6, dolphin.GetMilkProduction());
        CHECK_THROW(dolphin.SetMilkProduction(-2), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, DolphinBehavior) {
        Dolphin dolphin("Flipper", 3, 70.0, 110.0, 121);

        dolphin.Move();

        diver_feeder.Feed(dolphin);
        
        CHECK_THROW(dolphin.Draw(), utils::exceptions::CannotPerformActionException);

        CHECK_EQUAL(false, dolphin.CanDraw());
        trainer.TeachDrawing(dolphin);
        CHECK_EQUAL(true, dolphin.CanDraw());
        dolphin.Draw();

        Dolphin low_iq_dolphin("LowIQ", 3, 70.0, 110.0, 100);
        CHECK_THROW(trainer.TeachDrawing(low_iq_dolphin), utils::exceptions::CannotPerformActionException);
        CHECK_EQUAL(false, low_iq_dolphin.CanDraw());
      }
    }

    SUITE(SealTests) {
      TEST(SealContructor) {
        Seal seal("Sammy", 3, 150.0, 200.0);
        CHECK_EQUAL("Sammy", seal.GetName());
        CHECK_EQUAL("Seal", seal.GetSpecies());
        CHECK_EQUAL(3, seal.GetMilkProduction());
        CHECK_EQUAL(150.0, seal.GetDiveDepth());
        CHECK_EQUAL(200.0, seal.GetBreathHoldTime());

        CHECK_THROW(Seal invalid_seal("BadSeal", -3, 150.0, 200.0),
                    std::out_of_range);
        CHECK_THROW(Seal invalid_seal2("", 3, 150.0, 200.0),
                    std::invalid_argument);
        CHECK_THROW(Seal invalid_seal3("BadSeal", 3, -150.0, 200.0),
                    std::out_of_range);
        CHECK_THROW(Seal invalid_seal4("BadSeal", 3, 150.0, -200.0),
                    std::out_of_range);
      }

      TEST(SealGetters) {
        Seal seal("Sammy", 3, 150.0, 200.0);
        CHECK_EQUAL("Sammy", seal.GetName());
        CHECK_EQUAL("Seal", seal.GetSpecies());
        CHECK_EQUAL(3, seal.GetMilkProduction());
        CHECK_EQUAL(150.0, seal.GetDiveDepth());
        CHECK_EQUAL(200.0, seal.GetBreathHoldTime());
      }

      TEST(SealSetters) {
        Seal seal("Sally", 4, 160.0, 220.0);

        seal.SetMilkProduction(5);
        CHECK_EQUAL(5, seal.GetMilkProduction());
        CHECK_THROW(seal.SetMilkProduction(-1), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, SealBehavior) {
        Seal seal("Bobby", 2, 140.0, 180.0);

        seal.Move();

        diver_feeder.Feed(seal);

        CHECK_THROW(seal.BalanceBall(), utils::exceptions::CannotPerformActionException);    
  
        CHECK_EQUAL(false, seal.CanBalanceBall());
        trainer.TeachBallBalancing(seal);
        CHECK_EQUAL(true, seal.CanBalanceBall());
        seal.BalanceBall();
      }
    }
  }

  SUITE(ReptileTests) {
    SUITE(BasicReptileTests) {
      TEST(ReptileContructor) {
        Reptile reptile("GenericReptile", 25.0);
        CHECK_EQUAL("GenericReptile", reptile.GetName());
        CHECK_EQUAL("Reptile", reptile.GetSpecies());
        CHECK_EQUAL(25.0, reptile.GetBodyTemperature());

        CHECK_THROW(Reptile invalid_reptile("BadReptile", -10.0),
                    std::out_of_range);
        CHECK_THROW(Reptile invalid_reptile2("", 20.0),
                    std::invalid_argument);
      }

      TEST(Reptile_Getters) {
        Reptile reptile("Rex", 30.0);

        CHECK_EQUAL("Rex", reptile.GetName());
        CHECK_EQUAL("Reptile", reptile.GetSpecies());
        CHECK_EQUAL(30.0, reptile.GetBodyTemperature());
      }

      TEST(Reptile_Setters) {
        Reptile reptile("Rango", 28.0);
        
        reptile.SetBodyTemperature(32.0);
        CHECK_EQUAL(32.0, reptile.GetBodyTemperature());

        CHECK_THROW(reptile.SetBodyTemperature(-5.0), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, ReptileBehavior) {
        Reptile reptile("Lizzy", 27.0);
        
        reptile.Move();
        diver_feeder.Feed(reptile);
      }
    }

    SUITE(SeaTurtleTests) {
      TEST(SeaTurtleConstructor) {
        SeaTurtle turtle("Shelly", 20.0, 80.0);
        CHECK_EQUAL("Shelly", turtle.GetName());
        CHECK_EQUAL("Sea Turtle", turtle.GetSpecies());
        CHECK_EQUAL(20.0, turtle.GetBodyTemperature());
        CHECK_EQUAL(80.0, turtle.GetShellDiameter());

        CHECK_THROW(SeaTurtle invalid_turtle("BadTurtle", -50.0, 80.0),
                    std::out_of_range);
        CHECK_THROW(SeaTurtle invalid_turtle2("BadTurtle", 50.0, -80.0),
                    std::out_of_range);
        CHECK_THROW(SeaTurtle invalid_turtle3("", 50.0, 80.0),
                    std::invalid_argument);
      }

      TEST(SeaTurtleGetters) {
        SeaTurtle turtle("Shelly", 20.0, 80.0);
        CHECK_EQUAL("Shelly", turtle.GetName());
        CHECK_EQUAL("Sea Turtle", turtle.GetSpecies());
        CHECK_EQUAL(20.0, turtle.GetBodyTemperature());
        CHECK_EQUAL(80.0, turtle.GetShellDiameter());
      }

      TEST(SeaTurtleSetters) {
        SeaTurtle turtle("Tommy", 22.0, 90.0);

        turtle.SetBodyTemperature(25.0);
        CHECK_EQUAL(25.0, turtle.GetBodyTemperature());
        CHECK_THROW(turtle.SetBodyTemperature(-10.0), std::out_of_range);
      }

      TEST_FIXTURE(AnimalFixture, SeaTurtleBehavior) {
        SeaTurtle turtle("Tina", 18.0, 75.0);
        turtle.Move();

        diver_feeder.Feed(turtle);
      }
    }
  }

  SUITE(MedialTests) {
    SUITE(DiagnosisTests) {
      TEST(DiagnosisConstructor) {
        Diagnosis diagnosis(DiagnosisType::kHealthy);
        CHECK(diagnosis.GetType() == DiagnosisType::kHealthy);
      }

      TEST(DiagnosisGetters) {
        Diagnosis healthy(DiagnosisType::kHealthy);
        CHECK(healthy.GetType() == DiagnosisType::kHealthy);
        CHECK_EQUAL("Healthy", healthy.ToString());
        CHECK_EQUAL("The animal is healthy.", healthy.GetDescription());

        Diagnosis cold(DiagnosisType::kCold);
        CHECK(cold.GetType() == DiagnosisType::kCold);
        CHECK_EQUAL("Cold", cold.ToString());
        CHECK_EQUAL("Signs of a mild cold.", cold.GetDescription());

        Diagnosis injury(DiagnosisType::kInjury);
        CHECK(injury.GetType() == DiagnosisType::kInjury);
        CHECK_EQUAL("Injury", injury.ToString());
        CHECK_EQUAL("Detected a minor injury.", injury.GetDescription());

        Diagnosis infection(DiagnosisType::kInfection);
        CHECK(infection.GetType() == DiagnosisType::kInfection);
        CHECK_EQUAL("Infection", infection.ToString());
        CHECK_EQUAL("Possible bacterial infection.", infection.GetDescription());
      }
    }

    SUITE(MedicalRecordTests) {
      TEST(MedicalRecordConstructorAndGetters) {
        using clock = std::chrono::system_clock;

        auto before_creation = clock::now();
        MedicalRecord record(Diagnosis(DiagnosisType::kCold));
        auto after_creation = clock::now();

        auto creation = record.GetCreationDate();

        CHECK(creation >= before_creation);
        CHECK(creation <= after_creation);
        CHECK(record.GetDiagnosis().GetType() == DiagnosisType::kCold);

        std::regex date_pattern(R"(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})");
        CHECK(std::regex_match(record.GetFormattedCreationDate(), date_pattern));
      }
    }

    SUITE(MedicalRecordBookTests) {
      TEST(MedicalRecordBookConstructor) {
        MedicalRecordBook record_book("Leo");
        CHECK_EQUAL("Leo", record_book.GetOwner());
        CHECK_EQUAL(true, !record_book.GetLastRecord().has_value());

        CHECK_THROW(MedicalRecordBook invalid_book(""),
                    std::invalid_argument);
      }

      TEST_FIXTURE(MedicalDepartmentFixture, MedicalRecordBookOperations) {
        auto summary_initial = department.GetSummary(animal->GetName());
        CHECK(summary_initial.find("No medical records") != std::string::npos);

        Diagnosis diag_cold(DiagnosisType::kCold);
        vet.Diagnose(*animal, department, diag_cold);

        auto summary_after_cold = department.GetSummary(animal->GetName());
        CHECK(summary_after_cold.find("Cold") != std::string::npos);

        Diagnosis diag_injury(DiagnosisType::kInjury);
        vet.Diagnose(*animal, department, diag_injury);

        auto summary_final = department.GetSummary(animal->GetName());
        CHECK(summary_final.find("Cold") != std::string::npos);
        CHECK(summary_final.find("Injury") != std::string::npos);

        auto last_record_opt = department.GetRecordBooks().at(animal->GetName())->GetLastRecord();
        CHECK(last_record_opt.has_value());
        CHECK((*last_record_opt)->GetDiagnosis().GetType() == DiagnosisType::kInjury);

        auto all_records = department.GetRecordBooks().at(animal->GetName())->GetRecords();
        CHECK_EQUAL(2u, all_records.size());
        CHECK(all_records[0]->GetDiagnosis().GetType() == DiagnosisType::kCold);
        CHECK(all_records[1]->GetDiagnosis().GetType() == DiagnosisType::kInjury);
      }
    }
  }
}

#endif  // ANIMALS_TEST_CC_