#include "torque-generated/class-debug-readers-tq.h"
#include "include/v8-internal.h"

namespace i = v8::internal;

namespace v8_debug_helper_internal {

const char* TqHeapObject::GetName() const {
  return "v8::internal::HeapObject";
}

void TqHeapObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitHeapObject(this);
}

bool TqHeapObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqHeapObject*>(other) != nullptr;
}

uintptr_t TqHeapObject::GetMapAddress() const {
  return address_ - i::kHeapObjectTag + 0;
}

Value<uintptr_t> TqHeapObject::GetMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqHeapObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("map", "v8::internal::TaggedValue", "v8::internal::Map", GetMapAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqContext::GetName() const {
  return "v8::internal::Context";
}

void TqContext::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitContext(this);
}

bool TqContext::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqContext*>(other) != nullptr;
}

uintptr_t TqContext::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqContext::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqContext::GetScopeInfoAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqContext::GetScopeInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScopeInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqContext::GetPreviousAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqContext::GetPreviousValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPreviousAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqContext::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("scope_info", "v8::internal::TaggedValue", "v8::internal::ScopeInfo", GetScopeInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("previous", "v8::internal::TaggedValue", "v8::internal::Object", GetPreviousAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSReceiver::GetName() const {
  return "v8::internal::JSReceiver";
}

void TqJSReceiver::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSReceiver(this);
}

bool TqJSReceiver::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSReceiver*>(other) != nullptr;
}

uintptr_t TqJSReceiver::GetPropertiesOrHashAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqJSReceiver::GetPropertiesOrHashValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPropertiesOrHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSReceiver::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("properties_or_hash", "v8::internal::TaggedValue", "v8::internal::Object", GetPropertiesOrHashAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPrimitiveHeapObject::GetName() const {
  return "v8::internal::PrimitiveHeapObject";
}

void TqPrimitiveHeapObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPrimitiveHeapObject(this);
}

bool TqPrimitiveHeapObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPrimitiveHeapObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqPrimitiveHeapObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqHeapNumber::GetName() const {
  return "v8::internal::HeapNumber";
}

void TqHeapNumber::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitHeapNumber(this);
}

bool TqHeapNumber::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqHeapNumber*>(other) != nullptr;
}

uintptr_t TqHeapNumber::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<double /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqHeapNumber::GetValueValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqHeapNumber::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPrimitiveHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("value", "double", "double", GetValueAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqBigIntBase::GetName() const {
  return "v8::internal::BigIntBase";
}

void TqBigIntBase::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitBigIntBase(this);
}

bool TqBigIntBase::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqBigIntBase*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqBigIntBase::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPrimitiveHeapObject::GetProperties(accessor);
  return result;
}

const char* TqName::GetName() const {
  return "v8::internal::Name";
}

void TqName::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitName(this);
}

bool TqName::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqName*>(other) != nullptr;
}

uintptr_t TqName::GetHashFieldAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uint32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqName::GetHashFieldValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetHashFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqName::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPrimitiveHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("hash_field", "uint32_t", "uint32_t", GetHashFieldAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqString::GetName() const {
  return "v8::internal::String";
}

void TqString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitString(this);
}

bool TqString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqString*>(other) != nullptr;
}

uintptr_t TqString::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqString::GetLengthValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqName::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "int32_t", "int32_t", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSymbol::GetName() const {
  return "v8::internal::Symbol";
}

void TqSymbol::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSymbol(this);
}

bool TqSymbol::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSymbol*>(other) != nullptr;
}

uintptr_t TqSymbol::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSymbol::GetFlagsValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSymbol::GetDescriptionAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqSymbol::GetDescriptionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDescriptionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSymbol::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqName::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("flags", "int32_t", "int32_t", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("description", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetDescriptionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqOddball::GetName() const {
  return "v8::internal::Oddball";
}

void TqOddball::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitOddball(this);
}

bool TqOddball::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqOddball*>(other) != nullptr;
}

uintptr_t TqOddball::GetToNumberRawAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<double /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqOddball::GetToNumberRawValue(d::MemoryAccessor accessor) const {
  double /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetToNumberRawAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqOddball::GetToStringAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqOddball::GetToStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetToStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOddball::GetToNumberAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqOddball::GetToNumberValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetToNumberAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOddball::GetTypeOfAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqOddball::GetTypeOfValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTypeOfAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqOddball::GetKindAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqOddball::GetKindValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKindAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqOddball::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPrimitiveHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("to_number_raw", "double", "double", GetToNumberRawAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("to_string", "v8::internal::TaggedValue", "v8::internal::String", GetToStringAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("to_number", "v8::internal::TaggedValue", "v8::internal::Object", GetToNumberAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("type_of", "v8::internal::TaggedValue", "v8::internal::String", GetTypeOfAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("kind", "v8::internal::TaggedValue", "v8::internal::Object", GetKindAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqFixedArrayBase::GetName() const {
  return "v8::internal::FixedArrayBase";
}

void TqFixedArrayBase::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFixedArrayBase(this);
}

bool TqFixedArrayBase::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFixedArrayBase*>(other) != nullptr;
}

uintptr_t TqFixedArrayBase::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqFixedArrayBase::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFixedArrayBase::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqFixedArray::GetName() const {
  return "v8::internal::FixedArray";
}

void TqFixedArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFixedArray(this);
}

bool TqFixedArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFixedArray*>(other) != nullptr;
}

uintptr_t TqFixedArray::GetObjectsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqFixedArray::GetObjectsValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFixedArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  Value<uintptr_t> indexed_field_count = GetLengthValue(accessor);
  result.push_back(std::make_unique<ObjectProperty>("objects", "v8::internal::TaggedValue", "v8::internal::Object", GetObjectsAddress(), i::PlatformSmiTagging::SmiToInt(indexed_field_count.value), 4, std::vector<std::unique_ptr<StructProperty>>(), GetArrayKind(indexed_field_count.validity)));
  return result;
}

const char* TqByteArray::GetName() const {
  return "v8::internal::ByteArray";
}

void TqByteArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitByteArray(this);
}

bool TqByteArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqByteArray*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqByteArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  return result;
}

const char* TqWeakFixedArray::GetName() const {
  return "v8::internal::WeakFixedArray";
}

void TqWeakFixedArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWeakFixedArray(this);
}

bool TqWeakFixedArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWeakFixedArray*>(other) != nullptr;
}

uintptr_t TqWeakFixedArray::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqWeakFixedArray::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWeakFixedArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqForeign::GetName() const {
  return "v8::internal::Foreign";
}

void TqForeign::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitForeign(this);
}

bool TqForeign::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqForeign*>(other) != nullptr;
}

uintptr_t TqForeign::GetForeignAddressAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqForeign::GetForeignAddressValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetForeignAddressAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqForeign::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("foreign_address", "void*", "void*", GetForeignAddressAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSObject::GetName() const {
  return "v8::internal::JSObject";
}

void TqJSObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSObject(this);
}

bool TqJSObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSObject*>(other) != nullptr;
}

uintptr_t TqJSObject::GetElementsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqJSObject::GetElementsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSReceiver::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("elements", "v8::internal::TaggedValue", "v8::internal::FixedArrayBase", GetElementsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSProxy::GetName() const {
  return "v8::internal::JSProxy";
}

void TqJSProxy::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSProxy(this);
}

bool TqJSProxy::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSProxy*>(other) != nullptr;
}

uintptr_t TqJSProxy::GetTargetAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqJSProxy::GetTargetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSProxy::GetHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSProxy::GetHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSProxy::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSReceiver::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("target", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetTargetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("handler", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetHandlerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSFunctionOrBoundFunction::GetName() const {
  return "v8::internal::JSFunctionOrBoundFunction";
}

void TqJSFunctionOrBoundFunction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSFunctionOrBoundFunction(this);
}

bool TqJSFunctionOrBoundFunction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSFunctionOrBoundFunction*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSFunctionOrBoundFunction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSFunction::GetName() const {
  return "v8::internal::JSFunction";
}

void TqJSFunction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSFunction(this);
}

bool TqJSFunction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSFunction*>(other) != nullptr;
}

uintptr_t TqJSFunction::GetSharedFunctionInfoAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSFunction::GetSharedFunctionInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedFunctionInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFunction::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSFunction::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFunction::GetFeedbackCellAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSFunction::GetFeedbackCellValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFeedbackCellAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFunction::GetCodeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSFunction::GetCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFunction::GetPrototypeOrInitialMapAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSFunction::GetPrototypeOrInitialMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeOrInitialMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSFunction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSFunctionOrBoundFunction::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("shared_function_info", "v8::internal::TaggedValue", "v8::internal::SharedFunctionInfo", GetSharedFunctionInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::TaggedValue", "v8::internal::Context", GetContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("feedback_cell", "v8::internal::TaggedValue", "v8::internal::FeedbackCell", GetFeedbackCellAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("code", "v8::internal::TaggedValue", "v8::internal::Code", GetCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("prototype_or_initial_map", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetPrototypeOrInitialMapAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSBoundFunction::GetName() const {
  return "v8::internal::JSBoundFunction";
}

void TqJSBoundFunction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSBoundFunction(this);
}

bool TqJSBoundFunction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSBoundFunction*>(other) != nullptr;
}

uintptr_t TqJSBoundFunction::GetBoundTargetFunctionAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSBoundFunction::GetBoundTargetFunctionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundTargetFunctionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSBoundFunction::GetBoundThisAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSBoundFunction::GetBoundThisValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundThisAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSBoundFunction::GetBoundArgumentsAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSBoundFunction::GetBoundArgumentsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundArgumentsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSBoundFunction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSFunctionOrBoundFunction::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("bound_target_function", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetBoundTargetFunctionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_this", "v8::internal::TaggedValue", "v8::internal::Object", GetBoundThisAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_arguments", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetBoundArgumentsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSCustomElementsObject::GetName() const {
  return "v8::internal::JSCustomElementsObject";
}

void TqJSCustomElementsObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSCustomElementsObject(this);
}

bool TqJSCustomElementsObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSCustomElementsObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSCustomElementsObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSSpecialObject::GetName() const {
  return "v8::internal::JSSpecialObject";
}

void TqJSSpecialObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSpecialObject(this);
}

bool TqJSSpecialObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSpecialObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSpecialObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSCustomElementsObject::GetProperties(accessor);
  return result;
}

const char* TqMap::GetName() const {
  return "v8::internal::Map";
}

void TqMap::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitMap(this);
}

bool TqMap::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqMap*>(other) != nullptr;
}

uintptr_t TqMap::GetInstanceSizeInWordsAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqMap::GetInstanceSizeInWordsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetInstanceSizeInWordsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetInObjectPropertiesStartOrConstructorFunctionIndexAddress() const {
  return address_ - i::kHeapObjectTag + 5;
}

Value<uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqMap::GetInObjectPropertiesStartOrConstructorFunctionIndexValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetInObjectPropertiesStartOrConstructorFunctionIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetUsedOrUnusedInstanceSizeInWordsAddress() const {
  return address_ - i::kHeapObjectTag + 6;
}

Value<uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqMap::GetUsedOrUnusedInstanceSizeInWordsValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetUsedOrUnusedInstanceSizeInWordsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetVisitorIdAddress() const {
  return address_ - i::kHeapObjectTag + 7;
}

Value<uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqMap::GetVisitorIdValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetVisitorIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetInstanceTypeAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<v8::internal::InstanceType /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqMap::GetInstanceTypeValue(d::MemoryAccessor accessor) const {
  v8::internal::InstanceType /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetInstanceTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetBitFieldAddress() const {
  return address_ - i::kHeapObjectTag + 10;
}

Value<uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqMap::GetBitFieldValue(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetBitField2Address() const {
  return address_ - i::kHeapObjectTag + 11;
}

Value<uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqMap::GetBitField2Value(d::MemoryAccessor accessor) const {
  uint8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitField2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetBitField3Address() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uint32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqMap::GetBitField3Value(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetBitField3Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqMap::GetPrototypeAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqMap::GetPrototypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetConstructorOrBackPointerOrNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqMap::GetConstructorOrBackPointerOrNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstructorOrBackPointerOrNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetInstanceDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqMap::GetInstanceDescriptorsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceDescriptorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetDependentCodeAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqMap::GetDependentCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDependentCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetPrototypeValidityCellAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqMap::GetPrototypeValidityCellValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeValidityCellAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqMap::GetTransitionsOrPrototypeInfoAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqMap::GetTransitionsOrPrototypeInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTransitionsOrPrototypeInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqMap::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("instance_size_in_words", "uint8_t", "uint8_t", GetInstanceSizeInWordsAddress(), 1, 1, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("in_object_properties_start_or_constructor_function_index", "uint8_t", "uint8_t", GetInObjectPropertiesStartOrConstructorFunctionIndexAddress(), 1, 1, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("used_or_unused_instance_size_in_words", "uint8_t", "uint8_t", GetUsedOrUnusedInstanceSizeInWordsAddress(), 1, 1, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("visitor_id", "uint8_t", "uint8_t", GetVisitorIdAddress(), 1, 1, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("instance_type", "v8::internal::InstanceType", "v8::internal::InstanceType", GetInstanceTypeAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bit_field", "uint8_t", "uint8_t", GetBitFieldAddress(), 1, 1, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bit_field2", "uint8_t", "uint8_t", GetBitField2Address(), 1, 1, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bit_field3", "uint32_t", "uint32_t", GetBitField3Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("prototype", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetPrototypeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("constructor_or_back_pointer_or_native_context", "v8::internal::TaggedValue", "v8::internal::Object", GetConstructorOrBackPointerOrNativeContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("instance_descriptors", "v8::internal::TaggedValue", "v8::internal::DescriptorArray", GetInstanceDescriptorsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("dependent_code", "v8::internal::TaggedValue", "v8::internal::WeakFixedArray", GetDependentCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("prototype_validity_cell", "v8::internal::TaggedValue", "v8::internal::Object", GetPrototypeValidityCellAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("transitions_or_prototype_info", "v8::internal::TaggedValue", "v8::internal::Object", GetTransitionsOrPrototypeInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqMutableBigInt::GetName() const {
  return "v8::internal::MutableBigInt";
}

void TqMutableBigInt::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitMutableBigInt(this);
}

bool TqMutableBigInt::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqMutableBigInt*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqMutableBigInt::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqBigIntBase::GetProperties(accessor);
  return result;
}

const char* TqJSArrayBufferView::GetName() const {
  return "v8::internal::JSArrayBufferView";
}

void TqJSArrayBufferView::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArrayBufferView(this);
}

bool TqJSArrayBufferView::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArrayBufferView*>(other) != nullptr;
}

uintptr_t TqJSArrayBufferView::GetBufferAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSArrayBufferView::GetBufferValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBufferAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSArrayBufferView::GetByteOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqJSArrayBufferView::GetByteOffsetValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetByteOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBufferView::GetByteLengthAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqJSArrayBufferView::GetByteLengthValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetByteLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArrayBufferView::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("buffer", "v8::internal::TaggedValue", "v8::internal::JSArrayBuffer", GetBufferAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("byte_offset", "uintptr_t", "uintptr_t", GetByteOffsetAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("byte_length", "uintptr_t", "uintptr_t", GetByteLengthAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSTypedArray::GetName() const {
  return "v8::internal::JSTypedArray";
}

void TqJSTypedArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSTypedArray(this);
}

bool TqJSTypedArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSTypedArray*>(other) != nullptr;
}

uintptr_t TqJSTypedArray::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqJSTypedArray::GetLengthValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSTypedArray::GetExternalPointerAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqJSTypedArray::GetExternalPointerValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetExternalPointerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSTypedArray::GetBasePointerAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqJSTypedArray::GetBasePointerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBasePointerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSTypedArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArrayBufferView::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "uintptr_t", "uintptr_t", GetLengthAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("external_pointer", "void*", "void*", GetExternalPointerAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("base_pointer", "v8::internal::TaggedValue", "v8::internal::Object", GetBasePointerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqStruct::GetName() const {
  return "v8::internal::Struct";
}

void TqStruct::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitStruct(this);
}

bool TqStruct::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqStruct*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqStruct::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  return result;
}

const char* TqDataHandler::GetName() const {
  return "v8::internal::DataHandler";
}

void TqDataHandler::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitDataHandler(this);
}

bool TqDataHandler::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqDataHandler*>(other) != nullptr;
}

uintptr_t TqDataHandler::GetSmiHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqDataHandler::GetSmiHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSmiHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDataHandler::GetValidityCellAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqDataHandler::GetValidityCellValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValidityCellAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDataHandler::GetData1Address() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqDataHandler::GetData1Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetData1Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDataHandler::GetData2Address() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqDataHandler::GetData2Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetData2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDataHandler::GetData3Address() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqDataHandler::GetData3Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetData3Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqDataHandler::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("smi_handler", "v8::internal::TaggedValue", "v8::internal::Object", GetSmiHandlerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("validity_cell", "v8::internal::TaggedValue", "v8::internal::Object", GetValidityCellAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data_1", "v8::internal::TaggedValue", "v8::internal::Object", GetData1Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data_2", "v8::internal::TaggedValue", "v8::internal::Object", GetData2Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data_3", "v8::internal::TaggedValue", "v8::internal::Object", GetData3Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqAllocationMemento::GetName() const {
  return "v8::internal::AllocationMemento";
}

void TqAllocationMemento::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAllocationMemento(this);
}

bool TqAllocationMemento::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAllocationMemento*>(other) != nullptr;
}

uintptr_t TqAllocationMemento::GetAllocationSiteAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqAllocationMemento::GetAllocationSiteValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAllocationSiteAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAllocationMemento::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("allocation_site", "v8::internal::TaggedValue", "v8::internal::AllocationSite", GetAllocationSiteAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqCallHandlerInfo::GetName() const {
  return "v8::internal::CallHandlerInfo";
}

void TqCallHandlerInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCallHandlerInfo(this);
}

bool TqCallHandlerInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCallHandlerInfo*>(other) != nullptr;
}

uintptr_t TqCallHandlerInfo::GetCallbackAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqCallHandlerInfo::GetCallbackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallbackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallHandlerInfo::GetJsCallbackAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqCallHandlerInfo::GetJsCallbackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetJsCallbackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallHandlerInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqCallHandlerInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCallHandlerInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("callback", "v8::internal::TaggedValue", "v8::internal::Object", GetCallbackAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("js_callback", "v8::internal::TaggedValue", "v8::internal::Object", GetJsCallbackAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::TaggedValue", "v8::internal::Object", GetDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqInterceptorInfo::GetName() const {
  return "v8::internal::InterceptorInfo";
}

void TqInterceptorInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInterceptorInfo(this);
}

bool TqInterceptorInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInterceptorInfo*>(other) != nullptr;
}

