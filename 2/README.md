Animal 1 2 -> Fish, Mammal, Reptile
Fish 1 2 -> Shark, Stingray
Shark 1 2 ->
Stingray 3 2 ->
Mammal 2 2 -> SeaMammal
SeaMammal 4 2 -> Dolphin, Seal
Dolphin 6 5 ->
Seal 5 5 ->
Reptile 2 2 -> SeaTurtle
SeaTurtle 3 2 ->
Diagnosis 1 0 ->
MedicalRecord 2 0 ->
MedicalRecordBook 2 3 -> 
IPaymentMethod 0 1 -> CashPayment
IAccountPaymentMethod 0 1 -> CardPayment
CashPayment 2 1 -> 
CardPayment 2 1 -> OnlineCardPayment
OnlineCardPayment 3 2 ->
Account 2 3 ->
PaymentContext 1 0 ->
Ticket 3 1 ->
Transaction 6 2 ->
Employee 2 0 -> Cashier, DiverFeeder, Trainer, Veterinarian
Cashier 2 2 ->
DiverFeeder 3 1 ->
Trainer 2 2 ->
Veterinarian 2 1 ->
Visitor 3 1 -> 
Tank 5 1 ->
ScheduleEvent 3 1 -> 
Schedule 1 5 ->
Member 3 3 ->
MembershipSystem 1 4 ->
MedicalDepartment 1 3 ->
MaintenanceUnit 1 3 ->
EmployeeInfo 3 0 ->
HumanResources 1 3 ->
Ecosystem 1 3 ->
Aquarium 8 2 ->
IDGenerator 1 1 ->
BaseException 0 0 -> NotFoundError, AlreadyExistsError, PaymentError, UnknownTypeError, CannotPerformActionException, ClosedAquariumError
AlreadyExistsError 0 0 -> MemberAlreadyExistsError
CannotPerformActionException 0 0 ->
MemberAlreadyExistsError 0 0 ->
ClosedAquariumError 0 0 ->
NotFoundError 0 0 -> EmployeeNotFoundError, MedicalRecordBookNotFoundError, TankNotFoundError, MemberNotFoundError
EmployeeNotFoundError 0 0 ->
MedicalRecordBookNotFoundError 0 0 ->
TankNotFoundError 0 0 ->
MemberNotFoundError 0 0 ->
PaymentError 0 0 -> InsufficientFundsError, CardVerificationError, TransactionAlreadyProcessedError, MismatchingPaymentMethodError
UnknownTypeError 0 0 -> UnknownDiagnosisTypeError, UnknownTicketTypeError, UnknownMembershipTypeError
InsufficientFundsError 0 0 ->
CardVerificationError 0 0 -> 
TransactionAlreadyProcessedError 0 0 -> 
UnknownDiagnosisTypeError 0 0 ->
UnknownTicketTypeError 0 0 ->
UnknownMembershipTypeError 0 0 ->