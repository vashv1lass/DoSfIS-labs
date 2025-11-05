#include <UnitTest++/UnitTest++.h>

#include <chrono>

#include "infrastructure/infrastructure.h"
#include "utils/utils.h"
#include "animals/animals.h"
#include "staff/staff.h"

using namespace infrastructure;

SUITE(EcosystemTests) {
  TEST(AddAnimal) {
    Ecosystem eco;
    auto fish = std::make_unique<animals::Fish>("Nemo", 20);
    eco.AddAnimal(std::move(fish));
    CHECK_THROW(eco.AddAnimal(nullptr), std::invalid_argument);

    CHECK_EQUAL(1u, eco.GetCount());
  }

  TEST(GetStatusReport) {
    Ecosystem eco;
    eco.AddAnimal(std::make_unique<animals::Fish>("Nemo", 20));
    eco.AddAnimal(std::make_unique<animals::Fish>("Dory", 15));

    auto report = eco.GetStatusReport();
    CHECK_EQUAL(2u, report.size());
    CHECK_EQUAL("Nemo (Fish)", report[0]);
    CHECK_EQUAL("Dory (Fish)", report[1]);
  }

  TEST(GetCount) {
    Ecosystem eco;
    CHECK_EQUAL(0u, eco.GetCount());
    eco.AddAnimal(std::make_unique<animals::Fish>("Nemo", 20));
    eco.AddAnimal(std::make_unique<animals::Fish>("Marlin", 10));
    CHECK_EQUAL(2u, eco.GetCount());
  }
}

SUITE(HumanResourcesTests) {
  SUITE(EmployeeInfoTests) {
    TEST(ConstructorValid) {
      EmployeeInfo info("Alice", "Biologist", 5000);
      CHECK_EQUAL("Alice", info.name);
      CHECK_EQUAL("Biologist", info.role);
      CHECK_EQUAL(5000, info.salary);
    }
  }

  SUITE(HumanResourcesSystemTests) {
    TEST(HireEmployee) {
      HumanResources hr;
      auto emp = std::make_unique<staff::Veterinarian>("Bob", 3000);
      hr.Hire(std::move(emp));
      CHECK_THROW(hr.Hire(nullptr), std::invalid_argument);

      auto list = hr.ListEmployees();
      CHECK_EQUAL(1, list.size());
      CHECK_EQUAL("Bob", list[0].name);
      CHECK_EQUAL("Veterinarian", list[0].role);
      CHECK_EQUAL(3000, list[0].salary);
    }

    TEST(FireEmployee) {
      HumanResources hr;
      hr.Hire(std::make_unique<staff::Veterinarian>("Carl", 3500));
      hr.Fire("Carl");

      // После удаления список должен быть пуст
      auto list = hr.ListEmployees();
      CHECK_EQUAL(0, list.size());

      CHECK_THROW(hr.Fire("Ghost"), utils::exceptions::EmployeeNotFoundError);
    }

    TEST(FindEmployee) {
      HumanResources hr;
      hr.Hire(std::make_unique<staff::Veterinarian>("Eve", 2500));
      hr.Hire(std::make_unique<staff::Veterinarian>("Finn", 4500));

      auto* found = hr.FindEmployee("Finn");
      CHECK(found != nullptr);
      CHECK_EQUAL("Finn", found->GetName());

      CHECK(hr.FindEmployee("Nobody") == nullptr);
    }

    TEST(ListEmployees) {
      HumanResources hr;
      CHECK_EQUAL(0, hr.ListEmployees().size());

      hr.Hire(std::make_unique<staff::Veterinarian>("Hana", 3200));
      hr.Hire(std::make_unique<staff::Veterinarian>("Ivan", 2700));

      auto list = hr.ListEmployees();
      CHECK_EQUAL(2, list.size());
      CHECK_EQUAL("Hana", list[0].name);
      CHECK_EQUAL("Ivan", list[1].name);
    }
  }
}

SUITE(MaintenanceTests) {
  TEST(RegisterTank) {
    MaintenanceUnit unit;
    unit.RegisterTank(std::make_shared<Tank>(10, 100));
    CHECK_THROW(unit.RegisterTank(nullptr), std::invalid_argument);
  }

  TEST(CleanTank) {
    utils::IDGenerator::Instance().Reset();
    MaintenanceUnit unit;

    auto tank = std::make_shared<Tank>(15, 200);
    tank->MarkDirty();
    CHECK(!tank->IsClean());

    unit.RegisterTank(tank);
    unit.CleanTank(tank->GetID());

    CHECK(tank->IsClean());

    CHECK_THROW(unit.CleanTank(999), utils::exceptions::TankNotFoundError);
  }
}