uintptr_t TqInterceptorInfo::GetGetterAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqInterceptorInfo::GetGetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetSetterAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqInterceptorInfo::GetSetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetQueryAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqInterceptorInfo::GetQueryValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetQueryAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetDescriptorAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqInterceptorInfo::GetDescriptorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDescriptorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetDeleterAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqInterceptorInfo::GetDeleterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDeleterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetEnumeratorAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqInterceptorInfo::GetEnumeratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEnumeratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetDefinerAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqInterceptorInfo::GetDefinerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDefinerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqInterceptorInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterceptorInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqInterceptorInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqInterceptorInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("getter", "v8::internal::TaggedValue", "v8::internal::Object", GetGetterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("setter", "v8::internal::TaggedValue", "v8::internal::Object", GetSetterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("query", "v8::internal::TaggedValue", "v8::internal::Object", GetQueryAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("descriptor", "v8::internal::TaggedValue", "v8::internal::Object", GetDescriptorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("deleter", "v8::internal::TaggedValue", "v8::internal::Object", GetDeleterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("enumerator", "v8::internal::TaggedValue", "v8::internal::Object", GetEnumeratorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("definer", "v8::internal::TaggedValue", "v8::internal::Object", GetDefinerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::TaggedValue", "v8::internal::Object", GetDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqAccessCheckInfo::GetName() const {
  return "v8::internal::AccessCheckInfo";
}

void TqAccessCheckInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAccessCheckInfo(this);
}

bool TqAccessCheckInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAccessCheckInfo*>(other) != nullptr;
}

uintptr_t TqAccessCheckInfo::GetCallbackAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqAccessCheckInfo::GetCallbackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallbackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessCheckInfo::GetNamedInterceptorAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAccessCheckInfo::GetNamedInterceptorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNamedInterceptorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessCheckInfo::GetIndexedInterceptorAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqAccessCheckInfo::GetIndexedInterceptorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexedInterceptorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessCheckInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAccessCheckInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAccessCheckInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("callback", "v8::internal::TaggedValue", "v8::internal::Object", GetCallbackAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("named_interceptor", "v8::internal::TaggedValue", "v8::internal::Object", GetNamedInterceptorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("indexed_interceptor", "v8::internal::TaggedValue", "v8::internal::Object", GetIndexedInterceptorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::TaggedValue", "v8::internal::Object", GetDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqAccessorInfo::GetName() const {
  return "v8::internal::AccessorInfo";
}

void TqAccessorInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAccessorInfo(this);
}

bool TqAccessorInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAccessorInfo*>(other) != nullptr;
}

uintptr_t TqAccessorInfo::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqAccessorInfo::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAccessorInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorInfo::GetExpectedReceiverTypeAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqAccessorInfo::GetExpectedReceiverTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExpectedReceiverTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorInfo::GetSetterAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAccessorInfo::GetSetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorInfo::GetGetterAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqAccessorInfo::GetGetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorInfo::GetJsGetterAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqAccessorInfo::GetJsGetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetJsGetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqAccessorInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAccessorInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::TaggedValue", "v8::internal::Object", GetNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("expected_receiver_type", "v8::internal::TaggedValue", "v8::internal::Object", GetExpectedReceiverTypeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("setter", "v8::internal::TaggedValue", "v8::internal::Object", GetSetterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("getter", "v8::internal::TaggedValue", "v8::internal::Object", GetGetterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("js_getter", "v8::internal::TaggedValue", "v8::internal::Object", GetJsGetterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::TaggedValue", "v8::internal::Object", GetDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSArgumentsObject::GetName() const {
  return "v8::internal::JSArgumentsObject";
}

void TqJSArgumentsObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArgumentsObject(this);
}

bool TqJSArgumentsObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArgumentsObject*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArgumentsObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  return result;
}

const char* TqJSSloppyArgumentsObject::GetName() const {
  return "v8::internal::JSSloppyArgumentsObject";
}

void TqJSSloppyArgumentsObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSloppyArgumentsObject(this);
}

bool TqJSSloppyArgumentsObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSloppyArgumentsObject*>(other) != nullptr;
}

uintptr_t TqJSSloppyArgumentsObject::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSSloppyArgumentsObject::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSloppyArgumentsObject::GetCalleeAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSSloppyArgumentsObject::GetCalleeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCalleeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSloppyArgumentsObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArgumentsObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("callee", "v8::internal::TaggedValue", "v8::internal::Object", GetCalleeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSStrictArgumentsObject::GetName() const {
  return "v8::internal::JSStrictArgumentsObject";
}

void TqJSStrictArgumentsObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSStrictArgumentsObject(this);
}

bool TqJSStrictArgumentsObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSStrictArgumentsObject*>(other) != nullptr;
}

uintptr_t TqJSStrictArgumentsObject::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSStrictArgumentsObject::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSStrictArgumentsObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArgumentsObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqAliasedArgumentsEntry::GetName() const {
  return "v8::internal::AliasedArgumentsEntry";
}

void TqAliasedArgumentsEntry::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAliasedArgumentsEntry(this);
}

bool TqAliasedArgumentsEntry::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAliasedArgumentsEntry*>(other) != nullptr;
}

uintptr_t TqAliasedArgumentsEntry::GetAliasedContextSlotAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqAliasedArgumentsEntry::GetAliasedContextSlotValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAliasedContextSlotAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAliasedArgumentsEntry::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("aliased_context_slot", "v8::internal::TaggedValue", "v8::internal::Object", GetAliasedContextSlotAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqCell::GetName() const {
  return "v8::internal::Cell";
}

void TqCell::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCell(this);
}

bool TqCell::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCell*>(other) != nullptr;
}

uintptr_t TqCell::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqCell::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCell::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::TaggedValue", "v8::internal::Object", GetValueAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSourcePositionTableWithFrameCache::GetName() const {
  return "v8::internal::SourcePositionTableWithFrameCache";
}

void TqSourcePositionTableWithFrameCache::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSourcePositionTableWithFrameCache(this);
}

bool TqSourcePositionTableWithFrameCache::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSourcePositionTableWithFrameCache*>(other) != nullptr;
}

uintptr_t TqSourcePositionTableWithFrameCache::GetSourcePositionTableAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqSourcePositionTableWithFrameCache::GetSourcePositionTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourcePositionTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourcePositionTableWithFrameCache::GetStackFrameCacheAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSourcePositionTableWithFrameCache::GetStackFrameCacheValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStackFrameCacheAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSourcePositionTableWithFrameCache::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("source_position_table", "v8::internal::TaggedValue", "v8::internal::ByteArray", GetSourcePositionTableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("stack_frame_cache", "v8::internal::TaggedValue", "v8::internal::Object", GetStackFrameCacheAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqBytecodeArray::GetName() const {
  return "v8::internal::BytecodeArray";
}

void TqBytecodeArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitBytecodeArray(this);
}

bool TqBytecodeArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqBytecodeArray*>(other) != nullptr;
}

uintptr_t TqBytecodeArray::GetConstantPoolAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqBytecodeArray::GetConstantPoolValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstantPoolAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqBytecodeArray::GetHandlerTableAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqBytecodeArray::GetHandlerTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHandlerTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqBytecodeArray::GetSourcePositionTableAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqBytecodeArray::GetSourcePositionTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourcePositionTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqBytecodeArray::GetFrameSizeAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqBytecodeArray::GetFrameSizeValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetFrameSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqBytecodeArray::GetParameterSizeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqBytecodeArray::GetParameterSizeValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetParameterSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqBytecodeArray::GetIncomingNewTargetOrGeneratorRegisterAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqBytecodeArray::GetIncomingNewTargetOrGeneratorRegisterValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetIncomingNewTargetOrGeneratorRegisterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqBytecodeArray::GetOsrNestingLevelAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<int8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqBytecodeArray::GetOsrNestingLevelValue(d::MemoryAccessor accessor) const {
  int8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetOsrNestingLevelAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqBytecodeArray::GetBytecodeAgeAddress() const {
  return address_ - i::kHeapObjectTag + 33;
}

Value<int8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqBytecodeArray::GetBytecodeAgeValue(d::MemoryAccessor accessor) const {
  int8_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetBytecodeAgeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqBytecodeArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("constant_pool", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetConstantPoolAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("handler_table", "v8::internal::TaggedValue", "v8::internal::ByteArray", GetHandlerTableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("source_position_table", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetSourcePositionTableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("frame_size", "int32_t", "int32_t", GetFrameSizeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("parameter_size", "int32_t", "int32_t", GetParameterSizeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("incoming_new_target_or_generator_register", "int32_t", "int32_t", GetIncomingNewTargetOrGeneratorRegisterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("osr_nesting_level", "int8_t", "int8_t", GetOsrNestingLevelAddress(), 1, 1, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bytecode_age", "int8_t", "int8_t", GetBytecodeAgeAddress(), 1, 1, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqTuple2::GetName() const {
  return "v8::internal::Tuple2";
}

void TqTuple2::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTuple2(this);
}

bool TqTuple2::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTuple2*>(other) != nullptr;
}

uintptr_t TqTuple2::GetValue1Address() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqTuple2::GetValue1Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValue1Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTuple2::GetValue2Address() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTuple2::GetValue2Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValue2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTuple2::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("value1", "v8::internal::TaggedValue", "v8::internal::Object", GetValue1Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("value2", "v8::internal::TaggedValue", "v8::internal::Object", GetValue2Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqBreakPoint::GetName() const {
  return "v8::internal::BreakPoint";
}

void TqBreakPoint::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitBreakPoint(this);
}

bool TqBreakPoint::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqBreakPoint*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqBreakPoint::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTuple2::GetProperties(accessor);
  return result;
}

const char* TqBreakPointInfo::GetName() const {
  return "v8::internal::BreakPointInfo";
}

void TqBreakPointInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitBreakPointInfo(this);
}

bool TqBreakPointInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqBreakPointInfo*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqBreakPointInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTuple2::GetProperties(accessor);
  return result;
}

const char* TqDebugInfo::GetName() const {
  return "v8::internal::DebugInfo";
}

void TqDebugInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitDebugInfo(this);
}

bool TqDebugInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqDebugInfo*>(other) != nullptr;
}

uintptr_t TqDebugInfo::GetSharedAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqDebugInfo::GetSharedValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetDebuggerHintsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqDebugInfo::GetDebuggerHintsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDebuggerHintsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetScriptAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqDebugInfo::GetScriptValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetOriginalBytecodeArrayAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqDebugInfo::GetOriginalBytecodeArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOriginalBytecodeArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetDebugBytecodeArrayAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqDebugInfo::GetDebugBytecodeArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDebugBytecodeArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetBreakPointsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqDebugInfo::GetBreakPointsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBreakPointsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqDebugInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDebugInfo::GetCoverageInfoAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqDebugInfo::GetCoverageInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCoverageInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqDebugInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("shared", "v8::internal::TaggedValue", "v8::internal::SharedFunctionInfo", GetSharedAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("debugger_hints", "v8::internal::TaggedValue", "v8::internal::Object", GetDebuggerHintsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetScriptAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("original_bytecode_array", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetOriginalBytecodeArrayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("debug_bytecode_array", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetDebugBytecodeArrayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("break_points", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetBreakPointsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("coverage_info", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetCoverageInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqEnumCache::GetName() const {
  return "v8::internal::EnumCache";
}

void TqEnumCache::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitEnumCache(this);
}

bool TqEnumCache::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqEnumCache*>(other) != nullptr;
}

uintptr_t TqEnumCache::GetKeysAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqEnumCache::GetKeysValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeysAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqEnumCache::GetIndicesAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqEnumCache::GetIndicesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndicesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqEnumCache::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("keys", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetKeysAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("indices", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetIndicesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqAccessorPair::GetName() const {
  return "v8::internal::AccessorPair";
}

void TqAccessorPair::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAccessorPair(this);
}

bool TqAccessorPair::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAccessorPair*>(other) != nullptr;
}

uintptr_t TqAccessorPair::GetGetterAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqAccessorPair::GetGetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAccessorPair::GetSetterAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAccessorPair::GetSetterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSetterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAccessorPair::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("getter", "v8::internal::TaggedValue", "v8::internal::Object", GetGetterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("setter", "v8::internal::TaggedValue", "v8::internal::Object", GetSetterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqClassPositions::GetName() const {
  return "v8::internal::ClassPositions";
}

void TqClassPositions::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitClassPositions(this);
}

bool TqClassPositions::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqClassPositions*>(other) != nullptr;
}

uintptr_t TqClassPositions::GetStartAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqClassPositions::GetStartValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStartAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqClassPositions::GetEndAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqClassPositions::GetEndValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEndAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqClassPositions::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("start", "v8::internal::TaggedValue", "v8::internal::Object", GetStartAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("end", "v8::internal::TaggedValue", "v8::internal::Object", GetEndAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqDescriptorArray::GetName() const {
  return "v8::internal::DescriptorArray";
}

void TqDescriptorArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitDescriptorArray(this);
}

bool TqDescriptorArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqDescriptorArray*>(other) != nullptr;
}

uintptr_t TqDescriptorArray::GetNumberOfAllDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqDescriptorArray::GetNumberOfAllDescriptorsValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfAllDescriptorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqDescriptorArray::GetNumberOfDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 6;
}

Value<uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqDescriptorArray::GetNumberOfDescriptorsValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfDescriptorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqDescriptorArray::GetRawNumberOfMarkedDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqDescriptorArray::GetRawNumberOfMarkedDescriptorsValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetRawNumberOfMarkedDescriptorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqDescriptorArray::GetFiller16BitsAddress() const {
  return address_ - i::kHeapObjectTag + 10;
}

Value<uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqDescriptorArray::GetFiller16BitsValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetFiller16BitsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqDescriptorArray::GetEnumCacheAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqDescriptorArray::GetEnumCacheValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEnumCacheAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqDescriptorArray::GetDescriptorsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

std::vector<std::unique_ptr<ObjectProperty>> TqDescriptorArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("number_of_all_descriptors", "uint16_t", "uint16_t", GetNumberOfAllDescriptorsAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("number_of_descriptors", "uint16_t", "uint16_t", GetNumberOfDescriptorsAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("raw_number_of_marked_descriptors", "uint16_t", "uint16_t", GetRawNumberOfMarkedDescriptorsAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("filler16_bits", "uint16_t", "uint16_t", GetFiller16BitsAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("enum_cache", "v8::internal::TaggedValue", "v8::internal::EnumCache", GetEnumCacheAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  std::vector<std::unique_ptr<StructProperty>> descriptors_struct_field_list;
  descriptors_struct_field_list.push_back(std::make_unique<StructProperty>("key", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", 0));
  descriptors_struct_field_list.push_back(std::make_unique<StructProperty>("details", "v8::internal::TaggedValue", "v8::internal::Object", 4));
  descriptors_struct_field_list.push_back(std::make_unique<StructProperty>("value", "v8::internal::TaggedValue", "v8::internal::Object", 8));
  Value<uint16_t> indexed_field_count = GetNumberOfAllDescriptorsValue(accessor);
  result.push_back(std::make_unique<ObjectProperty>("descriptors", "", "", GetDescriptorsAddress(), indexed_field_count.value, 12, std::move(descriptors_struct_field_list), GetArrayKind(indexed_field_count.validity)));
  return result;
}

const char* TqEmbedderDataArray::GetName() const {
  return "v8::internal::EmbedderDataArray";
}

void TqEmbedderDataArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitEmbedderDataArray(this);
}

bool TqEmbedderDataArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqEmbedderDataArray*>(other) != nullptr;
}

uintptr_t TqEmbedderDataArray::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqEmbedderDataArray::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqEmbedderDataArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqFeedbackCell::GetName() const {
  return "v8::internal::FeedbackCell";
}

void TqFeedbackCell::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFeedbackCell(this);
}

bool TqFeedbackCell::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFeedbackCell*>(other) != nullptr;
}

uintptr_t TqFeedbackCell::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqFeedbackCell::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackCell::GetInterruptBudgetAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqFeedbackCell::GetInterruptBudgetValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetInterruptBudgetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFeedbackCell::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetValueAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("interrupt_budget", "int32_t", "int32_t", GetInterruptBudgetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqFeedbackVector::GetName() const {
  return "v8::internal::FeedbackVector";
}

void TqFeedbackVector::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFeedbackVector(this);
}

bool TqFeedbackVector::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFeedbackVector*>(other) != nullptr;
}

uintptr_t TqFeedbackVector::GetSharedFunctionInfoAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqFeedbackVector::GetSharedFunctionInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedFunctionInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackVector::GetOptimizedCodeWeakOrSmiAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqFeedbackVector::GetOptimizedCodeWeakOrSmiValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOptimizedCodeWeakOrSmiAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackVector::GetClosureFeedbackCellArrayAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqFeedbackVector::GetClosureFeedbackCellArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetClosureFeedbackCellArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFeedbackVector::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqFeedbackVector::GetLengthValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetInvocationCountAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqFeedbackVector::GetInvocationCountValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetInvocationCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetProfilerTicksAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqFeedbackVector::GetProfilerTicksValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetProfilerTicksAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqFeedbackVector::GetPaddingAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uint32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqFeedbackVector::GetPaddingValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetPaddingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFeedbackVector::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("shared_function_info", "v8::internal::TaggedValue", "v8::internal::SharedFunctionInfo", GetSharedFunctionInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("optimized_code_weak_or_smi", "v8::internal::TaggedValue", "v8::internal::Object", GetOptimizedCodeWeakOrSmiAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("closure_feedback_cell_array", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetClosureFeedbackCellArrayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("length", "int32_t", "int32_t", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("invocation_count", "int32_t", "int32_t", GetInvocationCountAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("profiler_ticks", "int32_t", "int32_t", GetProfilerTicksAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("padding", "uint32_t", "uint32_t", GetPaddingAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqFixedDoubleArray::GetName() const {
  return "v8::internal::FixedDoubleArray";
}

void TqFixedDoubleArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFixedDoubleArray(this);
}

bool TqFixedDoubleArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFixedDoubleArray*>(other) != nullptr;
}

uintptr_t TqFixedDoubleArray::GetFloatsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<double /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqFixedDoubleArray::GetFloatsValue(d::MemoryAccessor accessor, size_t offset) const {
  double /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetFloatsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFixedDoubleArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArrayBase::GetProperties(accessor);
  Value<uintptr_t> indexed_field_count = GetLengthValue(accessor);
  result.push_back(std::make_unique<ObjectProperty>("floats", "double", "double", GetFloatsAddress(), i::PlatformSmiTagging::SmiToInt(indexed_field_count.value), 8, std::vector<std::unique_ptr<StructProperty>>(), GetArrayKind(indexed_field_count.validity)));
  return result;
}

const char* TqArrayList::GetName() const {
  return "v8::internal::ArrayList";
}

void TqArrayList::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitArrayList(this);
}

bool TqArrayList::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqArrayList*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqArrayList::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArray::GetProperties(accessor);
  return result;
}

const char* TqTemplateList::GetName() const {
  return "v8::internal::TemplateList";
}

void TqTemplateList::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTemplateList(this);
}

bool TqTemplateList::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTemplateList*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqTemplateList::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArray::GetProperties(accessor);
  return result;
}

const char* TqWeakArrayList::GetName() const {
  return "v8::internal::WeakArrayList";
}

void TqWeakArrayList::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWeakArrayList(this);
}

bool TqWeakArrayList::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWeakArrayList*>(other) != nullptr;
}

uintptr_t TqWeakArrayList::GetCapacityAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqWeakArrayList::GetCapacityValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCapacityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakArrayList::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWeakArrayList::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakArrayList::GetObjectsAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWeakArrayList::GetObjectsValue(d::MemoryAccessor accessor, size_t offset) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWeakArrayList::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("capacity", "v8::internal::TaggedValue", "v8::internal::Object", GetCapacityAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  Value<uintptr_t> indexed_field_count = GetLengthValue(accessor);
  result.push_back(std::make_unique<ObjectProperty>("objects", "v8::internal::TaggedValue", "v8::internal::Object", GetObjectsAddress(), i::PlatformSmiTagging::SmiToInt(indexed_field_count.value), 4, std::vector<std::unique_ptr<StructProperty>>(), GetArrayKind(indexed_field_count.validity)));
  return result;
}

const char* TqFreeSpace::GetName() const {
  return "v8::internal::FreeSpace";
}

void TqFreeSpace::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFreeSpace(this);
}

bool TqFreeSpace::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFreeSpace*>(other) != nullptr;
}

uintptr_t TqFreeSpace::GetSizeAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqFreeSpace::GetSizeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFreeSpace::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqFreeSpace::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFreeSpace::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("size", "v8::internal::TaggedValue", "v8::internal::Object", GetSizeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::TaggedValue", "v8::internal::Object", GetNextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDateTimeFormat::GetName() const {
  return "v8::internal::JSDateTimeFormat";
}

void TqJSDateTimeFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDateTimeFormat(this);
}

bool TqJSDateTimeFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDateTimeFormat*>(other) != nullptr;
}

uintptr_t TqJSDateTimeFormat::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSDateTimeFormat::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetIcuLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSDateTimeFormat::GetIcuLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetIcuSimpleDateFormatAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSDateTimeFormat::GetIcuSimpleDateFormatValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuSimpleDateFormatAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetIcuDateIntervalFormatAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSDateTimeFormat::GetIcuDateIntervalFormatValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuDateIntervalFormatAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetBoundFormatAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSDateTimeFormat::GetBoundFormatValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundFormatAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDateTimeFormat::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSDateTimeFormat::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDateTimeFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::TaggedValue", "v8::internal::String", GetLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_locale", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_simple_date_format", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuSimpleDateFormatAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_date_interval_format", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuDateIntervalFormatAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_format", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetBoundFormatAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDisplayNames::GetName() const {
  return "v8::internal::JSDisplayNames";
}

