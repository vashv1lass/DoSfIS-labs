#include "animals/medical/medical.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace animals {
namespace medical {

MedicalRecord::MedicalRecord(Diagnosis diagnosis)
    : diagnosis_(std::move(diagnosis)),
      created_at_(std::chrono::system_clock::now()) {
  if (treatment_plan_.empty()) {
    throw std::invalid_argument("Treatment plan cannot be empty.");
  }
}

const Diagnosis& MedicalRecord::GetDiagnosis() const noexcept {
  return diagnosis_;
}

std::chrono::system_clock::time_point MedicalRecord::GetCreationDate() const noexcept {
  return created_at_;
}

std::string MedicalRecord::GetFormattedCreationDate() const {
  std::time_t t = std::chrono::system_clock::to_time_t(created_at_);

  std::ostringstream oss;
  oss << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S");

  return oss.str();
}

MedicalRecordBook::MedicalRecordBook(std::string owner)
    : owner_(std::move(owner)) {
  if (owner_.empty()) {
    throw std::invalid_argument("Owner name cannot be empty.");
  }
}

void MedicalRecordBook::AddRecord(std::unique_ptr<MedicalRecord> record) {
  if (!record) {
    throw std::invalid_argument("Cannot add null medical record.");
  }
  records_.push_back(std::move(record));
}

std::optional<const MedicalRecord*> MedicalRecordBook::GetLastRecord() const noexcept {
  if (records_.empty()) {
    return std::nullopt;
  }
  return records_.back().get();
}

std::vector<const MedicalRecord*> MedicalRecordBook::GetRecords() const noexcept {
  std::vector<const MedicalRecord*> result;
  result.reserve(records_.size());
  for (const auto& rec : records_) {
    result.push_back(rec.get());
  }
  return result;
}

std::string MedicalRecordBook::GetSummary() const {
  std::ostringstream summary;
  summary << "=== Medical Record Book: " << owner_ << " ===\n";

  if (records_.empty()) {
    summary << "No medical records available.\n";
    return summary.str();
  }

  for (const auto& record : records_) {
    summary << "- Date: " << record->GetFormattedCreationDate() << "\n"
            << "  Diagnosis: " << record->GetDiagnosis().ToString() << "\n";
  }

  return summary.str();
}

const std::string& MedicalRecordBook::GetOwner() const noexcept {
  return owner_;
}

}  // namespace medical
}  // namespace animals