SUITE(MedicalDepartmentTests) {
  TEST(RegisterBookInvalid) {
    MedicalDepartment mdpt;
    CHECK_THROW(mdpt.RegisterBook("", nullptr), std::invalid_argument);
    CHECK_THROW(mdpt.RegisterBook("aa", nullptr), std::invalid_argument);
  }

  TEST(AddRecordInvalid) {
    staff::Veterinarian vet("Victor", 2500);
    MedicalDepartment mdpt;
    CHECK_THROW(mdpt.AddRecord("zzzz", animals::medical::Diagnosis(animals::medical::DiagnosisType::kHealthy), vet),
                utils::exceptions::MedicalRecordBookNotFoundError);
  }

  TEST(GetSummaryInvalid) {
    MedicalDepartment mdpt;
    CHECK_THROW(mdpt.GetSummary("bbbbb"), utils::exceptions::MedicalRecordBookNotFoundError);
  }
}

SUITE(MembershipTests) {
  SUITE(MemberTests) {
    TEST(MemberConstructor) {
      Member member("Alice", MembershipLevel::kBasic);
      CHECK_EQUAL("Alice", member.GetName());
      CHECK(member.GetLevel() == MembershipLevel::kBasic);
      CHECK_EQUAL(0, member.GetPoints());

      CHECK_THROW(Member("", MembershipLevel::kBasic), std::invalid_argument);
    }

    TEST(MemberAddPoints) {
      Member member("Bob", MembershipLevel::kSilver);
      member.AddPoints(30);
      CHECK_EQUAL(30, member.GetPoints());

      member.AddPoints(10);
      CHECK_EQUAL(40, member.GetPoints());

      CHECK_THROW(member.AddPoints(-5), std::out_of_range);
    }

    TEST(MemberRedeemPoints) {
      Member member("Daisy", MembershipLevel::kBasic);
      member.AddPoints(20);
      member.RedeemPoints(10);
      CHECK_EQUAL(10, member.GetPoints());

      CHECK_THROW(member.RedeemPoints(100), std::runtime_error);
    }

    TEST(UpgradeFromBasic) {
      Member member("Frank", MembershipLevel::kBasic);
      member.AddPoints(20);
      member.Upgrade();
      CHECK(member.GetLevel() == MembershipLevel::kSilver);
      CHECK_EQUAL(10, member.GetPoints());
    }

    TEST(UpgradeFromSilver) {
      Member member("Greg", MembershipLevel::kSilver);
      member.AddPoints(100);
      member.Upgrade();
      CHECK(member.GetLevel() == MembershipLevel::kGold);
    }

    TEST(UpgradeFromGold) {
      Member member("Henry", MembershipLevel::kGold);
      member.AddPoints(100);
      member.Upgrade();
      CHECK(member.GetLevel() == MembershipLevel::kPlatinum);
    }

    TEST(UpgradeFromPlatinum) {
      Member member("Isabella", MembershipLevel::kPlatinum);
      CHECK_THROW(member.Upgrade(), std::runtime_error);
    }
  }

  SUITE(MembershipSystemTests) {
    TEST(RegisterMember) {
      MembershipSystem system;
      system.RegisterMember("John", MembershipLevel::kBasic);
      CHECK_EQUAL(0, system.GetMemberPoints("John"));
      CHECK_THROW(system.RegisterMember("John", MembershipLevel::kBasic),
                  utils::exceptions::MemberAlreadyExistsError);
    }

    TEST(AddPoints) {
      MembershipSystem system;
      system.RegisterMember("Leo", MembershipLevel::kBasic);
      system.AddPoints("Leo", 30);
      CHECK_EQUAL(30, system.GetMemberPoints("Leo"));
      CHECK_THROW(system.AddPoints("Missing", 10),
                  utils::exceptions::MemberNotFoundError);
    }

    TEST(RedeemPoints) {
      MembershipSystem system;
      system.RegisterMember("Mira", MembershipLevel::kBasic);
      system.AddPoints("Mira", 50);
      system.RedeemPoints("Mira", 30);
      CHECK_EQUAL(20, system.GetMemberPoints("Mira"));
      CHECK_THROW(system.RedeemPoints("Mira", 100), std::runtime_error);
      CHECK_THROW(system.RedeemPoints("Ghost", 5),
                  utils::exceptions::MemberNotFoundError);
    }

    TEST(GetMemberPointsNonexistent) {
      MembershipSystem system;
      CHECK_THROW(system.GetMemberPoints("Unknown"),
                  utils::exceptions::MemberNotFoundError);
    }
  }
}