void TqJSDisplayNames::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDisplayNames(this);
}

bool TqJSDisplayNames::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDisplayNames*>(other) != nullptr;
}

uintptr_t TqJSDisplayNames::GetInternalAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSDisplayNames::GetInternalValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInternalAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDisplayNames::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSDisplayNames::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDisplayNames::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("internal", "v8::internal::TaggedValue", "v8::internal::Foreign", GetInternalAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSListFormat::GetName() const {
  return "v8::internal::JSListFormat";
}

void TqJSListFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSListFormat(this);
}

bool TqJSListFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSListFormat*>(other) != nullptr;
}

uintptr_t TqJSListFormat::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSListFormat::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSListFormat::GetIcuFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSListFormat::GetIcuFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSListFormat::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSListFormat::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSListFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::TaggedValue", "v8::internal::String", GetLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_formatter", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuFormatterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSNumberFormat::GetName() const {
  return "v8::internal::JSNumberFormat";
}

void TqJSNumberFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSNumberFormat(this);
}

bool TqJSNumberFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSNumberFormat*>(other) != nullptr;
}

uintptr_t TqJSNumberFormat::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSNumberFormat::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSNumberFormat::GetNumberingSystemAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSNumberFormat::GetNumberingSystemValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNumberingSystemAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSNumberFormat::GetIcuNumberFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSNumberFormat::GetIcuNumberFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuNumberFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSNumberFormat::GetBoundFormatAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSNumberFormat::GetBoundFormatValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundFormatAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSNumberFormat::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSNumberFormat::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSNumberFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::TaggedValue", "v8::internal::String", GetLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("numberingSystem", "v8::internal::TaggedValue", "v8::internal::String", GetNumberingSystemAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_number_formatter", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuNumberFormatterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_format", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetBoundFormatAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSPluralRules::GetName() const {
  return "v8::internal::JSPluralRules";
}

void TqJSPluralRules::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSPluralRules(this);
}

bool TqJSPluralRules::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSPluralRules*>(other) != nullptr;
}

uintptr_t TqJSPluralRules::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSPluralRules::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSPluralRules::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSPluralRules::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSPluralRules::GetIcuPluralRulesAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSPluralRules::GetIcuPluralRulesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuPluralRulesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSPluralRules::GetIcuNumberFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSPluralRules::GetIcuNumberFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuNumberFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSPluralRules::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::TaggedValue", "v8::internal::String", GetLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_plural_rules", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuPluralRulesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_number_formatter", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuNumberFormatterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRelativeTimeFormat::GetName() const {
  return "v8::internal::JSRelativeTimeFormat";
}

void TqJSRelativeTimeFormat::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRelativeTimeFormat(this);
}

bool TqJSRelativeTimeFormat::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRelativeTimeFormat*>(other) != nullptr;
}

uintptr_t TqJSRelativeTimeFormat::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSRelativeTimeFormat::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRelativeTimeFormat::GetNumberingSystemAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSRelativeTimeFormat::GetNumberingSystemValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNumberingSystemAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRelativeTimeFormat::GetIcuFormatterAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSRelativeTimeFormat::GetIcuFormatterValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuFormatterAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRelativeTimeFormat::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSRelativeTimeFormat::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRelativeTimeFormat::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::TaggedValue", "v8::internal::String", GetLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("numberingSystem", "v8::internal::TaggedValue", "v8::internal::String", GetNumberingSystemAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_formatter", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuFormatterAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSLocale::GetName() const {
  return "v8::internal::JSLocale";
}

void TqJSLocale::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSLocale(this);
}

bool TqJSLocale::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSLocale*>(other) != nullptr;
}

uintptr_t TqJSLocale::GetIcuLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSLocale::GetIcuLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSLocale::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("icu_locale", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSegmenter::GetName() const {
  return "v8::internal::JSSegmenter";
}

void TqJSSegmenter::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSegmenter(this);
}

bool TqJSSegmenter::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSegmenter*>(other) != nullptr;
}

uintptr_t TqJSSegmenter::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSSegmenter::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegmenter::GetIcuBreakIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSSegmenter::GetIcuBreakIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuBreakIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegmenter::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSSegmenter::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSegmenter::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::TaggedValue", "v8::internal::String", GetLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("icu_break_iterator", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuBreakIteratorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSegmentIterator::GetName() const {
  return "v8::internal::JSSegmentIterator";
}

void TqJSSegmentIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSegmentIterator(this);
}

bool TqJSSegmentIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSegmentIterator*>(other) != nullptr;
}

uintptr_t TqJSSegmentIterator::GetIcuBreakIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSSegmentIterator::GetIcuBreakIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuBreakIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegmentIterator::GetUnicodeStringAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSSegmentIterator::GetUnicodeStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUnicodeStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSSegmentIterator::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSSegmentIterator::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSegmentIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("icu_break_iterator", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuBreakIteratorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("unicode_string", "v8::internal::TaggedValue", "v8::internal::Foreign", GetUnicodeStringAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSV8BreakIterator::GetName() const {
  return "v8::internal::JSV8BreakIterator";
}

void TqJSV8BreakIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSV8BreakIterator(this);
}

bool TqJSV8BreakIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSV8BreakIterator*>(other) != nullptr;
}

uintptr_t TqJSV8BreakIterator::GetLocaleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSV8BreakIterator::GetLocaleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocaleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBreakIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBreakIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBreakIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetUnicodeStringAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSV8BreakIterator::GetUnicodeStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUnicodeStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundAdoptTextAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundAdoptTextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundAdoptTextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundFirstAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundFirstValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundFirstAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundNextAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundCurrentAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundCurrentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundCurrentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBoundBreakTypeAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBoundBreakTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundBreakTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSV8BreakIterator::GetBreakIteratorTypeAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqJSV8BreakIterator::GetBreakIteratorTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBreakIteratorTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSV8BreakIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("locale", "v8::internal::TaggedValue", "v8::internal::String", GetLocaleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("break_iterator", "v8::internal::TaggedValue", "v8::internal::Foreign", GetBreakIteratorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("unicode_string", "v8::internal::TaggedValue", "v8::internal::Foreign", GetUnicodeStringAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_adopt_text", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetBoundAdoptTextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_first", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetBoundFirstAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_next", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetBoundNextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_current", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetBoundCurrentAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_break_type", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetBoundBreakTypeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("break_iterator_type", "v8::internal::TaggedValue", "v8::internal::Object", GetBreakIteratorTypeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSCollator::GetName() const {
  return "v8::internal::JSCollator";
}

void TqJSCollator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSCollator(this);
}

bool TqJSCollator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSCollator*>(other) != nullptr;
}

uintptr_t TqJSCollator::GetIcuCollatorAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSCollator::GetIcuCollatorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIcuCollatorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSCollator::GetBoundCompareAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSCollator::GetBoundCompareValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBoundCompareAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSCollator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("icu_collator", "v8::internal::TaggedValue", "v8::internal::Foreign", GetIcuCollatorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bound_compare", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetBoundCompareAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSArrayBuffer::GetName() const {
  return "v8::internal::JSArrayBuffer";
}

void TqJSArrayBuffer::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArrayBuffer(this);
}

bool TqJSArrayBuffer::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArrayBuffer*>(other) != nullptr;
}

uintptr_t TqJSArrayBuffer::GetByteLengthAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqJSArrayBuffer::GetByteLengthValue(d::MemoryAccessor accessor) const {
  uintptr_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetByteLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqJSArrayBuffer::GetBackingStoreAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqJSArrayBuffer::GetBackingStoreValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetBackingStoreAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArrayBuffer::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("byte_length", "uintptr_t", "uintptr_t", GetByteLengthAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("backing_store", "void*", "void*", GetBackingStoreAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDataView::GetName() const {
  return "v8::internal::JSDataView";
}

void TqJSDataView::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDataView(this);
}

bool TqJSDataView::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDataView*>(other) != nullptr;
}

uintptr_t TqJSDataView::GetDataPointerAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqJSDataView::GetDataPointerValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetDataPointerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDataView::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArrayBufferView::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("data_pointer", "void*", "void*", GetDataPointerAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSArrayIterator::GetName() const {
  return "v8::internal::JSArrayIterator";
}

void TqJSArrayIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArrayIterator(this);
}

bool TqJSArrayIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArrayIterator*>(other) != nullptr;
}

uintptr_t TqJSArrayIterator::GetIteratedObjectAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSArrayIterator::GetIteratedObjectValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIteratedObjectAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSArrayIterator::GetNextIndexAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSArrayIterator::GetNextIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSArrayIterator::GetKindAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSArrayIterator::GetKindValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKindAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArrayIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("iterated_object", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetIteratedObjectAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("next_index", "v8::internal::TaggedValue", "v8::internal::Object", GetNextIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("kind", "v8::internal::TaggedValue", "v8::internal::Object", GetKindAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSArray::GetName() const {
  return "v8::internal::JSArray";
}

void TqJSArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSArray(this);
}

bool TqJSArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSArray*>(other) != nullptr;
}

uintptr_t TqJSArray::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSArray::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSCollectionIterator::GetName() const {
  return "v8::internal::JSCollectionIterator";
}

void TqJSCollectionIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSCollectionIterator(this);
}

bool TqJSCollectionIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSCollectionIterator*>(other) != nullptr;
}

uintptr_t TqJSCollectionIterator::GetTableAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSCollectionIterator::GetTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSCollectionIterator::GetIndexAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSCollectionIterator::GetIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSCollectionIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("table", "v8::internal::TaggedValue", "v8::internal::Object", GetTableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("index", "v8::internal::TaggedValue", "v8::internal::Object", GetIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSCollection::GetName() const {
  return "v8::internal::JSCollection";
}

void TqJSCollection::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSCollection(this);
}

bool TqJSCollection::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSCollection*>(other) != nullptr;
}

uintptr_t TqJSCollection::GetTableAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSCollection::GetTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSCollection::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("table", "v8::internal::TaggedValue", "v8::internal::Object", GetTableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSSet::GetName() const {
  return "v8::internal::JSSet";
}

void TqJSSet::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSSet(this);
}

bool TqJSSet::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSSet*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSSet::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSCollection::GetProperties(accessor);
  return result;
}