SUITE(ScheduleTests) {
  SUITE(ScheduleEventTests) {
    TEST(ScheduleEventConstructor) {
      bool called = false;
      auto now = std::chrono::system_clock::now();
      ScheduleEvent event("Feed Fish", now, [&called]() { called = true; });

      CHECK_EQUAL("Feed Fish", event.GetName());
      CHECK(event.GetTime() == now);

      event.ExecuteIfDue();
      CHECK(called);

      CHECK_THROW(ScheduleEvent invalid_event("", now, []() {}), std::invalid_argument);
      CHECK_THROW(ScheduleEvent invalid_event2("No action", now, nullptr), std::invalid_argument);
    }

    TEST(ScheduleEventExecuteIfDue) {
      bool called = false;
      auto past_time = std::chrono::system_clock::now() - std::chrono::seconds(1);
      ScheduleEvent event("Past Event", past_time, [&called]() { called = true; });

      event.ExecuteIfDue();
      CHECK(called);
    }

    TEST(ScheduleEventNotDueYet) {
      bool called = false;
      auto future_time = std::chrono::system_clock::now() + std::chrono::seconds(1);
      ScheduleEvent event("Future Event", future_time, [&called]() { called = true; });

      event.ExecuteIfDue();
      CHECK(!called);
    }
  }

  SUITE(ScheduleSystemTests) {
   TEST(ScheduleAddAndGetAllEvents) {
    Schedule schedule;

    auto now = std::chrono::system_clock::now();
    schedule.AddEvent(std::make_unique<ScheduleEvent>("Feed", now, []() {}));
    schedule.AddEvent(std::make_unique<ScheduleEvent>("Clean", now + std::chrono::minutes(10), []() {}));
    CHECK_THROW(schedule.AddEvent(nullptr), std::invalid_argument);

    auto events = schedule.GetAllEvents();
    CHECK_EQUAL(2, events.size());
    CHECK_EQUAL("Feed", events[0]->GetName());
    CHECK_EQUAL("Clean", events[1]->GetName());
    }

    TEST(ScheduleRemoveEvent) {
      Schedule schedule;
      auto now = std::chrono::system_clock::now();

      schedule.AddEvent(std::make_unique<ScheduleEvent>("Feed", now, []() {}));
      schedule.AddEvent(std::make_unique<ScheduleEvent>("Clean", now, []() {}));

      schedule.RemoveEvent("Feed");

      auto events = schedule.GetAllEvents();
      CHECK_EQUAL(1, events.size());
      CHECK_EQUAL("Clean", events[0]->GetName());
    }

    TEST(ScheduleGetNextEvent) {
      Schedule schedule;
      CHECK(schedule.GetNextEvent() == nullptr);
      
      auto now = std::chrono::system_clock::now();
      
      schedule.AddEvent(std::make_unique<ScheduleEvent>("Past", now - std::chrono::minutes(5), []() {}));
      CHECK(schedule.GetNextEvent() == nullptr);

      schedule.AddEvent(std::make_unique<ScheduleEvent>("Future", now + std::chrono::minutes(5), []() {}));

      const ScheduleEvent* next = schedule.GetNextEvent();
      CHECK(next != nullptr);
      CHECK_EQUAL("Future", next->GetName());
    }

    TEST(ScheduleExecuteDueEvents) {
      Schedule schedule;

      bool called1 = false;
      bool called2 = false;

      auto past = std::chrono::system_clock::now() - std::chrono::minutes(2);
      auto future = std::chrono::system_clock::now() + std::chrono::minutes(2);

      schedule.AddEvent(std::make_unique<ScheduleEvent>("Past1", past, [&]() { called1 = true; }));
      schedule.AddEvent(std::make_unique<ScheduleEvent>("Future1", future, [&]() { called2 = true; }));

      schedule.ExecuteDueEvents();

      CHECK(called1);
      CHECK(!called2);
    }

    TEST(ScheduleGetSummary) {
      Schedule schedule;
      auto now = std::chrono::system_clock::now();

      schedule.AddEvent(std::make_unique<ScheduleEvent>("Feed", now, []() {}));
      schedule.AddEvent(std::make_unique<ScheduleEvent>("Clean", now + std::chrono::minutes(30), []() {}));

      std::string summary = schedule.GetSummary();
      CHECK(summary.find("Feed") != std::string::npos);
      CHECK(summary.find("Clean") != std::string::npos);
      CHECK(summary.find("Schedule Overview") != std::string::npos);
    }
  }
}