const char* TqJSMap::GetName() const {
  return "v8::internal::JSMap";
}

void TqJSMap::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSMap(this);
}

bool TqJSMap::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSMap*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSMap::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSCollection::GetProperties(accessor);
  return result;
}

const char* TqJSWeakCollection::GetName() const {
  return "v8::internal::JSWeakCollection";
}

void TqJSWeakCollection::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWeakCollection(this);
}

bool TqJSWeakCollection::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWeakCollection*>(other) != nullptr;
}

uintptr_t TqJSWeakCollection::GetTableAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSWeakCollection::GetTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWeakCollection::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("table", "v8::internal::TaggedValue", "v8::internal::Object", GetTableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSWeakSet::GetName() const {
  return "v8::internal::JSWeakSet";
}

void TqJSWeakSet::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWeakSet(this);
}

bool TqJSWeakSet::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWeakSet*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWeakSet::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSWeakCollection::GetProperties(accessor);
  return result;
}

const char* TqJSWeakMap::GetName() const {
  return "v8::internal::JSWeakMap";
}

void TqJSWeakMap::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWeakMap(this);
}

bool TqJSWeakMap::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWeakMap*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWeakMap::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSWeakCollection::GetProperties(accessor);
  return result;
}

const char* TqJSGeneratorObject::GetName() const {
  return "v8::internal::JSGeneratorObject";
}

void TqJSGeneratorObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSGeneratorObject(this);
}

bool TqJSGeneratorObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSGeneratorObject*>(other) != nullptr;
}

uintptr_t TqJSGeneratorObject::GetFunctionAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSGeneratorObject::GetFunctionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSGeneratorObject::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetReceiverAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSGeneratorObject::GetReceiverValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetReceiverAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetInputOrDebugPosAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSGeneratorObject::GetInputOrDebugPosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInputOrDebugPosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetResumeModeAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSGeneratorObject::GetResumeModeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetResumeModeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetContinuationAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSGeneratorObject::GetContinuationValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContinuationAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGeneratorObject::GetParametersAndRegistersAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqJSGeneratorObject::GetParametersAndRegistersValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParametersAndRegistersAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSGeneratorObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("function", "v8::internal::TaggedValue", "v8::internal::JSFunction", GetFunctionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::TaggedValue", "v8::internal::Context", GetContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("receiver", "v8::internal::TaggedValue", "v8::internal::Object", GetReceiverAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("input_or_debug_pos", "v8::internal::TaggedValue", "v8::internal::Object", GetInputOrDebugPosAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("resume_mode", "v8::internal::TaggedValue", "v8::internal::Object", GetResumeModeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("continuation", "v8::internal::TaggedValue", "v8::internal::Object", GetContinuationAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("parameters_and_registers", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetParametersAndRegistersAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSAsyncFunctionObject::GetName() const {
  return "v8::internal::JSAsyncFunctionObject";
}

void TqJSAsyncFunctionObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSAsyncFunctionObject(this);
}

bool TqJSAsyncFunctionObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSAsyncFunctionObject*>(other) != nullptr;
}

uintptr_t TqJSAsyncFunctionObject::GetPromiseAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSAsyncFunctionObject::GetPromiseValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSAsyncFunctionObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSGeneratorObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("promise", "v8::internal::TaggedValue", "v8::internal::JSPromise", GetPromiseAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSAsyncGeneratorObject::GetName() const {
  return "v8::internal::JSAsyncGeneratorObject";
}

void TqJSAsyncGeneratorObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSAsyncGeneratorObject(this);
}

bool TqJSAsyncGeneratorObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSAsyncGeneratorObject*>(other) != nullptr;
}

uintptr_t TqJSAsyncGeneratorObject::GetQueueAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSAsyncGeneratorObject::GetQueueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetQueueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSAsyncGeneratorObject::GetIsAwaitingAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqJSAsyncGeneratorObject::GetIsAwaitingValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIsAwaitingAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSAsyncGeneratorObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSGeneratorObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("queue", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetQueueAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("is_awaiting", "v8::internal::TaggedValue", "v8::internal::Object", GetIsAwaitingAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqAsyncGeneratorRequest::GetName() const {
  return "v8::internal::AsyncGeneratorRequest";
}

void TqAsyncGeneratorRequest::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAsyncGeneratorRequest(this);
}

bool TqAsyncGeneratorRequest::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAsyncGeneratorRequest*>(other) != nullptr;
}

uintptr_t TqAsyncGeneratorRequest::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqAsyncGeneratorRequest::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsyncGeneratorRequest::GetResumeModeAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAsyncGeneratorRequest::GetResumeModeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetResumeModeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsyncGeneratorRequest::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqAsyncGeneratorRequest::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsyncGeneratorRequest::GetPromiseAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAsyncGeneratorRequest::GetPromiseValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAsyncGeneratorRequest::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetNextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("resume_mode", "v8::internal::TaggedValue", "v8::internal::Object", GetResumeModeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::TaggedValue", "v8::internal::Object", GetValueAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("promise", "v8::internal::TaggedValue", "v8::internal::JSPromise", GetPromiseAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSGlobalProxy::GetName() const {
  return "v8::internal::JSGlobalProxy";
}

void TqJSGlobalProxy::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSGlobalProxy(this);
}

bool TqJSGlobalProxy::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSGlobalProxy*>(other) != nullptr;
}

uintptr_t TqJSGlobalProxy::GetNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSGlobalProxy::GetNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSGlobalProxy::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSSpecialObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("native_context", "v8::internal::TaggedValue", "v8::internal::Object", GetNativeContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSGlobalObject::GetName() const {
  return "v8::internal::JSGlobalObject";
}

void TqJSGlobalObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSGlobalObject(this);
}

bool TqJSGlobalObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSGlobalObject*>(other) != nullptr;
}

uintptr_t TqJSGlobalObject::GetNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSGlobalObject::GetNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSGlobalObject::GetGlobalProxyAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSGlobalObject::GetGlobalProxyValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGlobalProxyAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSGlobalObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSSpecialObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("native_context", "v8::internal::TaggedValue", "v8::internal::NativeContext", GetNativeContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("global_proxy", "v8::internal::TaggedValue", "v8::internal::JSGlobalProxy", GetGlobalProxyAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSPrimitiveWrapper::GetName() const {
  return "v8::internal::JSPrimitiveWrapper";
}

void TqJSPrimitiveWrapper::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSPrimitiveWrapper(this);
}

bool TqJSPrimitiveWrapper::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSPrimitiveWrapper*>(other) != nullptr;
}

uintptr_t TqJSPrimitiveWrapper::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSPrimitiveWrapper::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSPrimitiveWrapper::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSCustomElementsObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::TaggedValue", "v8::internal::Object", GetValueAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSMessageObject::GetName() const {
  return "v8::internal::JSMessageObject";
}

void TqJSMessageObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSMessageObject(this);
}

bool TqJSMessageObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSMessageObject*>(other) != nullptr;
}

uintptr_t TqJSMessageObject::GetMessageTypeAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSMessageObject::GetMessageTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMessageTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetArgumentsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSMessageObject::GetArgumentsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetArgumentsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetScriptAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSMessageObject::GetScriptValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetStackFramesAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSMessageObject::GetStackFramesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStackFramesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetSharedInfoAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSMessageObject::GetSharedInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetBytecodeOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSMessageObject::GetBytecodeOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBytecodeOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetStartPositionAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqJSMessageObject::GetStartPositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStartPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetEndPositionAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSMessageObject::GetEndPositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEndPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSMessageObject::GetErrorLevelAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqJSMessageObject::GetErrorLevelValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetErrorLevelAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSMessageObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("message_type", "v8::internal::TaggedValue", "v8::internal::Object", GetMessageTypeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("arguments", "v8::internal::TaggedValue", "v8::internal::Object", GetArgumentsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script", "v8::internal::TaggedValue", "v8::internal::Script", GetScriptAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("stack_frames", "v8::internal::TaggedValue", "v8::internal::Object", GetStackFramesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("shared_info", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetSharedInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bytecode_offset", "v8::internal::TaggedValue", "v8::internal::Object", GetBytecodeOffsetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("start_position", "v8::internal::TaggedValue", "v8::internal::Object", GetStartPositionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("end_position", "v8::internal::TaggedValue", "v8::internal::Object", GetEndPositionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("error_level", "v8::internal::TaggedValue", "v8::internal::Object", GetErrorLevelAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSDate::GetName() const {
  return "v8::internal::JSDate";
}

void TqJSDate::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSDate(this);
}

bool TqJSDate::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSDate*>(other) != nullptr;
}

uintptr_t TqJSDate::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSDate::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetYearAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSDate::GetYearValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetYearAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetMonthAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSDate::GetMonthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMonthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetDayAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSDate::GetDayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetWeekdayAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSDate::GetWeekdayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWeekdayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetHourAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSDate::GetHourValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHourAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetMinAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqJSDate::GetMinValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMinAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetSecAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSDate::GetSecValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSecAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSDate::GetCacheStampAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqJSDate::GetCacheStampValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCacheStampAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSDate::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::TaggedValue", "v8::internal::Object", GetValueAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("year", "v8::internal::TaggedValue", "v8::internal::Object", GetYearAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("month", "v8::internal::TaggedValue", "v8::internal::Object", GetMonthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("day", "v8::internal::TaggedValue", "v8::internal::Object", GetDayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("weekday", "v8::internal::TaggedValue", "v8::internal::Object", GetWeekdayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("hour", "v8::internal::TaggedValue", "v8::internal::Object", GetHourAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("min", "v8::internal::TaggedValue", "v8::internal::Object", GetMinAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("sec", "v8::internal::TaggedValue", "v8::internal::Object", GetSecAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("cache_stamp", "v8::internal::TaggedValue", "v8::internal::Object", GetCacheStampAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSAsyncFromSyncIterator::GetName() const {
  return "v8::internal::JSAsyncFromSyncIterator";
}

void TqJSAsyncFromSyncIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSAsyncFromSyncIterator(this);
}

bool TqJSAsyncFromSyncIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSAsyncFromSyncIterator*>(other) != nullptr;
}

uintptr_t TqJSAsyncFromSyncIterator::GetSyncIteratorAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSAsyncFromSyncIterator::GetSyncIteratorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSyncIteratorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSAsyncFromSyncIterator::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSAsyncFromSyncIterator::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSAsyncFromSyncIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("sync_iterator", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetSyncIteratorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::TaggedValue", "v8::internal::Object", GetNextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSStringIterator::GetName() const {
  return "v8::internal::JSStringIterator";
}

void TqJSStringIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSStringIterator(this);
}

bool TqJSStringIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSStringIterator*>(other) != nullptr;
}

uintptr_t TqJSStringIterator::GetStringAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSStringIterator::GetStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSStringIterator::GetIndexAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSStringIterator::GetIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSStringIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("string", "v8::internal::TaggedValue", "v8::internal::String", GetStringAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("index", "v8::internal::TaggedValue", "v8::internal::Object", GetIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSPromise::GetName() const {
  return "v8::internal::JSPromise";
}

void TqJSPromise::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSPromise(this);
}

bool TqJSPromise::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSPromise*>(other) != nullptr;
}

uintptr_t TqJSPromise::GetReactionsOrResultAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSPromise::GetReactionsOrResultValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetReactionsOrResultAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSPromise::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSPromise::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSPromise::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("reactions_or_result", "v8::internal::TaggedValue", "v8::internal::Object", GetReactionsOrResultAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSProxyRevocableResult::GetName() const {
  return "v8::internal::JSProxyRevocableResult";
}

void TqJSProxyRevocableResult::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSProxyRevocableResult(this);
}

bool TqJSProxyRevocableResult::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSProxyRevocableResult*>(other) != nullptr;
}

uintptr_t TqJSProxyRevocableResult::GetProxyAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSProxyRevocableResult::GetProxyValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetProxyAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSProxyRevocableResult::GetRevokeAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSProxyRevocableResult::GetRevokeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRevokeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSProxyRevocableResult::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("proxy", "v8::internal::TaggedValue", "v8::internal::Object", GetProxyAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("revoke", "v8::internal::TaggedValue", "v8::internal::Object", GetRevokeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRegExpStringIterator::GetName() const {
  return "v8::internal::JSRegExpStringIterator";
}

void TqJSRegExpStringIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExpStringIterator(this);
}

bool TqJSRegExpStringIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExpStringIterator*>(other) != nullptr;
}

uintptr_t TqJSRegExpStringIterator::GetIteratingRegExpAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSRegExpStringIterator::GetIteratingRegExpValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIteratingRegExpAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpStringIterator::GetIteratedStringAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSRegExpStringIterator::GetIteratedStringValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIteratedStringAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpStringIterator::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSRegExpStringIterator::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExpStringIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("iterating_reg_exp", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetIteratingRegExpAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("iterated_string", "v8::internal::TaggedValue", "v8::internal::String", GetIteratedStringAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRegExp::GetName() const {
  return "v8::internal::JSRegExp";
}

void TqJSRegExp::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExp(this);
}

bool TqJSRegExp::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExp*>(other) != nullptr;
}

uintptr_t TqJSRegExp::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSRegExp::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExp::GetSourceAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSRegExp::GetSourceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExp::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSRegExp::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExp::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("source", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetSourceAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRegExpResult::GetName() const {
  return "v8::internal::JSRegExpResult";
}

void TqJSRegExpResult::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExpResult(this);
}

bool TqJSRegExpResult::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExpResult*>(other) != nullptr;
}