SUITE(TankTests) {
  TEST(TankConstructor) {
    utils::IDGenerator::Instance().Reset();
    Tank tank(12, 100);
    CHECK_CLOSE(12, tank.GetDepth(), 1e-6);
    CHECK_CLOSE(100, tank.GetVolume(), 1e-6);
    CHECK_EQUAL(1, tank.GetID());

    CHECK_THROW(Tank invalid_tank1(-1, 100), std::out_of_range);
    CHECK_THROW(Tank invalid_tank2(12, -100), std::out_of_range);
  }

  TEST(TankSetters) {
    Tank tank(12, 100);
    
    tank.SetDepth(14);
    CHECK_CLOSE(14, tank.GetDepth(), 1e-6);
    CHECK_THROW(tank.SetDepth(-1), std::out_of_range);
    
    tank.SetVolume(120);
    CHECK_CLOSE(120, tank.GetVolume(), 1e-6);
    CHECK_THROW(tank.SetVolume(-10), std::out_of_range);

    tank.MarkClean();
    CHECK(tank.IsClean());

    tank.MarkDirty();
    CHECK(!tank.IsClean());
  }

  TEST(TankAddAnimal) {
    utils::IDGenerator::Instance().Reset();
    Tank tank(12, 100);
    tank.AddAnimal(std::make_shared<animals::Fish>(animals::Fish("Fish", 5)));
    tank.AddAnimal(std::make_shared<animals::Shark>(animals::Shark("Sharky", 2)));
    CHECK_THROW(tank.AddAnimal(nullptr), std::invalid_argument);

    const auto& tank_habitats = tank.GetAnimals();
    CHECK_EQUAL(2, tank_habitats.size());
    CHECK_EQUAL("Fish", tank_habitats[0]->GetName());
    CHECK_EQUAL("Sharky", tank_habitats[1]->GetName());
  }
}

SUITE(VisitorTests) {
  TEST(VisitorConstructor) {
    Visitor visitor_adult("Anton", 20);
    CHECK_EQUAL("Anton", visitor_adult.GetName());
    CHECK_EQUAL(20, visitor_adult.GetAge());

    Visitor visitor_child("Zlata", 5);
    CHECK_EQUAL("Zlata", visitor_child.GetName());
    CHECK_EQUAL(5, visitor_child.GetAge());

    CHECK_THROW(Visitor invalid_visitor1("", 25), std::invalid_argument);
    CHECK_THROW(Visitor invalid_visitor2("Aaron", -1), std::out_of_range);
  }

  TEST(VisitorAddTicket) {
    Visitor visitor("Seva", 18);
    visitor.AddTicket(payment::Ticket(payment::TicketCategory::kBase));
    CHECK_THROW(visitor.AddTicket(payment::Ticket(payment::TicketCategory::kChildBase)), std::invalid_argument);
    
    Visitor child_visitor("Hujkin Victor Ebat\'evich", 12);
    child_visitor.AddTicket(payment::Ticket(payment::TicketCategory::kChildBase));
    CHECK_THROW(child_visitor.AddTicket(payment::Ticket(payment::TicketCategory::kBase)), std::invalid_argument);
  }

  TEST(VisitorGetters) {
    Visitor visitor("Maxim", 20);
    visitor.AddTicket(payment::Ticket(payment::TicketCategory::kBase));
    visitor.AddTicket(payment::Ticket(payment::TicketCategory::kVip));

    CHECK_EQUAL("Maxim", visitor.GetName());
    CHECK_EQUAL(20, visitor.GetAge());
    
    std::vector<payment::Ticket> tickets = visitor.GetTickets();
    CHECK_EQUAL(2, tickets.size());
    CHECK(tickets[0].GetCategory() == payment::TicketCategory::kBase);
    CHECK(tickets[1].GetCategory() == payment::TicketCategory::kVip);
  }
}

SUITE(AquariumTests) {
  TEST(InstanceIsSingleton) {
    Aquarium& a1 = Aquarium::Instance();
    Aquarium& a2 = Aquarium::Instance();
    CHECK_EQUAL(&a1, &a2);
  }

  TEST(AquariumGetters) {
    Aquarium& aq = Aquarium::Instance();
    aq.Open();

    aq.GetEcosystem();
    aq.GetHumanResources();
    aq.GetMaintenanceUnit();
    aq.GetMembershipSystem();
    aq.GetPaymentContext();
    aq.GetSchedule();

    aq.Close();
    CHECK_THROW(aq.GetEcosystem(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetHumanResources(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetMaintenanceUnit(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetMembershipSystem(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetPaymentContext(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetSchedule(), utils::exceptions::ClosedAquariumError);
  }

  TEST(ConstAquariumGetters) {
    const Aquarium& aq = Aquarium::Instance();
    const_cast<Aquarium&>(aq).Open();

    aq.GetEcosystem();
    aq.GetHumanResources();
    aq.GetMaintenanceUnit();
    aq.GetMembershipSystem();
    aq.GetPaymentContext();
    aq.GetSchedule();

    const_cast<Aquarium&>(aq).Close();
    CHECK_THROW(aq.GetEcosystem(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetHumanResources(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetMaintenanceUnit(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetMembershipSystem(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetPaymentContext(), utils::exceptions::ClosedAquariumError);
    CHECK_THROW(aq.GetSchedule(), utils::exceptions::ClosedAquariumError);
  }
}