uintptr_t TqJSRegExpResult::GetIndexAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSRegExpResult::GetIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetInputAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSRegExpResult::GetInputValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInputAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetGroupsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSRegExpResult::GetGroupsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGroupsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetCachedIndicesOrRegexpAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSRegExpResult::GetCachedIndicesOrRegexpValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCachedIndicesOrRegexpAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetNamesAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSRegExpResult::GetNamesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNamesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetRegexpInputAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqJSRegExpResult::GetRegexpInputValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegexpInputAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSRegExpResult::GetRegexpLastIndexAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqJSRegExpResult::GetRegexpLastIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegexpLastIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExpResult::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArray::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("index", "v8::internal::TaggedValue", "v8::internal::Object", GetIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("input", "v8::internal::TaggedValue", "v8::internal::Object", GetInputAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("groups", "v8::internal::TaggedValue", "v8::internal::Object", GetGroupsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("cached_indices_or_regexp", "v8::internal::TaggedValue", "v8::internal::JSObject", GetCachedIndicesOrRegexpAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("names", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetNamesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("regexp_input", "v8::internal::TaggedValue", "v8::internal::String", GetRegexpInputAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("regexp_last_index", "v8::internal::TaggedValue", "v8::internal::Object", GetRegexpLastIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSRegExpResultIndices::GetName() const {
  return "v8::internal::JSRegExpResultIndices";
}

void TqJSRegExpResultIndices::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSRegExpResultIndices(this);
}

bool TqJSRegExpResultIndices::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSRegExpResultIndices*>(other) != nullptr;
}

uintptr_t TqJSRegExpResultIndices::GetGroupsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSRegExpResultIndices::GetGroupsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetGroupsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSRegExpResultIndices::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSArray::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("groups", "v8::internal::TaggedValue", "v8::internal::Object", GetGroupsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSFinalizationGroup::GetName() const {
  return "v8::internal::JSFinalizationGroup";
}

void TqJSFinalizationGroup::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSFinalizationGroup(this);
}

bool TqJSFinalizationGroup::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSFinalizationGroup*>(other) != nullptr;
}

uintptr_t TqJSFinalizationGroup::GetNativeContextAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSFinalizationGroup::GetNativeContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationGroup::GetCleanupAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqJSFinalizationGroup::GetCleanupValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCleanupAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationGroup::GetActiveCellsAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqJSFinalizationGroup::GetActiveCellsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetActiveCellsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationGroup::GetClearedCellsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqJSFinalizationGroup::GetClearedCellsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetClearedCellsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationGroup::GetKeyMapAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqJSFinalizationGroup::GetKeyMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeyMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationGroup::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqJSFinalizationGroup::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqJSFinalizationGroup::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqJSFinalizationGroup::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSFinalizationGroup::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("native_context", "v8::internal::TaggedValue", "v8::internal::NativeContext", GetNativeContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("cleanup", "v8::internal::TaggedValue", "v8::internal::Object", GetCleanupAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("active_cells", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetActiveCellsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("cleared_cells", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetClearedCellsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("key_map", "v8::internal::TaggedValue", "v8::internal::Object", GetKeyMapAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetNextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSFinalizationGroupCleanupIterator::GetName() const {
  return "v8::internal::JSFinalizationGroupCleanupIterator";
}

void TqJSFinalizationGroupCleanupIterator::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSFinalizationGroupCleanupIterator(this);
}

bool TqJSFinalizationGroupCleanupIterator::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSFinalizationGroupCleanupIterator*>(other) != nullptr;
}

uintptr_t TqJSFinalizationGroupCleanupIterator::GetFinalizationGroupAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSFinalizationGroupCleanupIterator::GetFinalizationGroupValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFinalizationGroupAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSFinalizationGroupCleanupIterator::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("finalization_group", "v8::internal::TaggedValue", "v8::internal::JSFinalizationGroup", GetFinalizationGroupAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWeakCell::GetName() const {
  return "v8::internal::WeakCell";
}

void TqWeakCell::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWeakCell(this);
}

bool TqWeakCell::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWeakCell*>(other) != nullptr;
}

uintptr_t TqWeakCell::GetFinalizationGroupAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqWeakCell::GetFinalizationGroupValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFinalizationGroupAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetTargetAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWeakCell::GetTargetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetHoldingsAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWeakCell::GetHoldingsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHoldingsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetPrevAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWeakCell::GetPrevValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrevAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWeakCell::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetKeyAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWeakCell::GetKeyValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeyAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetKeyListPrevAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqWeakCell::GetKeyListPrevValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeyListPrevAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWeakCell::GetKeyListNextAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqWeakCell::GetKeyListNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetKeyListNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWeakCell::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("finalization_group", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetFinalizationGroupAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("target", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetTargetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("holdings", "v8::internal::TaggedValue", "v8::internal::Object", GetHoldingsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("prev", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetPrevAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetNextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("key", "v8::internal::TaggedValue", "v8::internal::Object", GetKeyAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("key_list_prev", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetKeyListPrevAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("key_list_next", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetKeyListNextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSWeakRef::GetName() const {
  return "v8::internal::JSWeakRef";
}

void TqJSWeakRef::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSWeakRef(this);
}

bool TqJSWeakRef::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSWeakRef*>(other) != nullptr;
}

uintptr_t TqJSWeakRef::GetTargetAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSWeakRef::GetTargetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSWeakRef::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("target", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetTargetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqArrayBoilerplateDescription::GetName() const {
  return "v8::internal::ArrayBoilerplateDescription";
}

void TqArrayBoilerplateDescription::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitArrayBoilerplateDescription(this);
}

bool TqArrayBoilerplateDescription::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqArrayBoilerplateDescription*>(other) != nullptr;
}

uintptr_t TqArrayBoilerplateDescription::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqArrayBoilerplateDescription::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqArrayBoilerplateDescription::GetConstantElementsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqArrayBoilerplateDescription::GetConstantElementsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstantElementsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqArrayBoilerplateDescription::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("constant_elements", "v8::internal::TaggedValue", "v8::internal::FixedArrayBase", GetConstantElementsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqMicrotask::GetName() const {
  return "v8::internal::Microtask";
}

void TqMicrotask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitMicrotask(this);
}

bool TqMicrotask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqMicrotask*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqMicrotask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  return result;
}

const char* TqCallbackTask::GetName() const {
  return "v8::internal::CallbackTask";
}

void TqCallbackTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCallbackTask(this);
}

bool TqCallbackTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCallbackTask*>(other) != nullptr;
}

uintptr_t TqCallbackTask::GetCallbackAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqCallbackTask::GetCallbackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallbackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallbackTask::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqCallbackTask::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCallbackTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqMicrotask::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("callback", "v8::internal::TaggedValue", "v8::internal::Foreign", GetCallbackAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::TaggedValue", "v8::internal::Foreign", GetDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqCallableTask::GetName() const {
  return "v8::internal::CallableTask";
}

void TqCallableTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitCallableTask(this);
}

bool TqCallableTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqCallableTask*>(other) != nullptr;
}

uintptr_t TqCallableTask::GetCallableAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqCallableTask::GetCallableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqCallableTask::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqCallableTask::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqCallableTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqMicrotask::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("callable", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetCallableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::TaggedValue", "v8::internal::Context", GetContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqModule::GetName() const {
  return "v8::internal::Module";
}

void TqModule::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitModule(this);
}

bool TqModule::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqModule*>(other) != nullptr;
}

uintptr_t TqModule::GetExportsAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqModule::GetExportsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExportsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetHashAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqModule::GetHashValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetStatusAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqModule::GetStatusValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStatusAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetModuleNamespaceAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqModule::GetModuleNamespaceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetModuleNamespaceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqModule::GetExceptionAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqModule::GetExceptionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExceptionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqModule::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("exports", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetExportsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("hash", "v8::internal::TaggedValue", "v8::internal::Object", GetHashAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("status", "v8::internal::TaggedValue", "v8::internal::Object", GetStatusAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("module_namespace", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetModuleNamespaceAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("exception", "v8::internal::TaggedValue", "v8::internal::Object", GetExceptionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqJSModuleNamespace::GetName() const {
  return "v8::internal::JSModuleNamespace";
}

void TqJSModuleNamespace::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitJSModuleNamespace(this);
}

bool TqJSModuleNamespace::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqJSModuleNamespace*>(other) != nullptr;
}

uintptr_t TqJSModuleNamespace::GetModuleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqJSModuleNamespace::GetModuleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetModuleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqJSModuleNamespace::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSSpecialObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("module", "v8::internal::TaggedValue", "v8::internal::Module", GetModuleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPromiseCapability::GetName() const {
  return "v8::internal::PromiseCapability";
}

void TqPromiseCapability::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseCapability(this);
}

bool TqPromiseCapability::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseCapability*>(other) != nullptr;
}

uintptr_t TqPromiseCapability::GetPromiseAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqPromiseCapability::GetPromiseValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseCapability::GetResolveAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseCapability::GetResolveValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetResolveAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseCapability::GetRejectAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqPromiseCapability::GetRejectValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRejectAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseCapability::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("promise", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetPromiseAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("resolve", "v8::internal::TaggedValue", "v8::internal::Object", GetResolveAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("reject", "v8::internal::TaggedValue", "v8::internal::Object", GetRejectAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPromiseReaction::GetName() const {
  return "v8::internal::PromiseReaction";
}

void TqPromiseReaction::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseReaction(this);
}

bool TqPromiseReaction::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseReaction*>(other) != nullptr;
}

uintptr_t TqPromiseReaction::GetNextAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqPromiseReaction::GetNextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReaction::GetRejectHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseReaction::GetRejectHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRejectHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReaction::GetFulfillHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqPromiseReaction::GetFulfillHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFulfillHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReaction::GetPromiseOrCapabilityAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPromiseReaction::GetPromiseOrCapabilityValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseOrCapabilityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseReaction::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("next", "v8::internal::TaggedValue", "v8::internal::Object", GetNextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("reject_handler", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetRejectHandlerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("fulfill_handler", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetFulfillHandlerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("promise_or_capability", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetPromiseOrCapabilityAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPromiseReactionJobTask::GetName() const {
  return "v8::internal::PromiseReactionJobTask";
}

void TqPromiseReactionJobTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseReactionJobTask(this);
}

bool TqPromiseReactionJobTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseReactionJobTask*>(other) != nullptr;
}

uintptr_t TqPromiseReactionJobTask::GetArgumentAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetArgumentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetArgumentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReactionJobTask::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReactionJobTask::GetHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseReactionJobTask::GetPromiseOrCapabilityAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPromiseReactionJobTask::GetPromiseOrCapabilityValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseOrCapabilityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseReactionJobTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqMicrotask::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("argument", "v8::internal::TaggedValue", "v8::internal::Object", GetArgumentAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::TaggedValue", "v8::internal::Context", GetContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("handler", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetHandlerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("promise_or_capability", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetPromiseOrCapabilityAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPromiseFulfillReactionJobTask::GetName() const {
  return "v8::internal::PromiseFulfillReactionJobTask";
}

void TqPromiseFulfillReactionJobTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseFulfillReactionJobTask(this);
}

bool TqPromiseFulfillReactionJobTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseFulfillReactionJobTask*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseFulfillReactionJobTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPromiseReactionJobTask::GetProperties(accessor);
  return result;
}

const char* TqPromiseRejectReactionJobTask::GetName() const {
  return "v8::internal::PromiseRejectReactionJobTask";
}

void TqPromiseRejectReactionJobTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseRejectReactionJobTask(this);
}

bool TqPromiseRejectReactionJobTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseRejectReactionJobTask*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseRejectReactionJobTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqPromiseReactionJobTask::GetProperties(accessor);
  return result;
}

const char* TqPromiseResolveThenableJobTask::GetName() const {
  return "v8::internal::PromiseResolveThenableJobTask";
}

void TqPromiseResolveThenableJobTask::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPromiseResolveThenableJobTask(this);
}

bool TqPromiseResolveThenableJobTask::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPromiseResolveThenableJobTask*>(other) != nullptr;
}

uintptr_t TqPromiseResolveThenableJobTask::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqPromiseResolveThenableJobTask::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseResolveThenableJobTask::GetPromiseToResolveAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPromiseResolveThenableJobTask::GetPromiseToResolveValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseToResolveAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseResolveThenableJobTask::GetThenAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqPromiseResolveThenableJobTask::GetThenValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetThenAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPromiseResolveThenableJobTask::GetThenableAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPromiseResolveThenableJobTask::GetThenableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetThenableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPromiseResolveThenableJobTask::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqMicrotask::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::TaggedValue", "v8::internal::Context", GetContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("promise_to_resolve", "v8::internal::TaggedValue", "v8::internal::JSPromise", GetPromiseToResolveAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("then", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetThenAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("thenable", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetThenableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPropertyArray::GetName() const {
  return "v8::internal::PropertyArray";
}

void TqPropertyArray::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPropertyArray(this);
}

bool TqPropertyArray::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPropertyArray*>(other) != nullptr;
}

uintptr_t TqPropertyArray::GetLengthAndHashAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqPropertyArray::GetLengthAndHashValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAndHashAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPropertyArray::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("length_and_hash", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAndHashAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPropertyCell::GetName() const {
  return "v8::internal::PropertyCell";
}

void TqPropertyCell::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPropertyCell(this);
}

bool TqPropertyCell::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPropertyCell*>(other) != nullptr;
}

uintptr_t TqPropertyCell::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqPropertyCell::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyCell::GetPropertyDetailsRawAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPropertyCell::GetPropertyDetailsRawValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPropertyDetailsRawAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyCell::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqPropertyCell::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPropertyCell::GetDependentCodeAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPropertyCell::GetDependentCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDependentCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPropertyCell::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::TaggedValue", "v8::internal::Name", GetNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("property_details_raw", "v8::internal::TaggedValue", "v8::internal::Object", GetPropertyDetailsRawAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::TaggedValue", "v8::internal::Object", GetValueAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("dependent_code", "v8::internal::TaggedValue", "v8::internal::WeakFixedArray", GetDependentCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPrototypeInfo::GetName() const {
  return "v8::internal::PrototypeInfo";
}

void TqPrototypeInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPrototypeInfo(this);
}

bool TqPrototypeInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPrototypeInfo*>(other) != nullptr;
}

uintptr_t TqPrototypeInfo::GetJsModuleNamespaceAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqPrototypeInfo::GetJsModuleNamespaceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetJsModuleNamespaceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetPrototypeUsersAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqPrototypeInfo::GetPrototypeUsersValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeUsersAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetRegistrySlotAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqPrototypeInfo::GetRegistrySlotValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegistrySlotAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetValidityCellAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqPrototypeInfo::GetValidityCellValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValidityCellAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetObjectCreateMapAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqPrototypeInfo::GetObjectCreateMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetObjectCreateMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqPrototypeInfo::GetBitFieldAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqPrototypeInfo::GetBitFieldValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBitFieldAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPrototypeInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("js_module_namespace", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetJsModuleNamespaceAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("prototype_users", "v8::internal::TaggedValue", "v8::internal::Object", GetPrototypeUsersAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("registry_slot", "v8::internal::TaggedValue", "v8::internal::Object", GetRegistrySlotAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("validity_cell", "v8::internal::TaggedValue", "v8::internal::Object", GetValidityCellAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("object_create_map", "v8::internal::TaggedValue", "v8::internal::Object", GetObjectCreateMapAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("bit_field", "v8::internal::TaggedValue", "v8::internal::Object", GetBitFieldAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqRegExpMatchInfo::GetName() const {
  return "v8::internal::RegExpMatchInfo";
}

void TqRegExpMatchInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitRegExpMatchInfo(this);
}

bool TqRegExpMatchInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqRegExpMatchInfo*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqRegExpMatchInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqFixedArray::GetProperties(accessor);
  return result;
}

const char* TqScript::GetName() const {
  return "v8::internal::Script";
}

void TqScript::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitScript(this);
}

bool TqScript::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqScript*>(other) != nullptr;
}

uintptr_t TqScript::GetSourceAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqScript::GetSourceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqScript::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetLineOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqScript::GetLineOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLineOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetColumnOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqScript::GetColumnOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetColumnOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetContextAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqScript::GetContextValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetContextAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetScriptTypeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqScript::GetScriptTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetLineEndsAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqScript::GetLineEndsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLineEndsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetIdAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqScript::GetIdValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetEvalFromSharedOrWrappedArgumentsAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqScript::GetEvalFromSharedOrWrappedArgumentsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEvalFromSharedOrWrappedArgumentsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetEvalFromPositionAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqScript::GetEvalFromPositionValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEvalFromPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetSharedFunctionInfosAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqScript::GetSharedFunctionInfosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedFunctionInfosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqScript::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetSourceUrlAddress() const {
  return address_ - i::kHeapObjectTag + 52;
}

Value<uintptr_t> TqScript::GetSourceUrlValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceUrlAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetSourceMappingUrlAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqScript::GetSourceMappingUrlValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSourceMappingUrlAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqScript::GetHostDefinedOptionsAddress() const {
  return address_ - i::kHeapObjectTag + 60;
}

Value<uintptr_t> TqScript::GetHostDefinedOptionsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetHostDefinedOptionsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqScript::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("source", "v8::internal::TaggedValue", "v8::internal::Object", GetSourceAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::TaggedValue", "v8::internal::Object", GetNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("line_offset", "v8::internal::TaggedValue", "v8::internal::Object", GetLineOffsetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("column_offset", "v8::internal::TaggedValue", "v8::internal::Object", GetColumnOffsetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("context", "v8::internal::TaggedValue", "v8::internal::Object", GetContextAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script_type", "v8::internal::TaggedValue", "v8::internal::Object", GetScriptTypeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("line_ends", "v8::internal::TaggedValue", "v8::internal::Object", GetLineEndsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("id", "v8::internal::TaggedValue", "v8::internal::Object", GetIdAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("eval_from_shared_or_wrapped_arguments", "v8::internal::TaggedValue", "v8::internal::Object", GetEvalFromSharedOrWrappedArgumentsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("eval_from_position", "v8::internal::TaggedValue", "v8::internal::Object", GetEvalFromPositionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("shared_function_infos", "v8::internal::TaggedValue", "v8::internal::Object", GetSharedFunctionInfosAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("source_url", "v8::internal::TaggedValue", "v8::internal::Object", GetSourceUrlAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("source_mapping_url", "v8::internal::TaggedValue", "v8::internal::Object", GetSourceMappingUrlAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("host_defined_options", "v8::internal::TaggedValue", "v8::internal::Object", GetHostDefinedOptionsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqPreparseData::GetName() const {
  return "v8::internal::PreparseData";
}

void TqPreparseData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitPreparseData(this);
}

bool TqPreparseData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqPreparseData*>(other) != nullptr;
}

uintptr_t TqPreparseData::GetDataLengthAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqPreparseData::GetDataLengthValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetDataLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqPreparseData::GetChildrenLengthAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqPreparseData::GetChildrenLengthValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetChildrenLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqPreparseData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("data_length", "int32_t", "int32_t", GetDataLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("children_length", "int32_t", "int32_t", GetChildrenLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqInterpreterData::GetName() const {
  return "v8::internal::InterpreterData";
}

void TqInterpreterData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInterpreterData(this);
}

bool TqInterpreterData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInterpreterData*>(other) != nullptr;
}

uintptr_t TqInterpreterData::GetBytecodeArrayAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqInterpreterData::GetBytecodeArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBytecodeArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInterpreterData::GetInterpreterTrampolineAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqInterpreterData::GetInterpreterTrampolineValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInterpreterTrampolineAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqInterpreterData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("bytecode_array", "v8::internal::TaggedValue", "v8::internal::BytecodeArray", GetBytecodeArrayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("interpreter_trampoline", "v8::internal::TaggedValue", "v8::internal::Code", GetInterpreterTrampolineAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSharedFunctionInfo::GetName() const {
  return "v8::internal::SharedFunctionInfo";
}

void TqSharedFunctionInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSharedFunctionInfo(this);
}

bool TqSharedFunctionInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSharedFunctionInfo*>(other) != nullptr;
}

uintptr_t TqSharedFunctionInfo::GetFunctionDataAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqSharedFunctionInfo::GetFunctionDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSharedFunctionInfo::GetNameOrScopeInfoAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSharedFunctionInfo::GetNameOrScopeInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameOrScopeInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSharedFunctionInfo::GetOuterScopeInfoOrFeedbackMetadataAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqSharedFunctionInfo::GetOuterScopeInfoOrFeedbackMetadataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOuterScopeInfoOrFeedbackMetadataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSharedFunctionInfo::GetScriptOrDebugInfoAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSharedFunctionInfo::GetScriptOrDebugInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptOrDebugInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSharedFunctionInfo::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<int16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSharedFunctionInfo::GetLengthValue(d::MemoryAccessor accessor) const {
  int16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFormalParameterCountAddress() const {
  return address_ - i::kHeapObjectTag + 22;
}

Value<uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSharedFunctionInfo::GetFormalParameterCountValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetFormalParameterCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetExpectedNofPropertiesAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSharedFunctionInfo::GetExpectedNofPropertiesValue(d::MemoryAccessor accessor) const {
  uint16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetExpectedNofPropertiesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFunctionTokenOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 26;
}

Value<int16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSharedFunctionInfo::GetFunctionTokenOffsetValue(d::MemoryAccessor accessor) const {
  int16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetFunctionTokenOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSharedFunctionInfo::GetFlagsValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqSharedFunctionInfo::GetFunctionLiteralIdAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSharedFunctionInfo::GetFunctionLiteralIdValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetFunctionLiteralIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSharedFunctionInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("function_data", "v8::internal::TaggedValue", "v8::internal::Object", GetFunctionDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("name_or_scope_info", "v8::internal::TaggedValue", "v8::internal::Object", GetNameOrScopeInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("outer_scope_info_or_feedback_metadata", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetOuterScopeInfoOrFeedbackMetadataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script_or_debug_info", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetScriptOrDebugInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("length", "int16_t", "int16_t", GetLengthAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("formal_parameter_count", "uint16_t", "uint16_t", GetFormalParameterCountAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("expected_nof_properties", "uint16_t", "uint16_t", GetExpectedNofPropertiesAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("function_token_offset", "int16_t", "int16_t", GetFunctionTokenOffsetAddress(), 1, 2, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "int32_t", "int32_t", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("function_literal_id", "int32_t", "int32_t", GetFunctionLiteralIdAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqUncompiledData::GetName() const {
  return "v8::internal::UncompiledData";
}

void TqUncompiledData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUncompiledData(this);
}

bool TqUncompiledData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUncompiledData*>(other) != nullptr;
}

uintptr_t TqUncompiledData::GetInferredNameAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqUncompiledData::GetInferredNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInferredNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqUncompiledData::GetStartPositionAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqUncompiledData::GetStartPositionValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetStartPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqUncompiledData::GetEndPositionAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqUncompiledData::GetEndPositionValue(d::MemoryAccessor accessor) const {
  int32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetEndPositionAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqUncompiledData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqHeapObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("inferred_name", "v8::internal::TaggedValue", "v8::internal::String", GetInferredNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("start_position", "int32_t", "int32_t", GetStartPositionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("end_position", "int32_t", "int32_t", GetEndPositionAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqUncompiledDataWithoutPreparseData::GetName() const {
  return "v8::internal::UncompiledDataWithoutPreparseData";
}

void TqUncompiledDataWithoutPreparseData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUncompiledDataWithoutPreparseData(this);
}

bool TqUncompiledDataWithoutPreparseData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUncompiledDataWithoutPreparseData*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqUncompiledDataWithoutPreparseData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqUncompiledData::GetProperties(accessor);
  return result;
}

const char* TqUncompiledDataWithPreparseData::GetName() const {
  return "v8::internal::UncompiledDataWithPreparseData";
}

void TqUncompiledDataWithPreparseData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitUncompiledDataWithPreparseData(this);
}

bool TqUncompiledDataWithPreparseData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqUncompiledDataWithPreparseData*>(other) != nullptr;
}

uintptr_t TqUncompiledDataWithPreparseData::GetPreparseDataAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqUncompiledDataWithPreparseData::GetPreparseDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPreparseDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqUncompiledDataWithPreparseData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqUncompiledData::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("preparse_data", "v8::internal::TaggedValue", "v8::internal::PreparseData", GetPreparseDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSourceTextModule::GetName() const {
  return "v8::internal::SourceTextModule";
}

void TqSourceTextModule::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSourceTextModule(this);
}

bool TqSourceTextModule::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSourceTextModule*>(other) != nullptr;
}

uintptr_t TqSourceTextModule::GetCodeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSourceTextModule::GetCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetRegularExportsAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqSourceTextModule::GetRegularExportsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegularExportsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetRegularImportsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqSourceTextModule::GetRegularImportsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRegularImportsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetRequestedModulesAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqSourceTextModule::GetRequestedModulesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRequestedModulesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetScriptAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqSourceTextModule::GetScriptValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetImportMetaAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqSourceTextModule::GetImportMetaValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetImportMetaAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetAsyncParentModulesAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqSourceTextModule::GetAsyncParentModulesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAsyncParentModulesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetTopLevelCapabilityAddress() const {
  return address_ - i::kHeapObjectTag + 52;
}

Value<uintptr_t> TqSourceTextModule::GetTopLevelCapabilityValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTopLevelCapabilityAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetDfsIndexAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqSourceTextModule::GetDfsIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDfsIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetDfsAncestorIndexAddress() const {
  return address_ - i::kHeapObjectTag + 60;
}

Value<uintptr_t> TqSourceTextModule::GetDfsAncestorIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDfsAncestorIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetPendingAsyncDependenciesAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqSourceTextModule::GetPendingAsyncDependenciesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPendingAsyncDependenciesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModule::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 68;
}

Value<uintptr_t> TqSourceTextModule::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSourceTextModule::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqModule::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("code", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("regular_exports", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetRegularExportsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("regular_imports", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetRegularImportsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("requested_modules", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetRequestedModulesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script", "v8::internal::TaggedValue", "v8::internal::Script", GetScriptAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("import_meta", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetImportMetaAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("async_parent_modules", "v8::internal::TaggedValue", "v8::internal::ArrayList", GetAsyncParentModulesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("top_level_capability", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetTopLevelCapabilityAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("dfs_index", "v8::internal::TaggedValue", "v8::internal::Object", GetDfsIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("dfs_ancestor_index", "v8::internal::TaggedValue", "v8::internal::Object", GetDfsAncestorIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("pending_async_dependencies", "v8::internal::TaggedValue", "v8::internal::Object", GetPendingAsyncDependenciesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSourceTextModuleInfoEntry::GetName() const {
  return "v8::internal::SourceTextModuleInfoEntry";
}

void TqSourceTextModuleInfoEntry::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSourceTextModuleInfoEntry(this);
}

bool TqSourceTextModuleInfoEntry::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSourceTextModuleInfoEntry*>(other) != nullptr;
}

uintptr_t TqSourceTextModuleInfoEntry::GetExportNameAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetExportNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExportNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetLocalNameAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetLocalNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocalNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetImportNameAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetImportNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetImportNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetModuleRequestAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetModuleRequestValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetModuleRequestAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetCellIndexAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetCellIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCellIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetBegPosAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetBegPosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBegPosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSourceTextModuleInfoEntry::GetEndPosAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqSourceTextModuleInfoEntry::GetEndPosValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEndPosAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSourceTextModuleInfoEntry::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("export_name", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetExportNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("local_name", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetLocalNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("import_name", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetImportNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("module_request", "v8::internal::TaggedValue", "v8::internal::Object", GetModuleRequestAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("cell_index", "v8::internal::TaggedValue", "v8::internal::Object", GetCellIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("beg_pos", "v8::internal::TaggedValue", "v8::internal::Object", GetBegPosAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("end_pos", "v8::internal::TaggedValue", "v8::internal::Object", GetEndPosAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqStackFrameInfo::GetName() const {
  return "v8::internal::StackFrameInfo";
}

void TqStackFrameInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitStackFrameInfo(this);
}

bool TqStackFrameInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqStackFrameInfo*>(other) != nullptr;
}

uintptr_t TqStackFrameInfo::GetLineNumberAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqStackFrameInfo::GetLineNumberValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLineNumberAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetColumnNumberAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqStackFrameInfo::GetColumnNumberValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetColumnNumberAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetPromiseAllIndexAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqStackFrameInfo::GetPromiseAllIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPromiseAllIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetScriptIdAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqStackFrameInfo::GetScriptIdValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetWasmFunctionIndexAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqStackFrameInfo::GetWasmFunctionIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWasmFunctionIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetScriptNameAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqStackFrameInfo::GetScriptNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetScriptNameOrSourceUrlAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqStackFrameInfo::GetScriptNameOrSourceUrlValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptNameOrSourceUrlAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetFunctionNameAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqStackFrameInfo::GetFunctionNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetMethodNameAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqStackFrameInfo::GetMethodNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMethodNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetTypeNameAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqStackFrameInfo::GetTypeNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTypeNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetEvalOriginAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqStackFrameInfo::GetEvalOriginValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEvalOriginAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetWasmModuleNameAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqStackFrameInfo::GetWasmModuleNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWasmModuleNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetWasmInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 52;
}

Value<uintptr_t> TqStackFrameInfo::GetWasmInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWasmInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackFrameInfo::GetFlagAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqStackFrameInfo::GetFlagValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqStackFrameInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("line_number", "v8::internal::TaggedValue", "v8::internal::Object", GetLineNumberAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("column_number", "v8::internal::TaggedValue", "v8::internal::Object", GetColumnNumberAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("promise_all_index", "v8::internal::TaggedValue", "v8::internal::Object", GetPromiseAllIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script_id", "v8::internal::TaggedValue", "v8::internal::Object", GetScriptIdAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("wasm_function_index", "v8::internal::TaggedValue", "v8::internal::Object", GetWasmFunctionIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script_name", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetScriptNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script_name_or_source_url", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetScriptNameOrSourceUrlAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("function_name", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetFunctionNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("method_name", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetMethodNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("type_name", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetTypeNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("eval_origin", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetEvalOriginAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("wasm_module_name", "v8::internal::TaggedValue", "v8::internal::PrimitiveHeapObject", GetWasmModuleNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("wasm_instance", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetWasmInstanceAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flag", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqStackTraceFrame::GetName() const {
  return "v8::internal::StackTraceFrame";
}

void TqStackTraceFrame::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitStackTraceFrame(this);
}

bool TqStackTraceFrame::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqStackTraceFrame*>(other) != nullptr;
}

uintptr_t TqStackTraceFrame::GetFrameArrayAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqStackTraceFrame::GetFrameArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFrameArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackTraceFrame::GetFrameIndexAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqStackTraceFrame::GetFrameIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFrameIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackTraceFrame::GetFrameInfoAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqStackTraceFrame::GetFrameInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFrameInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqStackTraceFrame::GetIdAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqStackTraceFrame::GetIdValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIdAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqStackTraceFrame::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("frame_array", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetFrameArrayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("frame_index", "v8::internal::TaggedValue", "v8::internal::Object", GetFrameIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("frame_info", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetFrameInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("id", "v8::internal::TaggedValue", "v8::internal::Object", GetIdAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqConsString::GetName() const {
  return "v8::internal::ConsString";
}

void TqConsString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitConsString(this);
}

bool TqConsString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqConsString*>(other) != nullptr;
}

uintptr_t TqConsString::GetFirstAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqConsString::GetFirstValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFirstAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqConsString::GetSecondAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqConsString::GetSecondValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSecondAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqConsString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("first", "v8::internal::TaggedValue", "v8::internal::String", GetFirstAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("second", "v8::internal::TaggedValue", "v8::internal::String", GetSecondAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqExternalString::GetName() const {
  return "v8::internal::ExternalString";
}

void TqExternalString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExternalString(this);
}

bool TqExternalString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExternalString*>(other) != nullptr;
}

uintptr_t TqExternalString::GetResourceAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqExternalString::GetResourceValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetResourceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqExternalString::GetResourceDataAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqExternalString::GetResourceDataValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetResourceDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqExternalString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("resource", "void*", "void*", GetResourceAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("resource_data", "void*", "void*", GetResourceDataAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqExternalOneByteString::GetName() const {
  return "v8::internal::ExternalOneByteString";
}

void TqExternalOneByteString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExternalOneByteString(this);
}

bool TqExternalOneByteString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExternalOneByteString*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqExternalOneByteString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqExternalString::GetProperties(accessor);
  return result;
}

const char* TqExternalTwoByteString::GetName() const {
  return "v8::internal::ExternalTwoByteString";
}

void TqExternalTwoByteString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitExternalTwoByteString(this);
}

bool TqExternalTwoByteString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqExternalTwoByteString*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqExternalTwoByteString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqExternalString::GetProperties(accessor);
  return result;
}

const char* TqInternalizedString::GetName() const {
  return "v8::internal::InternalizedString";
}

void TqInternalizedString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInternalizedString(this);
}

bool TqInternalizedString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInternalizedString*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqInternalizedString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  return result;
}

const char* TqSeqString::GetName() const {
  return "v8::internal::SeqString";
}

void TqSeqString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSeqString(this);
}

bool TqSeqString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSeqString*>(other) != nullptr;
}

std::vector<std::unique_ptr<ObjectProperty>> TqSeqString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  return result;
}

const char* TqSeqOneByteString::GetName() const {
  return "v8::internal::SeqOneByteString";
}

void TqSeqOneByteString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSeqOneByteString(this);
}

bool TqSeqOneByteString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSeqOneByteString*>(other) != nullptr;
}

uintptr_t TqSeqOneByteString::GetCharsAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<char /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSeqOneByteString::GetCharsValue(d::MemoryAccessor accessor, size_t offset) const {
  char /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetCharsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSeqOneByteString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqSeqString::GetProperties(accessor);
  Value<int32_t> indexed_field_count = GetLengthValue(accessor);
  result.push_back(std::make_unique<ObjectProperty>("chars", "char", "char", GetCharsAddress(), indexed_field_count.value, 1, std::vector<std::unique_ptr<StructProperty>>(), GetArrayKind(indexed_field_count.validity)));
  return result;
}

const char* TqSeqTwoByteString::GetName() const {
  return "v8::internal::SeqTwoByteString";
}

void TqSeqTwoByteString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSeqTwoByteString(this);
}

bool TqSeqTwoByteString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSeqTwoByteString*>(other) != nullptr;
}

uintptr_t TqSeqTwoByteString::GetCharsAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<char16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqSeqTwoByteString::GetCharsValue(d::MemoryAccessor accessor, size_t offset) const {
  char16_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetCharsAddress() + offset * sizeof(value), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSeqTwoByteString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqSeqString::GetProperties(accessor);
  Value<int32_t> indexed_field_count = GetLengthValue(accessor);
  result.push_back(std::make_unique<ObjectProperty>("chars", "char16_t", "char16_t", GetCharsAddress(), indexed_field_count.value, 2, std::vector<std::unique_ptr<StructProperty>>(), GetArrayKind(indexed_field_count.validity)));
  return result;
}

const char* TqSlicedString::GetName() const {
  return "v8::internal::SlicedString";
}

void TqSlicedString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSlicedString(this);
}

bool TqSlicedString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSlicedString*>(other) != nullptr;
}

uintptr_t TqSlicedString::GetParentAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqSlicedString::GetParentValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParentAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSlicedString::GetOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSlicedString::GetOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSlicedString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("parent", "v8::internal::TaggedValue", "v8::internal::String", GetParentAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("offset", "v8::internal::TaggedValue", "v8::internal::Object", GetOffsetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqThinString::GetName() const {
  return "v8::internal::ThinString";
}

void TqThinString::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitThinString(this);
}

bool TqThinString::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqThinString*>(other) != nullptr;
}

uintptr_t TqThinString::GetActualAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqThinString::GetActualValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetActualAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqThinString::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqString::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("actual", "v8::internal::TaggedValue", "v8::internal::String", GetActualAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqTuple3::GetName() const {
  return "v8::internal::Tuple3";
}

void TqTuple3::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTuple3(this);
}

bool TqTuple3::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTuple3*>(other) != nullptr;
}

uintptr_t TqTuple3::GetValue1Address() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqTuple3::GetValue1Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValue1Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTuple3::GetValue2Address() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTuple3::GetValue2Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValue2Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTuple3::GetValue3Address() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqTuple3::GetValue3Value(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValue3Address(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTuple3::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("value1", "v8::internal::TaggedValue", "v8::internal::Object", GetValue1Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("value2", "v8::internal::TaggedValue", "v8::internal::Object", GetValue2Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("value3", "v8::internal::TaggedValue", "v8::internal::Object", GetValue3Address(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSyntheticModule::GetName() const {
  return "v8::internal::SyntheticModule";
}

void TqSyntheticModule::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSyntheticModule(this);
}

bool TqSyntheticModule::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSyntheticModule*>(other) != nullptr;
}

uintptr_t TqSyntheticModule::GetNameAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSyntheticModule::GetNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSyntheticModule::GetExportNamesAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqSyntheticModule::GetExportNamesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExportNamesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSyntheticModule::GetEvaluationStepsAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqSyntheticModule::GetEvaluationStepsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEvaluationStepsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSyntheticModule::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqModule::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("name", "v8::internal::TaggedValue", "v8::internal::String", GetNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("export_names", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetExportNamesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("evaluation_steps", "v8::internal::TaggedValue", "v8::internal::Foreign", GetEvaluationStepsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqTemplateObjectDescription::GetName() const {
  return "v8::internal::TemplateObjectDescription";
}

void TqTemplateObjectDescription::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTemplateObjectDescription(this);
}

bool TqTemplateObjectDescription::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTemplateObjectDescription*>(other) != nullptr;
}

uintptr_t TqTemplateObjectDescription::GetRawStringsAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqTemplateObjectDescription::GetRawStringsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRawStringsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateObjectDescription::GetCookedStringsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTemplateObjectDescription::GetCookedStringsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCookedStringsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTemplateObjectDescription::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("raw_strings", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetRawStringsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("cooked_strings", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetCookedStringsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqTemplateInfo::GetName() const {
  return "v8::internal::TemplateInfo";
}

void TqTemplateInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitTemplateInfo(this);
}

bool TqTemplateInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqTemplateInfo*>(other) != nullptr;
}

uintptr_t TqTemplateInfo::GetTagAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqTemplateInfo::GetTagValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTagAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateInfo::GetSerialNumberAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqTemplateInfo::GetSerialNumberValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerialNumberAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateInfo::GetNumberOfPropertiesAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqTemplateInfo::GetNumberOfPropertiesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfPropertiesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateInfo::GetPropertyListAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqTemplateInfo::GetPropertyListValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPropertyListAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqTemplateInfo::GetPropertyAccessorsAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqTemplateInfo::GetPropertyAccessorsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPropertyAccessorsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqTemplateInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("tag", "v8::internal::TaggedValue", "v8::internal::Object", GetTagAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("serial_number", "v8::internal::TaggedValue", "v8::internal::Object", GetSerialNumberAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("number_of_properties", "v8::internal::TaggedValue", "v8::internal::Object", GetNumberOfPropertiesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("property_list", "v8::internal::TaggedValue", "v8::internal::Object", GetPropertyListAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("property_accessors", "v8::internal::TaggedValue", "v8::internal::Object", GetPropertyAccessorsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqFunctionTemplateRareData::GetName() const {
  return "v8::internal::FunctionTemplateRareData";
}

void TqFunctionTemplateRareData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFunctionTemplateRareData(this);
}

bool TqFunctionTemplateRareData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFunctionTemplateRareData*>(other) != nullptr;
}

uintptr_t TqFunctionTemplateRareData::GetPrototypeTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetPrototypeTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetPrototypeProviderTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetPrototypeProviderTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPrototypeProviderTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetParentTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetParentTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetParentTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetNamedPropertyHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetNamedPropertyHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNamedPropertyHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetIndexedPropertyHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetIndexedPropertyHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexedPropertyHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetInstanceTemplateAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetInstanceTemplateValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceTemplateAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetInstanceCallHandlerAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetInstanceCallHandlerValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceCallHandlerAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateRareData::GetAccessCheckInfoAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqFunctionTemplateRareData::GetAccessCheckInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAccessCheckInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFunctionTemplateRareData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("prototype_template", "v8::internal::TaggedValue", "v8::internal::Object", GetPrototypeTemplateAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("prototype_provider_template", "v8::internal::TaggedValue", "v8::internal::Object", GetPrototypeProviderTemplateAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("parent_template", "v8::internal::TaggedValue", "v8::internal::Object", GetParentTemplateAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("named_property_handler", "v8::internal::TaggedValue", "v8::internal::Object", GetNamedPropertyHandlerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("indexed_property_handler", "v8::internal::TaggedValue", "v8::internal::Object", GetIndexedPropertyHandlerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("instance_template", "v8::internal::TaggedValue", "v8::internal::Object", GetInstanceTemplateAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("instance_call_handler", "v8::internal::TaggedValue", "v8::internal::Object", GetInstanceCallHandlerAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("access_check_info", "v8::internal::TaggedValue", "v8::internal::Object", GetAccessCheckInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqFunctionTemplateInfo::GetName() const {
  return "v8::internal::FunctionTemplateInfo";
}

void TqFunctionTemplateInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitFunctionTemplateInfo(this);
}

bool TqFunctionTemplateInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqFunctionTemplateInfo*>(other) != nullptr;
}

uintptr_t TqFunctionTemplateInfo::GetCallCodeAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetCallCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetClassNameAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetClassNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetClassNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetSignatureAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetSignatureValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSignatureAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetRareDataAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetRareDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRareDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetSharedFunctionInfoAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetSharedFunctionInfoValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSharedFunctionInfoAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetFlagAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetFlagValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetLengthAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqFunctionTemplateInfo::GetCachedPropertyNameAddress() const {
  return address_ - i::kHeapObjectTag + 52;
}

Value<uintptr_t> TqFunctionTemplateInfo::GetCachedPropertyNameValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCachedPropertyNameAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqFunctionTemplateInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTemplateInfo::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("call_code", "v8::internal::TaggedValue", "v8::internal::Object", GetCallCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("class_name", "v8::internal::TaggedValue", "v8::internal::Object", GetClassNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("signature", "v8::internal::TaggedValue", "v8::internal::Object", GetSignatureAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("rare_data", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetRareDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("shared_function_info", "v8::internal::TaggedValue", "v8::internal::Object", GetSharedFunctionInfoAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flag", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("length", "v8::internal::TaggedValue", "v8::internal::Object", GetLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("cached_property_name", "v8::internal::TaggedValue", "v8::internal::Object", GetCachedPropertyNameAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqObjectTemplateInfo::GetName() const {
  return "v8::internal::ObjectTemplateInfo";
}

void TqObjectTemplateInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitObjectTemplateInfo(this);
}

bool TqObjectTemplateInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqObjectTemplateInfo*>(other) != nullptr;
}

uintptr_t TqObjectTemplateInfo::GetConstructorAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqObjectTemplateInfo::GetConstructorValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetConstructorAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqObjectTemplateInfo::GetDataAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqObjectTemplateInfo::GetDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqObjectTemplateInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqTemplateInfo::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("constructor", "v8::internal::TaggedValue", "v8::internal::Object", GetConstructorAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("data", "v8::internal::TaggedValue", "v8::internal::Object", GetDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmExportedFunctionData::GetName() const {
  return "v8::internal::WasmExportedFunctionData";
}

void TqWasmExportedFunctionData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmExportedFunctionData(this);
}

bool TqWasmExportedFunctionData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmExportedFunctionData*>(other) != nullptr;
}

uintptr_t TqWasmExportedFunctionData::GetWrapperCodeAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetWrapperCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWrapperCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetJumpTableOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetJumpTableOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetJumpTableOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetFunctionIndexAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetFunctionIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFunctionIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetCWrapperCodeAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetCWrapperCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCWrapperCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetWasmCallTargetAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetWasmCallTargetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWasmCallTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExportedFunctionData::GetPackedArgsSizeAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqWasmExportedFunctionData::GetPackedArgsSizeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPackedArgsSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmExportedFunctionData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("wrapper_code", "v8::internal::TaggedValue", "v8::internal::Code", GetWrapperCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("instance", "v8::internal::TaggedValue", "v8::internal::WasmInstanceObject", GetInstanceAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("jump_table_offset", "v8::internal::TaggedValue", "v8::internal::Object", GetJumpTableOffsetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("function_index", "v8::internal::TaggedValue", "v8::internal::Object", GetFunctionIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("c_wrapper_code", "v8::internal::TaggedValue", "v8::internal::Object", GetCWrapperCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("wasm_call_target", "v8::internal::TaggedValue", "v8::internal::Object", GetWasmCallTargetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("packed_args_size", "v8::internal::TaggedValue", "v8::internal::Object", GetPackedArgsSizeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmJSFunctionData::GetName() const {
  return "v8::internal::WasmJSFunctionData";
}

void TqWasmJSFunctionData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmJSFunctionData(this);
}

bool TqWasmJSFunctionData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmJSFunctionData*>(other) != nullptr;
}

uintptr_t TqWasmJSFunctionData::GetCallableAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqWasmJSFunctionData::GetCallableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCallableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmJSFunctionData::GetWrapperCodeAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmJSFunctionData::GetWrapperCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWrapperCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmJSFunctionData::GetSerializedReturnCountAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmJSFunctionData::GetSerializedReturnCountValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerializedReturnCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmJSFunctionData::GetSerializedParameterCountAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmJSFunctionData::GetSerializedParameterCountValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerializedParameterCountAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmJSFunctionData::GetSerializedSignatureAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWasmJSFunctionData::GetSerializedSignatureValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerializedSignatureAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmJSFunctionData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("callable", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetCallableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("wrapper_code", "v8::internal::TaggedValue", "v8::internal::Code", GetWrapperCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("serialized_return_count", "v8::internal::TaggedValue", "v8::internal::Object", GetSerializedReturnCountAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("serialized_parameter_count", "v8::internal::TaggedValue", "v8::internal::Object", GetSerializedParameterCountAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("serialized_signature", "v8::internal::TaggedValue", "v8::internal::ByteArray", GetSerializedSignatureAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmCapiFunctionData::GetName() const {
  return "v8::internal::WasmCapiFunctionData";
}

void TqWasmCapiFunctionData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmCapiFunctionData(this);
}

bool TqWasmCapiFunctionData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmCapiFunctionData*>(other) != nullptr;
}

uintptr_t TqWasmCapiFunctionData::GetCallTargetAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqWasmCapiFunctionData::GetCallTargetValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetCallTargetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmCapiFunctionData::GetEmbedderDataAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmCapiFunctionData::GetEmbedderDataValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEmbedderDataAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmCapiFunctionData::GetWrapperCodeAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmCapiFunctionData::GetWrapperCodeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWrapperCodeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmCapiFunctionData::GetSerializedSignatureAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWasmCapiFunctionData::GetSerializedSignatureValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerializedSignatureAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmCapiFunctionData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("call_target", "void*", "void*", GetCallTargetAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("embedder_data", "v8::internal::TaggedValue", "v8::internal::Foreign", GetEmbedderDataAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("wrapper_code", "v8::internal::TaggedValue", "v8::internal::Code", GetWrapperCodeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("serialized_signature", "v8::internal::TaggedValue", "v8::internal::ByteArray", GetSerializedSignatureAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmIndirectFunctionTable::GetName() const {
  return "v8::internal::WasmIndirectFunctionTable";
}

void TqWasmIndirectFunctionTable::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmIndirectFunctionTable(this);
}

bool TqWasmIndirectFunctionTable::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmIndirectFunctionTable*>(other) != nullptr;
}

uintptr_t TqWasmIndirectFunctionTable::GetSizeAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uint32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqWasmIndirectFunctionTable::GetSizeValue(d::MemoryAccessor accessor) const {
  uint32_t /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmIndirectFunctionTable::GetSigIdsAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqWasmIndirectFunctionTable::GetSigIdsValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetSigIdsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmIndirectFunctionTable::GetTargetsAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/> TqWasmIndirectFunctionTable::GetTargetsValue(d::MemoryAccessor accessor) const {
  void* /*Failing? Ensure constexpr type name is fully qualified and necessary #includes are in debug-helper-internal.h*/ value{};
  d::MemoryAccessResult validity = accessor(GetTargetsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, value};
}

uintptr_t TqWasmIndirectFunctionTable::GetManagedNativeAllocationsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmIndirectFunctionTable::GetManagedNativeAllocationsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetManagedNativeAllocationsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmIndirectFunctionTable::GetRefsAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqWasmIndirectFunctionTable::GetRefsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRefsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmIndirectFunctionTable::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("size", "uint32_t", "uint32_t", GetSizeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("sig_ids", "void*", "void*", GetSigIdsAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("targets", "void*", "void*", GetTargetsAddress(), 1, 8, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("managed_native_allocations", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetManagedNativeAllocationsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("refs", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetRefsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmDebugInfo::GetName() const {
  return "v8::internal::WasmDebugInfo";
}

void TqWasmDebugInfo::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmDebugInfo(this);
}

bool TqWasmDebugInfo::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmDebugInfo*>(other) != nullptr;
}

uintptr_t TqWasmDebugInfo::GetInstanceAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqWasmDebugInfo::GetInstanceValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstanceAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmDebugInfo::GetInterpreterHandleAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqWasmDebugInfo::GetInterpreterHandleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInterpreterHandleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmDebugInfo::GetInterpreterReferenceStackAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmDebugInfo::GetInterpreterReferenceStackValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInterpreterReferenceStackAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmDebugInfo::GetLocalsNamesAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmDebugInfo::GetLocalsNamesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLocalsNamesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmDebugInfo::GetCWasmEntriesAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWasmDebugInfo::GetCWasmEntriesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCWasmEntriesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmDebugInfo::GetCWasmEntryMapAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmDebugInfo::GetCWasmEntryMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCWasmEntryMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmDebugInfo::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("instance", "v8::internal::TaggedValue", "v8::internal::WasmInstanceObject", GetInstanceAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("interpreter_handle", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetInterpreterHandleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("interpreter_reference_stack", "v8::internal::TaggedValue", "v8::internal::Cell", GetInterpreterReferenceStackAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("locals_names", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetLocalsNamesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("c_wasm_entries", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetCWasmEntriesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("c_wasm_entry_map", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetCWasmEntryMapAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmExceptionTag::GetName() const {
  return "v8::internal::WasmExceptionTag";
}

void TqWasmExceptionTag::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmExceptionTag(this);
}

bool TqWasmExceptionTag::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmExceptionTag*>(other) != nullptr;
}

uintptr_t TqWasmExceptionTag::GetIndexAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqWasmExceptionTag::GetIndexValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetIndexAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmExceptionTag::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("index", "v8::internal::TaggedValue", "v8::internal::Object", GetIndexAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmModuleObject::GetName() const {
  return "v8::internal::WasmModuleObject";
}

void TqWasmModuleObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmModuleObject(this);
}

bool TqWasmModuleObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmModuleObject*>(other) != nullptr;
}

uintptr_t TqWasmModuleObject::GetNativeModuleAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmModuleObject::GetNativeModuleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNativeModuleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmModuleObject::GetExportWrappersAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmModuleObject::GetExportWrappersValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExportWrappersAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmModuleObject::GetScriptAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWasmModuleObject::GetScriptValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetScriptAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmModuleObject::GetAsmJsOffsetTableAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmModuleObject::GetAsmJsOffsetTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAsmJsOffsetTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmModuleObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("native_module", "v8::internal::TaggedValue", "v8::internal::Foreign", GetNativeModuleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("export_wrappers", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetExportWrappersAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("script", "v8::internal::TaggedValue", "v8::internal::Script", GetScriptAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("asm_js_offset_table", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetAsmJsOffsetTableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmTableObject::GetName() const {
  return "v8::internal::WasmTableObject";
}

void TqWasmTableObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmTableObject(this);
}

bool TqWasmTableObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmTableObject*>(other) != nullptr;
}

uintptr_t TqWasmTableObject::GetEntriesAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmTableObject::GetEntriesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetEntriesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetCurrentLengthAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmTableObject::GetCurrentLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCurrentLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetMaximumLengthAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWasmTableObject::GetMaximumLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMaximumLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetDispatchTablesAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmTableObject::GetDispatchTablesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDispatchTablesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmTableObject::GetRawTypeAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqWasmTableObject::GetRawTypeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetRawTypeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmTableObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("entries", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetEntriesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("current_length", "v8::internal::TaggedValue", "v8::internal::Object", GetCurrentLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("maximum_length", "v8::internal::TaggedValue", "v8::internal::Object", GetMaximumLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("dispatch_tables", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetDispatchTablesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("raw_type", "v8::internal::TaggedValue", "v8::internal::Object", GetRawTypeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmMemoryObject::GetName() const {
  return "v8::internal::WasmMemoryObject";
}

void TqWasmMemoryObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmMemoryObject(this);
}

bool TqWasmMemoryObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmMemoryObject*>(other) != nullptr;
}

uintptr_t TqWasmMemoryObject::GetArrayBufferAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmMemoryObject::GetArrayBufferValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetArrayBufferAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmMemoryObject::GetMaximumPagesAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmMemoryObject::GetMaximumPagesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMaximumPagesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmMemoryObject::GetInstancesAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWasmMemoryObject::GetInstancesValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInstancesAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmMemoryObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("array_buffer", "v8::internal::TaggedValue", "v8::internal::JSArrayBuffer", GetArrayBufferAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("maximum_pages", "v8::internal::TaggedValue", "v8::internal::Object", GetMaximumPagesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("instances", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetInstancesAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmGlobalObject::GetName() const {
  return "v8::internal::WasmGlobalObject";
}

void TqWasmGlobalObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmGlobalObject(this);
}

bool TqWasmGlobalObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmGlobalObject*>(other) != nullptr;
}

uintptr_t TqWasmGlobalObject::GetUntaggedBufferAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmGlobalObject::GetUntaggedBufferValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUntaggedBufferAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmGlobalObject::GetTaggedBufferAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmGlobalObject::GetTaggedBufferValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTaggedBufferAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmGlobalObject::GetOffsetAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqWasmGlobalObject::GetOffsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetOffsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmGlobalObject::GetFlagsAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqWasmGlobalObject::GetFlagsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetFlagsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmGlobalObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("untagged_buffer", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetUntaggedBufferAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("tagged_buffer", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetTaggedBufferAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("offset", "v8::internal::TaggedValue", "v8::internal::Object", GetOffsetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("flags", "v8::internal::TaggedValue", "v8::internal::Object", GetFlagsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqWasmExceptionObject::GetName() const {
  return "v8::internal::WasmExceptionObject";
}

void TqWasmExceptionObject::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitWasmExceptionObject(this);
}

bool TqWasmExceptionObject::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqWasmExceptionObject*>(other) != nullptr;
}

uintptr_t TqWasmExceptionObject::GetSerializedSignatureAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqWasmExceptionObject::GetSerializedSignatureValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSerializedSignatureAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqWasmExceptionObject::GetExceptionTagAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqWasmExceptionObject::GetExceptionTagValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExceptionTagAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqWasmExceptionObject::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqJSObject::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("serialized_signature", "v8::internal::TaggedValue", "v8::internal::ByteArray", GetSerializedSignatureAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("exception_tag", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetExceptionTagAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqAsmWasmData::GetName() const {
  return "v8::internal::AsmWasmData";
}

void TqAsmWasmData::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitAsmWasmData(this);
}

bool TqAsmWasmData::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqAsmWasmData*>(other) != nullptr;
}

uintptr_t TqAsmWasmData::GetManagedNativeModuleAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqAsmWasmData::GetManagedNativeModuleValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetManagedNativeModuleAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsmWasmData::GetExportWrappersAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqAsmWasmData::GetExportWrappersValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetExportWrappersAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsmWasmData::GetAsmJsOffsetTableAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqAsmWasmData::GetAsmJsOffsetTableValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAsmJsOffsetTableAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqAsmWasmData::GetUsesBitsetAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqAsmWasmData::GetUsesBitsetValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUsesBitsetAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqAsmWasmData::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("managed_native_module", "v8::internal::TaggedValue", "v8::internal::Foreign", GetManagedNativeModuleAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("export_wrappers", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetExportWrappersAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("asm_js_offset_table", "v8::internal::TaggedValue", "v8::internal::ByteArray", GetAsmJsOffsetTableAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("uses_bitset", "v8::internal::TaggedValue", "v8::internal::HeapNumber", GetUsesBitsetAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqInternalClass::GetName() const {
  return "v8::internal::InternalClass";
}

void TqInternalClass::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitInternalClass(this);
}

bool TqInternalClass::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqInternalClass*>(other) != nullptr;
}

uintptr_t TqInternalClass::GetAAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqInternalClass::GetAValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqInternalClass::GetBAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqInternalClass::GetBValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqInternalClass::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("a", "v8::internal::TaggedValue", "v8::internal::Object", GetAAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("b", "v8::internal::TaggedValue", "v8::internal::Object", GetBAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSmiPair::GetName() const {
  return "v8::internal::SmiPair";
}

void TqSmiPair::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSmiPair(this);
}

bool TqSmiPair::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSmiPair*>(other) != nullptr;
}

uintptr_t TqSmiPair::GetAAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqSmiPair::GetAValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetAAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSmiPair::GetBAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSmiPair::GetBValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetBAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSmiPair::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("a", "v8::internal::TaggedValue", "v8::internal::Object", GetAAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("b", "v8::internal::TaggedValue", "v8::internal::Object", GetBAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSmiBox::GetName() const {
  return "v8::internal::SmiBox";
}

void TqSmiBox::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSmiBox(this);
}

bool TqSmiBox::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSmiBox*>(other) != nullptr;
}

uintptr_t TqSmiBox::GetValueAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqSmiBox::GetValueValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetValueAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSmiBox::GetUnrelatedAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSmiBox::GetUnrelatedValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUnrelatedAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSmiBox::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("value", "v8::internal::TaggedValue", "v8::internal::Object", GetValueAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("unrelated", "v8::internal::TaggedValue", "v8::internal::Object", GetUnrelatedAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* TqSortState::GetName() const {
  return "v8::internal::SortState";
}

void TqSortState::Visit(TqObjectVisitor* visitor) const {
  visitor->VisitSortState(this);
}

bool TqSortState::IsSuperclassOf(const TqObject* other) const {
  return GetName() != other->GetName() && dynamic_cast<const TqSortState*>(other) != nullptr;
}

uintptr_t TqSortState::GetReceiverAddress() const {
  return address_ - i::kHeapObjectTag + 4;
}

Value<uintptr_t> TqSortState::GetReceiverValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetReceiverAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetInitialReceiverMapAddress() const {
  return address_ - i::kHeapObjectTag + 8;
}

Value<uintptr_t> TqSortState::GetInitialReceiverMapValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInitialReceiverMapAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetInitialReceiverLengthAddress() const {
  return address_ - i::kHeapObjectTag + 12;
}

Value<uintptr_t> TqSortState::GetInitialReceiverLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetInitialReceiverLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetUserCmpFnAddress() const {
  return address_ - i::kHeapObjectTag + 16;
}

Value<uintptr_t> TqSortState::GetUserCmpFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetUserCmpFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetSortComparePtrAddress() const {
  return address_ - i::kHeapObjectTag + 20;
}

Value<uintptr_t> TqSortState::GetSortComparePtrValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSortComparePtrAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetLoadFnAddress() const {
  return address_ - i::kHeapObjectTag + 24;
}

Value<uintptr_t> TqSortState::GetLoadFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetLoadFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetStoreFnAddress() const {
  return address_ - i::kHeapObjectTag + 28;
}

Value<uintptr_t> TqSortState::GetStoreFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetStoreFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetDeleteFnAddress() const {
  return address_ - i::kHeapObjectTag + 32;
}

Value<uintptr_t> TqSortState::GetDeleteFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetDeleteFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetCanUseSameAccessorFnAddress() const {
  return address_ - i::kHeapObjectTag + 36;
}

Value<uintptr_t> TqSortState::GetCanUseSameAccessorFnValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetCanUseSameAccessorFnAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetMinGallopAddress() const {
  return address_ - i::kHeapObjectTag + 40;
}

Value<uintptr_t> TqSortState::GetMinGallopValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetMinGallopAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetPendingRunsSizeAddress() const {
  return address_ - i::kHeapObjectTag + 44;
}

Value<uintptr_t> TqSortState::GetPendingRunsSizeValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPendingRunsSizeAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetPendingRunsAddress() const {
  return address_ - i::kHeapObjectTag + 48;
}

Value<uintptr_t> TqSortState::GetPendingRunsValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetPendingRunsAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetWorkArrayAddress() const {
  return address_ - i::kHeapObjectTag + 52;
}

Value<uintptr_t> TqSortState::GetWorkArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetWorkArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetTempArrayAddress() const {
  return address_ - i::kHeapObjectTag + 56;
}

Value<uintptr_t> TqSortState::GetTempArrayValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetTempArrayAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetSortLengthAddress() const {
  return address_ - i::kHeapObjectTag + 60;
}

Value<uintptr_t> TqSortState::GetSortLengthValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetSortLengthAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

uintptr_t TqSortState::GetNumberOfUndefinedAddress() const {
  return address_ - i::kHeapObjectTag + 64;
}

Value<uintptr_t> TqSortState::GetNumberOfUndefinedValue(d::MemoryAccessor accessor) const {
  i::Tagged_t value{};
  d::MemoryAccessResult validity = accessor(GetNumberOfUndefinedAddress(), reinterpret_cast<uint8_t*>(&value), sizeof(value));
  return {validity, EnsureDecompressed(value, address_)};
}

std::vector<std::unique_ptr<ObjectProperty>> TqSortState::GetProperties(d::MemoryAccessor accessor) const {
  std::vector<std::unique_ptr<ObjectProperty>> result = TqStruct::GetProperties(accessor);
  result.push_back(std::make_unique<ObjectProperty>("receiver", "v8::internal::TaggedValue", "v8::internal::JSReceiver", GetReceiverAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("initialReceiverMap", "v8::internal::TaggedValue", "v8::internal::Map", GetInitialReceiverMapAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("initialReceiverLength", "v8::internal::TaggedValue", "v8::internal::Object", GetInitialReceiverLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("userCmpFn", "v8::internal::TaggedValue", "v8::internal::HeapObject", GetUserCmpFnAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("sortComparePtr", "v8::internal::TaggedValue", "v8::internal::Object", GetSortComparePtrAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("loadFn", "v8::internal::TaggedValue", "v8::internal::Object", GetLoadFnAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("storeFn", "v8::internal::TaggedValue", "v8::internal::Object", GetStoreFnAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("deleteFn", "v8::internal::TaggedValue", "v8::internal::Object", GetDeleteFnAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("canUseSameAccessorFn", "v8::internal::TaggedValue", "v8::internal::Object", GetCanUseSameAccessorFnAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("minGallop", "v8::internal::TaggedValue", "v8::internal::Object", GetMinGallopAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("pendingRunsSize", "v8::internal::TaggedValue", "v8::internal::Object", GetPendingRunsSizeAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("pendingRuns", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetPendingRunsAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("workArray", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetWorkArrayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("tempArray", "v8::internal::TaggedValue", "v8::internal::FixedArray", GetTempArrayAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("sortLength", "v8::internal::TaggedValue", "v8::internal::Object", GetSortLengthAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  result.push_back(std::make_unique<ObjectProperty>("numberOfUndefined", "v8::internal::TaggedValue", "v8::internal::Object", GetNumberOfUndefinedAddress(), 1, 4, std::vector<std::unique_ptr<StructProperty>>(), d::PropertyKind::kSingle));
  return result;
}

const char* kObjectClassNames[] {
  "v8::internal::HeapObject",
  "v8::internal::Context",
  "v8::internal::JSReceiver",
  "v8::internal::PrimitiveHeapObject",
  "v8::internal::HeapNumber",
  "v8::internal::BigIntBase",
  "v8::internal::Name",
  "v8::internal::String",
  "v8::internal::Symbol",
  "v8::internal::Oddball",
  "v8::internal::FixedArrayBase",
  "v8::internal::FixedArray",
  "v8::internal::ByteArray",
  "v8::internal::WeakFixedArray",
  "v8::internal::Foreign",
  "v8::internal::JSObject",
  "v8::internal::JSProxy",
  "v8::internal::JSFunctionOrBoundFunction",
  "v8::internal::JSFunction",
  "v8::internal::JSBoundFunction",
  "v8::internal::JSCustomElementsObject",
  "v8::internal::JSSpecialObject",
  "v8::internal::Map",
  "v8::internal::MutableBigInt",
  "v8::internal::JSArrayBufferView",
  "v8::internal::JSTypedArray",
  "v8::internal::Struct",
  "v8::internal::DataHandler",
  "v8::internal::AllocationMemento",
  "v8::internal::CallHandlerInfo",
  "v8::internal::InterceptorInfo",
  "v8::internal::AccessCheckInfo",
  "v8::internal::AccessorInfo",
  "v8::internal::JSArgumentsObject",
  "v8::internal::JSSloppyArgumentsObject",
  "v8::internal::JSStrictArgumentsObject",
  "v8::internal::AliasedArgumentsEntry",
  "v8::internal::Cell",
  "v8::internal::SourcePositionTableWithFrameCache",
  "v8::internal::BytecodeArray",
  "v8::internal::Tuple2",
  "v8::internal::BreakPoint",
  "v8::internal::BreakPointInfo",
  "v8::internal::DebugInfo",
  "v8::internal::EnumCache",
  "v8::internal::AccessorPair",
  "v8::internal::ClassPositions",
  "v8::internal::DescriptorArray",
  "v8::internal::EmbedderDataArray",
  "v8::internal::FeedbackCell",
  "v8::internal::FeedbackVector",
  "v8::internal::FixedDoubleArray",
  "v8::internal::ArrayList",
  "v8::internal::TemplateList",
  "v8::internal::WeakArrayList",
  "v8::internal::FreeSpace",
  "v8::internal::JSDateTimeFormat",
  "v8::internal::JSDisplayNames",
  "v8::internal::JSListFormat",
  "v8::internal::JSNumberFormat",
  "v8::internal::JSPluralRules",
  "v8::internal::JSRelativeTimeFormat",
  "v8::internal::JSLocale",
  "v8::internal::JSSegmenter",
  "v8::internal::JSSegmentIterator",
  "v8::internal::JSV8BreakIterator",
  "v8::internal::JSCollator",
  "v8::internal::JSArrayBuffer",
  "v8::internal::JSDataView",
  "v8::internal::JSArrayIterator",
  "v8::internal::JSArray",
  "v8::internal::JSCollectionIterator",
  "v8::internal::JSCollection",
  "v8::internal::JSSet",
  "v8::internal::JSMap",
  "v8::internal::JSWeakCollection",
  "v8::internal::JSWeakSet",
  "v8::internal::JSWeakMap",
  "v8::internal::JSGeneratorObject",
  "v8::internal::JSAsyncFunctionObject",
  "v8::internal::JSAsyncGeneratorObject",
  "v8::internal::AsyncGeneratorRequest",
  "v8::internal::JSGlobalProxy",
  "v8::internal::JSGlobalObject",
  "v8::internal::JSPrimitiveWrapper",
  "v8::internal::JSMessageObject",
  "v8::internal::JSDate",
  "v8::internal::JSAsyncFromSyncIterator",
  "v8::internal::JSStringIterator",
  "v8::internal::JSPromise",
  "v8::internal::JSProxyRevocableResult",
  "v8::internal::JSRegExpStringIterator",
  "v8::internal::JSRegExp",
  "v8::internal::JSRegExpResult",
  "v8::internal::JSRegExpResultIndices",
  "v8::internal::JSFinalizationGroup",
  "v8::internal::JSFinalizationGroupCleanupIterator",
  "v8::internal::WeakCell",
  "v8::internal::JSWeakRef",
  "v8::internal::ArrayBoilerplateDescription",
  "v8::internal::Microtask",
  "v8::internal::CallbackTask",
  "v8::internal::CallableTask",
  "v8::internal::Module",
  "v8::internal::JSModuleNamespace",
  "v8::internal::PromiseCapability",
  "v8::internal::PromiseReaction",
  "v8::internal::PromiseReactionJobTask",
  "v8::internal::PromiseFulfillReactionJobTask",
  "v8::internal::PromiseRejectReactionJobTask",
  "v8::internal::PromiseResolveThenableJobTask",
  "v8::internal::PropertyArray",
  "v8::internal::PropertyCell",
  "v8::internal::PrototypeInfo",
  "v8::internal::RegExpMatchInfo",
  "v8::internal::Script",
  "v8::internal::PreparseData",
  "v8::internal::InterpreterData",
  "v8::internal::SharedFunctionInfo",
  "v8::internal::UncompiledData",
  "v8::internal::UncompiledDataWithoutPreparseData",
  "v8::internal::UncompiledDataWithPreparseData",
  "v8::internal::SourceTextModule",
  "v8::internal::SourceTextModuleInfoEntry",
  "v8::internal::StackFrameInfo",
  "v8::internal::StackTraceFrame",
  "v8::internal::ConsString",
  "v8::internal::ExternalString",
  "v8::internal::ExternalOneByteString",
  "v8::internal::ExternalTwoByteString",
  "v8::internal::InternalizedString",
  "v8::internal::SeqString",
  "v8::internal::SeqOneByteString",
  "v8::internal::SeqTwoByteString",
  "v8::internal::SlicedString",
  "v8::internal::ThinString",
  "v8::internal::Tuple3",
  "v8::internal::SyntheticModule",
  "v8::internal::TemplateObjectDescription",
  "v8::internal::TemplateInfo",
  "v8::internal::FunctionTemplateRareData",
  "v8::internal::FunctionTemplateInfo",
  "v8::internal::ObjectTemplateInfo",
  "v8::internal::WasmExportedFunctionData",
  "v8::internal::WasmJSFunctionData",
  "v8::internal::WasmCapiFunctionData",
  "v8::internal::WasmIndirectFunctionTable",
  "v8::internal::WasmDebugInfo",
  "v8::internal::WasmExceptionTag",
  "v8::internal::WasmModuleObject",
  "v8::internal::WasmTableObject",
  "v8::internal::WasmMemoryObject",
  "v8::internal::WasmGlobalObject",
  "v8::internal::WasmExceptionObject",
  "v8::internal::AsmWasmData",
  "v8::internal::InternalClass",
  "v8::internal::SmiPair",
  "v8::internal::SmiBox",
  "v8::internal::SortState",
};

const d::ClassList kObjectClassList {
  sizeof(kObjectClassNames) / sizeof(const char*),
  kObjectClassNames,
};
}  // namespace v8_debug_helper_internal
