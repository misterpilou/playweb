#ifndef V8_GEN_TORQUE_GENERATED_CLASS_DEFINITIONS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_CLASS_DEFINITIONS_TQ_H_

#include "src/objects/objects.h"
#include "src/objects/smi.h"
#include "torque-generated/field-offsets-tq.h"
#include <type_traits>


// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"
namespace v8 {
namespace internal {
using BuiltinPtr = Smi;

class Context;
class HeapObject;
class JSReceiver;
class HeapNumber;
class PrimitiveHeapObject;
class BigInt;
class String;
class Name;
class Symbol;
class Oddball;
class FixedArray;
class FixedArrayBase;
class FixedArray;
class OrderedHashMap;
class OrderedHashSet;
class OrderedNameDictionary;
class NameDictionary;
class GlobalDictionary;
class SimpleNumberDictionary;
class StringTable;
class EphemeronHashTable;
class NumberDictionary;
class Code;
class ObjectBoilerplateDescription;
class ClosureFeedbackCellArray;
class ScriptContextTable;
class ByteArray;
class TransitionArray;
class WeakFixedArray;
class ScopeInfo;
class Foreign;
class JSObject;
class JSProxy;
class JSFunction;
class JSFunctionOrBoundFunction;
class JSBoundFunction;
class HeapObject;
class JSObject;
class JSSpecialObject;
class JSSpecialObject;
class JSCustomElementsObject;
class JSObject;
class JSObject;
class Map;
class BigInt;
class JSTypedArray;
class JSArrayBufferView;
class LoadHandler;
class DataHandler;
class Struct;
class StoreHandler;
class AllocationSite;
class AllocationMemento;
class CallHandlerInfo;
class InterceptorInfo;
class AccessCheckInfo;
class AccessorInfo;
class JSArgumentsObject;
class JSArgumentsObject;
class JSArgumentsObject;
class AliasedArgumentsEntry;
class Cell;
class SourcePositionTableWithFrameCache;
class BytecodeArray;
class CodeDataContainer;
class Context;
class Context;
class Context;
class Context;
class Context;
class Context;
class Context;
class NativeContext;
class Context;
class Context;
class BreakPoint;
class Tuple2;
class BreakPointInfo;
class DebugInfo;
class EnumCache;
class AccessorPair;
class ClassPositions;
class DescriptorArray;
class EmbedderDataArray;
class FeedbackCell;
class FeedbackVector;
class FeedbackMetadata;
class FixedDoubleArray;
class ArrayList;
class TemplateList;
class WeakArrayList;
class FreeSpace;
class JSDateTimeFormat;
class JSDisplayNames;
class JSListFormat;
class JSNumberFormat;
class JSPluralRules;
class JSRelativeTimeFormat;
class JSLocale;
class JSSegmenter;
class JSSegmentIterator;
class JSV8BreakIterator;
class JSCollator;
class JSArrayBuffer;
class JSDataView;
class JSArrayIterator;
class JSArray;
class JSCollectionIterator;
class JSCollection;
class JSSet;
class JSMap;
class JSWeakCollection;
class JSWeakSet;
class JSWeakMap;
class JSMapIterator;
class JSMapIterator;
class JSMapIterator;
class JSMapIterator;
class JSSetIterator;
class JSSetIterator;
class JSSetIterator;
class JSGeneratorObject;
class JSAsyncFunctionObject;
class JSAsyncGeneratorObject;
class AsyncGeneratorRequest;
class JSGlobalProxy;
class JSGlobalObject;
class JSPrimitiveWrapper;
class JSMessageObject;
class JSDate;
class JSAsyncFromSyncIterator;
class JSStringIterator;
class JSPromise;
class JSObject;
class JSRegExpStringIterator;
class JSRegExp;
class JSArray;
class JSArray;
class JSFinalizationGroup;
class JSFinalizationGroupCleanupIterator;
class WeakCell;
class JSWeakRef;
class ArrayBoilerplateDescription;
class Microtask;
class CallbackTask;
class CallableTask;
class Module;
class JSModuleNamespace;
class HeapObject;
class SmallOrderedHashMap;
class SmallOrderedHashSet;
class SmallOrderedNameDictionary;
class PromiseCapability;
class PromiseReaction;
class PromiseReactionJobTask;
class PromiseFulfillReactionJobTask;
class PromiseRejectReactionJobTask;
class PromiseResolveThenableJobTask;
class PropertyArray;
class PropertyCell;
class PrototypeInfo;
class RegExpMatchInfo;
class Script;
class PreparseData;
class InterpreterData;
class SharedFunctionInfo;
class UncompiledData;
class UncompiledDataWithoutPreparseData;
class UncompiledDataWithPreparseData;
class SourceTextModule;
class SourceTextModuleInfoEntry;
class StackFrameInfo;
class StackTraceFrame;
class ConsString;
class ExternalString;
class ExternalOneByteString;
class ExternalTwoByteString;
class InternalizedString;
class SeqString;
class SeqOneByteString;
class SeqTwoByteString;
class SlicedString;
class ThinString;
class Tuple3;
class SyntheticModule;
class TemplateObjectDescription;
class TemplateInfo;
class FunctionTemplateRareData;
class FunctionTemplateInfo;
class ObjectTemplateInfo;
class WasmInstanceObject;
class WasmExportedFunctionData;
class WasmJSFunctionData;
class WasmCapiFunctionData;
class WasmIndirectFunctionTable;
class WasmDebugInfo;
class WasmExceptionTag;
class WasmModuleObject;
class WasmTableObject;
class WasmMemoryObject;
class WasmGlobalObject;
class WasmExceptionObject;
class AsmWasmData;
class InternalClass;
class SmiPair;
class SmiBox;
class SortState;
template <class D, class P>
class TorqueGeneratedPrimitiveHeapObject : public P {
  static_assert(std::is_same<PrimitiveHeapObject, D>::value,
    "Use this class as direct base for PrimitiveHeapObject.");
  static_assert(std::is_same<HeapObject, P>::value,
    "Pass in HeapObject as second template parameter for TorqueGeneratedPrimitiveHeapObject.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void PrimitiveHeapObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedPrimitiveHeapObject() : P() {
    static_assert(std::is_base_of<TorqueGeneratedPrimitiveHeapObject, 
      DAlias>::value,
      "class TorqueGeneratedPrimitiveHeapObject should be used as direct base for PrimitiveHeapObject.");
  }
protected:
  inline explicit TorqueGeneratedPrimitiveHeapObject(Address ptr);
};

template <class D, class P>
class TorqueGeneratedString : public P {
  static_assert(std::is_same<String, D>::value,
    "Use this class as direct base for String.");
  static_assert(std::is_same<Name, P>::value,
    "Pass in Name as second template parameter for TorqueGeneratedString.");
 public: 
  using Super = P;
  inline int32_t length() const;
  inline void set_length(int32_t value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void StringVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kLengthOffset = P::kHeaderSize;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedString() : P() {
    static_assert(std::is_base_of<TorqueGeneratedString, 
      DAlias>::value,
      "class TorqueGeneratedString should be used as direct base for String.");
  }
protected:
  inline explicit TorqueGeneratedString(Address ptr);
};

template <class D, class P>
class TorqueGeneratedName : public P {
  static_assert(std::is_same<Name, D>::value,
    "Use this class as direct base for Name.");
  static_assert(std::is_same<PrimitiveHeapObject, P>::value,
    "Pass in PrimitiveHeapObject as second template parameter for TorqueGeneratedName.");
 public: 
  using Super = P;
  inline uint32_t hash_field() const;
  inline void set_hash_field(uint32_t value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void NameVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kHashFieldOffset = P::kHeaderSize;
  static constexpr int kHashFieldOffsetEnd = kHashFieldOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kHashFieldOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kHashFieldOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kHashFieldOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kHashFieldOffsetEnd + 1;
  static constexpr int kHeaderSize = kHashFieldOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedName() : P() {
    static_assert(std::is_base_of<TorqueGeneratedName, 
      DAlias>::value,
      "class TorqueGeneratedName should be used as direct base for Name.");
  }
protected:
  inline explicit TorqueGeneratedName(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSymbol : public P {
  static_assert(std::is_same<Symbol, D>::value,
    "Use this class as direct base for Symbol.");
  static_assert(std::is_same<Name, P>::value,
    "Pass in Name as second template parameter for TorqueGeneratedSymbol.");
 public: 
  using Super = P;
  inline int32_t flags() const;
  inline void set_flags(int32_t value);

  inline PrimitiveHeapObject description() const;
  inline PrimitiveHeapObject description(const Isolate* isolate) const;
  inline void set_description(PrimitiveHeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SymbolVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kFlagsOffset = P::kHeaderSize;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kInt32Size - 1;
  static constexpr int kStartOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kDescriptionOffset = kFlagsOffsetEnd + 1;
  static constexpr int kDescriptionOffsetEnd = kDescriptionOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDescriptionOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDescriptionOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDescriptionOffsetEnd + 1;
  static constexpr int kHeaderSize = kDescriptionOffsetEnd + 1;
  static constexpr int kSize = kDescriptionOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSymbol() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSymbol, 
      DAlias>::value,
      "class TorqueGeneratedSymbol should be used as direct base for Symbol.");
  }
protected:
  inline explicit TorqueGeneratedSymbol(Address ptr);
};

template <class D, class P>
class TorqueGeneratedOddball : public P {
  static_assert(std::is_same<Oddball, D>::value,
    "Use this class as direct base for Oddball.");
  static_assert(std::is_same<PrimitiveHeapObject, P>::value,
    "Pass in PrimitiveHeapObject as second template parameter for TorqueGeneratedOddball.");
 public: 
  using Super = P;
  inline double to_number_raw() const;
  inline void set_to_number_raw(double value);

  inline String to_string() const;
  inline String to_string(const Isolate* isolate) const;
  inline void set_to_string(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Number
  inline Object to_number() const;
  inline Object to_number(const Isolate* isolate) const;
  inline void set_to_number(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline String type_of() const;
  inline String type_of(const Isolate* isolate) const;
  inline void set_type_of(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi kind() const;
  inline void set_kind(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void OddballVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kToNumberRawOffset = P::kHeaderSize;
  static constexpr int kToNumberRawOffsetEnd = kToNumberRawOffset + kDoubleSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kToNumberRawOffsetEnd + 1;
  static constexpr int kToStringOffset = kToNumberRawOffsetEnd + 1;
  static constexpr int kToStringOffsetEnd = kToStringOffset + kTaggedSize - 1;
  static constexpr int kToNumberOffset = kToStringOffsetEnd + 1;
  static constexpr int kToNumberOffsetEnd = kToNumberOffset + kTaggedSize - 1;
  static constexpr int kTypeOfOffset = kToNumberOffsetEnd + 1;
  static constexpr int kTypeOfOffsetEnd = kTypeOfOffset + kTaggedSize - 1;
  static constexpr int kKindOffset = kTypeOfOffsetEnd + 1;
  static constexpr int kKindOffsetEnd = kKindOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kKindOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kKindOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kKindOffsetEnd + 1;
  static constexpr int kHeaderSize = kKindOffsetEnd + 1;
  static constexpr int kSize = kKindOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedOddball() : P() {
    static_assert(std::is_base_of<TorqueGeneratedOddball, 
      DAlias>::value,
      "class TorqueGeneratedOddball should be used as direct base for Oddball.");
  }
protected:
  inline explicit TorqueGeneratedOddball(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSObject : public P {
  static_assert(std::is_same<JSObject, D>::value,
    "Use this class as direct base for JSObject.");
  static_assert(std::is_same<JSReceiver, P>::value,
    "Pass in JSReceiver as second template parameter for TorqueGeneratedJSObject.");
 public: 
  using Super = P;
  inline FixedArrayBase elements() const;
  inline FixedArrayBase elements(const Isolate* isolate) const;
  inline void set_elements(FixedArrayBase value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kElementsOffset = P::kHeaderSize;
  static constexpr int kElementsOffsetEnd = kElementsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kElementsOffsetEnd + 1;
  static constexpr int kHeaderSize = kElementsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSObject() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSObject, 
      DAlias>::value,
      "class TorqueGeneratedJSObject should be used as direct base for JSObject.");
  }
protected:
  inline explicit TorqueGeneratedJSObject(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSProxy : public P {
  static_assert(std::is_same<JSProxy, D>::value,
    "Use this class as direct base for JSProxy.");
  static_assert(std::is_same<JSReceiver, P>::value,
    "Pass in JSReceiver as second template parameter for TorqueGeneratedJSProxy.");
 public: 
  using Super = P;
  inline HeapObject target() const;
  inline HeapObject target(const Isolate* isolate) const;
  inline void set_target(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject handler() const;
  inline HeapObject handler(const Isolate* isolate) const;
  inline void set_handler(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSProxyVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kTargetOffset = P::kHeaderSize;
  static constexpr int kTargetOffsetEnd = kTargetOffset + kTaggedSize - 1;
  static constexpr int kHandlerOffset = kTargetOffsetEnd + 1;
  static constexpr int kHandlerOffsetEnd = kHandlerOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kHandlerOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kHandlerOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kHandlerOffsetEnd + 1;
  static constexpr int kHeaderSize = kHandlerOffsetEnd + 1;
  static constexpr int kSize = kHandlerOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSProxy() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSProxy, 
      DAlias>::value,
      "class TorqueGeneratedJSProxy should be used as direct base for JSProxy.");
  }
protected:
  inline explicit TorqueGeneratedJSProxy(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSFunctionOrBoundFunction : public P {
  static_assert(std::is_same<JSFunctionOrBoundFunction, D>::value,
    "Use this class as direct base for JSFunctionOrBoundFunction.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSFunctionOrBoundFunction.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSFunctionOrBoundFunctionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSFunctionOrBoundFunction() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSFunctionOrBoundFunction, 
      DAlias>::value,
      "class TorqueGeneratedJSFunctionOrBoundFunction should be used as direct base for JSFunctionOrBoundFunction.");
  }
protected:
  inline explicit TorqueGeneratedJSFunctionOrBoundFunction(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSBoundFunction : public P {
  static_assert(std::is_same<JSBoundFunction, D>::value,
    "Use this class as direct base for JSBoundFunction.");
  static_assert(std::is_same<JSFunctionOrBoundFunction, P>::value,
    "Pass in JSFunctionOrBoundFunction as second template parameter for TorqueGeneratedJSBoundFunction.");
 public: 
  using Super = P;
  inline JSReceiver bound_target_function() const;
  inline JSReceiver bound_target_function(const Isolate* isolate) const;
  inline void set_bound_target_function(JSReceiver value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class JSReceiver | Smi | class HeapNumber | BigInt | class String | class Symbol | True | False | Null | Undefined | class SourceTextModule)
  inline Object bound_this() const;
  inline Object bound_this(const Isolate* isolate) const;
  inline void set_bound_this(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray bound_arguments() const;
  inline FixedArray bound_arguments(const Isolate* isolate) const;
  inline void set_bound_arguments(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSBoundFunctionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kBoundTargetFunctionOffset = P::kHeaderSize;
  static constexpr int kBoundTargetFunctionOffsetEnd = kBoundTargetFunctionOffset + kTaggedSize - 1;
  static constexpr int kBoundThisOffset = kBoundTargetFunctionOffsetEnd + 1;
  static constexpr int kBoundThisOffsetEnd = kBoundThisOffset + kTaggedSize - 1;
  static constexpr int kBoundArgumentsOffset = kBoundThisOffsetEnd + 1;
  static constexpr int kBoundArgumentsOffsetEnd = kBoundArgumentsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBoundArgumentsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBoundArgumentsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBoundArgumentsOffsetEnd + 1;
  static constexpr int kHeaderSize = kBoundArgumentsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSBoundFunction() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSBoundFunction, 
      DAlias>::value,
      "class TorqueGeneratedJSBoundFunction should be used as direct base for JSBoundFunction.");
  }
protected:
  inline explicit TorqueGeneratedJSBoundFunction(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSSpecialObject : public P {
  static_assert(std::is_same<JSSpecialObject, D>::value,
    "Use this class as direct base for JSSpecialObject.");
  static_assert(std::is_same<JSCustomElementsObject, P>::value,
    "Pass in JSCustomElementsObject as second template parameter for TorqueGeneratedJSSpecialObject.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSSpecialObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSSpecialObject() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSSpecialObject, 
      DAlias>::value,
      "class TorqueGeneratedJSSpecialObject should be used as direct base for JSSpecialObject.");
  }
protected:
  inline explicit TorqueGeneratedJSSpecialObject(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSCustomElementsObject : public P {
  static_assert(std::is_same<JSCustomElementsObject, D>::value,
    "Use this class as direct base for JSCustomElementsObject.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSCustomElementsObject.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSCustomElementsObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSCustomElementsObject() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSCustomElementsObject, 
      DAlias>::value,
      "class TorqueGeneratedJSCustomElementsObject should be used as direct base for JSCustomElementsObject.");
  }
protected:
  inline explicit TorqueGeneratedJSCustomElementsObject(Address ptr);
};

template <class D, class P>
class TorqueGeneratedStruct : public P {
  static_assert(std::is_same<Struct, D>::value,
    "Use this class as direct base for Struct.");
  static_assert(std::is_same<HeapObject, P>::value,
    "Pass in HeapObject as second template parameter for TorqueGeneratedStruct.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(Struct)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void StructVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedStruct() : P() {
    static_assert(std::is_base_of<TorqueGeneratedStruct, 
      DAlias>::value,
      "class TorqueGeneratedStruct should be used as direct base for Struct.");
  }
protected:
  inline explicit TorqueGeneratedStruct(Address ptr);
};

template <class D, class P>
class TorqueGeneratedCallHandlerInfo : public P {
  static_assert(std::is_same<CallHandlerInfo, D>::value,
    "Use this class as direct base for CallHandlerInfo.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedCallHandlerInfo.");
 public: 
  using Super = P;
  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object callback() const;
  inline Object callback(const Isolate* isolate) const;
  inline void set_callback(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object js_callback() const;
  inline Object js_callback(const Isolate* isolate) const;
  inline void set_js_callback(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object data() const;
  inline Object data(const Isolate* isolate) const;
  inline void set_data(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void CallHandlerInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kCallbackOffset = P::kHeaderSize;
  static constexpr int kCallbackOffsetEnd = kCallbackOffset + kTaggedSize - 1;
  static constexpr int kJsCallbackOffset = kCallbackOffsetEnd + 1;
  static constexpr int kJsCallbackOffsetEnd = kJsCallbackOffset + kTaggedSize - 1;
  static constexpr int kDataOffset = kJsCallbackOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kDataOffsetEnd + 1;
  static constexpr int kSize = kDataOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedCallHandlerInfo() : P() {
    static_assert(std::is_base_of<TorqueGeneratedCallHandlerInfo, 
      DAlias>::value,
      "class TorqueGeneratedCallHandlerInfo should be used as direct base for CallHandlerInfo.");
  }
protected:
  inline explicit TorqueGeneratedCallHandlerInfo(Address ptr);
};

template <class D, class P>
class TorqueGeneratedInterceptorInfo : public P {
  static_assert(std::is_same<InterceptorInfo, D>::value,
    "Use this class as direct base for InterceptorInfo.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedInterceptorInfo.");
 public: 
  using Super = P;
  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object getter() const;
  inline Object getter(const Isolate* isolate) const;
  inline void set_getter(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object setter() const;
  inline Object setter(const Isolate* isolate) const;
  inline void set_setter(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object query() const;
  inline Object query(const Isolate* isolate) const;
  inline void set_query(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object descriptor() const;
  inline Object descriptor(const Isolate* isolate) const;
  inline void set_descriptor(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object deleter() const;
  inline Object deleter(const Isolate* isolate) const;
  inline void set_deleter(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object enumerator() const;
  inline Object enumerator(const Isolate* isolate) const;
  inline void set_enumerator(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | NonNullForeign)
  inline Object definer() const;
  inline Object definer(const Isolate* isolate) const;
  inline void set_definer(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object data() const;
  inline Object data(const Isolate* isolate) const;
  inline void set_data(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi flags() const;
  inline void set_flags(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void InterceptorInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kGetterOffset = P::kHeaderSize;
  static constexpr int kGetterOffsetEnd = kGetterOffset + kTaggedSize - 1;
  static constexpr int kSetterOffset = kGetterOffsetEnd + 1;
  static constexpr int kSetterOffsetEnd = kSetterOffset + kTaggedSize - 1;
  static constexpr int kQueryOffset = kSetterOffsetEnd + 1;
  static constexpr int kQueryOffsetEnd = kQueryOffset + kTaggedSize - 1;
  static constexpr int kDescriptorOffset = kQueryOffsetEnd + 1;
  static constexpr int kDescriptorOffsetEnd = kDescriptorOffset + kTaggedSize - 1;
  static constexpr int kDeleterOffset = kDescriptorOffsetEnd + 1;
  static constexpr int kDeleterOffsetEnd = kDeleterOffset + kTaggedSize - 1;
  static constexpr int kEnumeratorOffset = kDeleterOffsetEnd + 1;
  static constexpr int kEnumeratorOffsetEnd = kEnumeratorOffset + kTaggedSize - 1;
  static constexpr int kDefinerOffset = kEnumeratorOffsetEnd + 1;
  static constexpr int kDefinerOffsetEnd = kDefinerOffset + kTaggedSize - 1;
  static constexpr int kDataOffset = kDefinerOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kFlagsOffset = kDataOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;
  static constexpr int kSize = kFlagsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedInterceptorInfo() : P() {
    static_assert(std::is_base_of<TorqueGeneratedInterceptorInfo, 
      DAlias>::value,
      "class TorqueGeneratedInterceptorInfo should be used as direct base for InterceptorInfo.");
  }
protected:
  inline explicit TorqueGeneratedInterceptorInfo(Address ptr);
};

template <class D, class P>
class TorqueGeneratedAccessCheckInfo : public P {
  static_assert(std::is_same<AccessCheckInfo, D>::value,
    "Use this class as direct base for AccessCheckInfo.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedAccessCheckInfo.");
 public: 
  using Super = P;
  // Torque type: (Undefined | Zero | class Foreign)
  inline Object callback() const;
  inline Object callback(const Isolate* isolate) const;
  inline void set_callback(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | class InterceptorInfo)
  inline Object named_interceptor() const;
  inline Object named_interceptor(const Isolate* isolate) const;
  inline void set_named_interceptor(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Undefined | Zero | class InterceptorInfo)
  inline Object indexed_interceptor() const;
  inline Object indexed_interceptor(const Isolate* isolate) const;
  inline void set_indexed_interceptor(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object data() const;
  inline Object data(const Isolate* isolate) const;
  inline void set_data(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void AccessCheckInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kCallbackOffset = P::kHeaderSize;
  static constexpr int kCallbackOffsetEnd = kCallbackOffset + kTaggedSize - 1;
  static constexpr int kNamedInterceptorOffset = kCallbackOffsetEnd + 1;
  static constexpr int kNamedInterceptorOffsetEnd = kNamedInterceptorOffset + kTaggedSize - 1;
  static constexpr int kIndexedInterceptorOffset = kNamedInterceptorOffsetEnd + 1;
  static constexpr int kIndexedInterceptorOffsetEnd = kIndexedInterceptorOffset + kTaggedSize - 1;
  static constexpr int kDataOffset = kIndexedInterceptorOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kDataOffsetEnd + 1;
  static constexpr int kSize = kDataOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedAccessCheckInfo() : P() {
    static_assert(std::is_base_of<TorqueGeneratedAccessCheckInfo, 
      DAlias>::value,
      "class TorqueGeneratedAccessCheckInfo should be used as direct base for AccessCheckInfo.");
  }
protected:
  inline explicit TorqueGeneratedAccessCheckInfo(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSArgumentsObject : public P {
  static_assert(std::is_same<JSArgumentsObject, D>::value,
    "Use this class as direct base for JSArgumentsObject.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSArgumentsObject.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSArgumentsObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSArgumentsObject() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSArgumentsObject, 
      DAlias>::value,
      "class TorqueGeneratedJSArgumentsObject should be used as direct base for JSArgumentsObject.");
  }
protected:
  inline explicit TorqueGeneratedJSArgumentsObject(Address ptr);
};

template <class D, class P>
class TorqueGeneratedAliasedArgumentsEntry : public P {
  static_assert(std::is_same<AliasedArgumentsEntry, D>::value,
    "Use this class as direct base for AliasedArgumentsEntry.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedAliasedArgumentsEntry.");
 public: 
  using Super = P;
  inline Smi aliased_context_slot() const;
  inline void set_aliased_context_slot(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void AliasedArgumentsEntryVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kAliasedContextSlotOffset = P::kHeaderSize;
  static constexpr int kAliasedContextSlotOffsetEnd = kAliasedContextSlotOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kAliasedContextSlotOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kAliasedContextSlotOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kAliasedContextSlotOffsetEnd + 1;
  static constexpr int kHeaderSize = kAliasedContextSlotOffsetEnd + 1;
  static constexpr int kSize = kAliasedContextSlotOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedAliasedArgumentsEntry() : P() {
    static_assert(std::is_base_of<TorqueGeneratedAliasedArgumentsEntry, 
      DAlias>::value,
      "class TorqueGeneratedAliasedArgumentsEntry should be used as direct base for AliasedArgumentsEntry.");
  }
protected:
  inline explicit TorqueGeneratedAliasedArgumentsEntry(Address ptr);
};

template <class D, class P>
class TorqueGeneratedCell : public P {
  static_assert(std::is_same<Cell, D>::value,
    "Use this class as direct base for Cell.");
  static_assert(std::is_same<HeapObject, P>::value,
    "Pass in HeapObject as second template parameter for TorqueGeneratedCell.");
 public: 
  using Super = P;
  inline Object value() const;
  inline Object value(const Isolate* isolate) const;
  inline void set_value(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void CellVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kHeaderSize = kValueOffsetEnd + 1;
  static constexpr int kSize = kValueOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedCell() : P() {
    static_assert(std::is_base_of<TorqueGeneratedCell, 
      DAlias>::value,
      "class TorqueGeneratedCell should be used as direct base for Cell.");
  }
protected:
  inline explicit TorqueGeneratedCell(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSourcePositionTableWithFrameCache : public P {
  static_assert(std::is_same<SourcePositionTableWithFrameCache, D>::value,
    "Use this class as direct base for SourcePositionTableWithFrameCache.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedSourcePositionTableWithFrameCache.");
 public: 
  using Super = P;
  inline ByteArray source_position_table() const;
  inline ByteArray source_position_table(const Isolate* isolate) const;
  inline void set_source_position_table(ByteArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object stack_frame_cache() const;
  inline Object stack_frame_cache(const Isolate* isolate) const;
  inline void set_stack_frame_cache(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(SourcePositionTableWithFrameCache)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SourcePositionTableWithFrameCacheVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kSourcePositionTableOffset = P::kHeaderSize;
  static constexpr int kSourcePositionTableOffsetEnd = kSourcePositionTableOffset + kTaggedSize - 1;
  static constexpr int kStackFrameCacheOffset = kSourcePositionTableOffsetEnd + 1;
  static constexpr int kStackFrameCacheOffsetEnd = kStackFrameCacheOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kStackFrameCacheOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kStackFrameCacheOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kStackFrameCacheOffsetEnd + 1;
  static constexpr int kHeaderSize = kStackFrameCacheOffsetEnd + 1;
  static constexpr int kSize = kStackFrameCacheOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSourcePositionTableWithFrameCache() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSourcePositionTableWithFrameCache, 
      DAlias>::value,
      "class TorqueGeneratedSourcePositionTableWithFrameCache should be used as direct base for SourcePositionTableWithFrameCache.");
  }
protected:
  inline explicit TorqueGeneratedSourcePositionTableWithFrameCache(Address ptr);
};

template <class D, class P>
class TorqueGeneratedTuple2 : public P {
  static_assert(std::is_same<Tuple2, D>::value,
    "Use this class as direct base for Tuple2.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedTuple2.");
 public: 
  using Super = P;
  inline Object value1() const;
  inline Object value1(const Isolate* isolate) const;
  inline void set_value1(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object value2() const;
  inline Object value2(const Isolate* isolate) const;
  inline void set_value2(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(Tuple2)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void Tuple2Verify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kValue1Offset = P::kHeaderSize;
  static constexpr int kValue1OffsetEnd = kValue1Offset + kTaggedSize - 1;
  static constexpr int kValue2Offset = kValue1OffsetEnd + 1;
  static constexpr int kValue2OffsetEnd = kValue2Offset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kValue2OffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kValue2OffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValue2OffsetEnd + 1;
  static constexpr int kHeaderSize = kValue2OffsetEnd + 1;
  static constexpr int kSize = kValue2OffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedTuple2() : P() {
    static_assert(std::is_base_of<TorqueGeneratedTuple2, 
      DAlias>::value,
      "class TorqueGeneratedTuple2 should be used as direct base for Tuple2.");
  }
protected:
  inline explicit TorqueGeneratedTuple2(Address ptr);
};

template <class D, class P>
class TorqueGeneratedDebugInfo : public P {
  static_assert(std::is_same<DebugInfo, D>::value,
    "Use this class as direct base for DebugInfo.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedDebugInfo.");
 public: 
  using Super = P;
  inline SharedFunctionInfo shared() const;
  inline SharedFunctionInfo shared(const Isolate* isolate) const;
  inline void set_shared(SharedFunctionInfo value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi debugger_hints() const;
  inline void set_debugger_hints(Smi value);

  inline HeapObject script() const;
  inline HeapObject script(const Isolate* isolate) const;
  inline void set_script(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject original_bytecode_array() const;
  inline HeapObject original_bytecode_array(const Isolate* isolate) const;
  inline void set_original_bytecode_array(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject debug_bytecode_array() const;
  inline HeapObject debug_bytecode_array(const Isolate* isolate) const;
  inline void set_debug_bytecode_array(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray break_points() const;
  inline FixedArray break_points(const Isolate* isolate) const;
  inline void set_break_points(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi flags() const;
  inline void set_flags(Smi value);

  inline HeapObject coverage_info() const;
  inline HeapObject coverage_info(const Isolate* isolate) const;
  inline void set_coverage_info(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void DebugInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kSharedOffset = P::kHeaderSize;
  static constexpr int kSharedOffsetEnd = kSharedOffset + kTaggedSize - 1;
  static constexpr int kDebuggerHintsOffset = kSharedOffsetEnd + 1;
  static constexpr int kDebuggerHintsOffsetEnd = kDebuggerHintsOffset + kTaggedSize - 1;
  static constexpr int kScriptOffset = kDebuggerHintsOffsetEnd + 1;
  static constexpr int kScriptOffsetEnd = kScriptOffset + kTaggedSize - 1;
  static constexpr int kOriginalBytecodeArrayOffset = kScriptOffsetEnd + 1;
  static constexpr int kOriginalBytecodeArrayOffsetEnd = kOriginalBytecodeArrayOffset + kTaggedSize - 1;
  static constexpr int kDebugBytecodeArrayOffset = kOriginalBytecodeArrayOffsetEnd + 1;
  static constexpr int kDebugBytecodeArrayOffsetEnd = kDebugBytecodeArrayOffset + kTaggedSize - 1;
  static constexpr int kBreakPointsOffset = kDebugBytecodeArrayOffsetEnd + 1;
  static constexpr int kBreakPointsOffsetEnd = kBreakPointsOffset + kTaggedSize - 1;
  static constexpr int kFlagsOffset = kBreakPointsOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kCoverageInfoOffset = kFlagsOffsetEnd + 1;
  static constexpr int kCoverageInfoOffsetEnd = kCoverageInfoOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCoverageInfoOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCoverageInfoOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCoverageInfoOffsetEnd + 1;
  static constexpr int kHeaderSize = kCoverageInfoOffsetEnd + 1;
  static constexpr int kSize = kCoverageInfoOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedDebugInfo() : P() {
    static_assert(std::is_base_of<TorqueGeneratedDebugInfo, 
      DAlias>::value,
      "class TorqueGeneratedDebugInfo should be used as direct base for DebugInfo.");
  }
protected:
  inline explicit TorqueGeneratedDebugInfo(Address ptr);
};

template <class D, class P>
class TorqueGeneratedEnumCache : public P {
  static_assert(std::is_same<EnumCache, D>::value,
    "Use this class as direct base for EnumCache.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedEnumCache.");
 public: 
  using Super = P;
  inline FixedArray keys() const;
  inline FixedArray keys(const Isolate* isolate) const;
  inline void set_keys(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray indices() const;
  inline FixedArray indices(const Isolate* isolate) const;
  inline void set_indices(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(EnumCache)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void EnumCacheVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kKeysOffset = P::kHeaderSize;
  static constexpr int kKeysOffsetEnd = kKeysOffset + kTaggedSize - 1;
  static constexpr int kIndicesOffset = kKeysOffsetEnd + 1;
  static constexpr int kIndicesOffsetEnd = kIndicesOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIndicesOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIndicesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIndicesOffsetEnd + 1;
  static constexpr int kHeaderSize = kIndicesOffsetEnd + 1;
  static constexpr int kSize = kIndicesOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedEnumCache() : P() {
    static_assert(std::is_base_of<TorqueGeneratedEnumCache, 
      DAlias>::value,
      "class TorqueGeneratedEnumCache should be used as direct base for EnumCache.");
  }
protected:
  inline explicit TorqueGeneratedEnumCache(Address ptr);
};

template <class D, class P>
class TorqueGeneratedAccessorPair : public P {
  static_assert(std::is_same<AccessorPair, D>::value,
    "Use this class as direct base for AccessorPair.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedAccessorPair.");
 public: 
  using Super = P;
  inline Object getter() const;
  inline Object getter(const Isolate* isolate) const;
  inline void set_getter(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object setter() const;
  inline Object setter(const Isolate* isolate) const;
  inline void set_setter(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void AccessorPairVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kGetterOffset = P::kHeaderSize;
  static constexpr int kGetterOffsetEnd = kGetterOffset + kTaggedSize - 1;
  static constexpr int kSetterOffset = kGetterOffsetEnd + 1;
  static constexpr int kSetterOffsetEnd = kSetterOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSetterOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSetterOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSetterOffsetEnd + 1;
  static constexpr int kHeaderSize = kSetterOffsetEnd + 1;
  static constexpr int kSize = kSetterOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedAccessorPair() : P() {
    static_assert(std::is_base_of<TorqueGeneratedAccessorPair, 
      DAlias>::value,
      "class TorqueGeneratedAccessorPair should be used as direct base for AccessorPair.");
  }
protected:
  inline explicit TorqueGeneratedAccessorPair(Address ptr);
};

template <class D, class P>
class TorqueGeneratedClassPositions : public P {
  static_assert(std::is_same<ClassPositions, D>::value,
    "Use this class as direct base for ClassPositions.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedClassPositions.");
 public: 
  using Super = P;
  inline Smi start() const;
  inline void set_start(Smi value);

  inline Smi end() const;
  inline void set_end(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void ClassPositionsVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOffset = P::kHeaderSize;
  static constexpr int kStartOffsetEnd = kStartOffset + kTaggedSize - 1;
  static constexpr int kEndOffset = kStartOffsetEnd + 1;
  static constexpr int kEndOffsetEnd = kEndOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kEndOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kEndOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kEndOffsetEnd + 1;
  static constexpr int kHeaderSize = kEndOffsetEnd + 1;
  static constexpr int kSize = kEndOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedClassPositions() : P() {
    static_assert(std::is_base_of<TorqueGeneratedClassPositions, 
      DAlias>::value,
      "class TorqueGeneratedClassPositions should be used as direct base for ClassPositions.");
  }
protected:
  inline explicit TorqueGeneratedClassPositions(Address ptr);
};

template <class D, class P>
class TorqueGeneratedEmbedderDataArray : public P {
  static_assert(std::is_same<EmbedderDataArray, D>::value,
    "Use this class as direct base for EmbedderDataArray.");
  static_assert(std::is_same<HeapObject, P>::value,
    "Pass in HeapObject as second template parameter for TorqueGeneratedEmbedderDataArray.");
 public: 
  using Super = P;
  inline Smi length() const;
  inline void set_length(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void EmbedderDataArrayVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kLengthOffset = P::kHeaderSize;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;
  static constexpr int kSize = kLengthOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedEmbedderDataArray() : P() {
    static_assert(std::is_base_of<TorqueGeneratedEmbedderDataArray, 
      DAlias>::value,
      "class TorqueGeneratedEmbedderDataArray should be used as direct base for EmbedderDataArray.");
  }
protected:
  inline explicit TorqueGeneratedEmbedderDataArray(Address ptr);
};

template <class D, class P>
class TorqueGeneratedFeedbackCell : public P {
  static_assert(std::is_same<FeedbackCell, D>::value,
    "Use this class as direct base for FeedbackCell.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedFeedbackCell.");
 public: 
  using Super = P;
  inline HeapObject value() const;
  inline HeapObject value(const Isolate* isolate) const;
  inline void set_value(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline int32_t interrupt_budget() const;
  inline void set_interrupt_budget(int32_t value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void FeedbackCellVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kInterruptBudgetOffset = kValueOffsetEnd + 1;
  static constexpr int kInterruptBudgetOffsetEnd = kInterruptBudgetOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kInterruptBudgetOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kInterruptBudgetOffsetEnd + 1;
  static constexpr int kHeaderSize = kInterruptBudgetOffsetEnd + 1;
  static constexpr int kSize = kInterruptBudgetOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedFeedbackCell() : P() {
    static_assert(std::is_base_of<TorqueGeneratedFeedbackCell, 
      DAlias>::value,
      "class TorqueGeneratedFeedbackCell should be used as direct base for FeedbackCell.");
  }
protected:
  inline explicit TorqueGeneratedFeedbackCell(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSCollectionIterator : public P {
  static_assert(std::is_same<JSCollectionIterator, D>::value,
    "Use this class as direct base for JSCollectionIterator.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSCollectionIterator.");
 public: 
  using Super = P;
  inline Object table() const;
  inline Object table(const Isolate* isolate) const;
  inline void set_table(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object index() const;
  inline Object index(const Isolate* isolate) const;
  inline void set_index(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSCollectionIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kTableOffset = P::kHeaderSize;
  static constexpr int kTableOffsetEnd = kTableOffset + kTaggedSize - 1;
  static constexpr int kIndexOffset = kTableOffsetEnd + 1;
  static constexpr int kIndexOffsetEnd = kIndexOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kHeaderSize = kIndexOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSCollectionIterator() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSCollectionIterator, 
      DAlias>::value,
      "class TorqueGeneratedJSCollectionIterator should be used as direct base for JSCollectionIterator.");
  }
protected:
  inline explicit TorqueGeneratedJSCollectionIterator(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSCollection : public P {
  static_assert(std::is_same<JSCollection, D>::value,
    "Use this class as direct base for JSCollection.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSCollection.");
 public: 
  using Super = P;
  inline Object table() const;
  inline Object table(const Isolate* isolate) const;
  inline void set_table(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSCollectionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kTableOffset = P::kHeaderSize;
  static constexpr int kTableOffsetEnd = kTableOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kTableOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kTableOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kTableOffsetEnd + 1;
  static constexpr int kHeaderSize = kTableOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSCollection() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSCollection, 
      DAlias>::value,
      "class TorqueGeneratedJSCollection should be used as direct base for JSCollection.");
  }
protected:
  inline explicit TorqueGeneratedJSCollection(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSSet : public P {
  static_assert(std::is_same<JSSet, D>::value,
    "Use this class as direct base for JSSet.");
  static_assert(std::is_same<JSCollection, P>::value,
    "Pass in JSCollection as second template parameter for TorqueGeneratedJSSet.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSSetVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSSet() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSSet, 
      DAlias>::value,
      "class TorqueGeneratedJSSet should be used as direct base for JSSet.");
  }
protected:
  inline explicit TorqueGeneratedJSSet(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSMap : public P {
  static_assert(std::is_same<JSMap, D>::value,
    "Use this class as direct base for JSMap.");
  static_assert(std::is_same<JSCollection, P>::value,
    "Pass in JSCollection as second template parameter for TorqueGeneratedJSMap.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSMapVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSMap() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSMap, 
      DAlias>::value,
      "class TorqueGeneratedJSMap should be used as direct base for JSMap.");
  }
protected:
  inline explicit TorqueGeneratedJSMap(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSWeakCollection : public P {
  static_assert(std::is_same<JSWeakCollection, D>::value,
    "Use this class as direct base for JSWeakCollection.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSWeakCollection.");
 public: 
  using Super = P;
  inline Object table() const;
  inline Object table(const Isolate* isolate) const;
  inline void set_table(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSWeakCollectionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kTableOffset = P::kHeaderSize;
  static constexpr int kTableOffsetEnd = kTableOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kTableOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kTableOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kTableOffsetEnd + 1;
  static constexpr int kHeaderSize = kTableOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSWeakCollection() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSWeakCollection, 
      DAlias>::value,
      "class TorqueGeneratedJSWeakCollection should be used as direct base for JSWeakCollection.");
  }
protected:
  inline explicit TorqueGeneratedJSWeakCollection(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSWeakSet : public P {
  static_assert(std::is_same<JSWeakSet, D>::value,
    "Use this class as direct base for JSWeakSet.");
  static_assert(std::is_same<JSWeakCollection, P>::value,
    "Pass in JSWeakCollection as second template parameter for TorqueGeneratedJSWeakSet.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSWeakSetVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSWeakSet() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSWeakSet, 
      DAlias>::value,
      "class TorqueGeneratedJSWeakSet should be used as direct base for JSWeakSet.");
  }
protected:
  inline explicit TorqueGeneratedJSWeakSet(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSWeakMap : public P {
  static_assert(std::is_same<JSWeakMap, D>::value,
    "Use this class as direct base for JSWeakMap.");
  static_assert(std::is_same<JSWeakCollection, P>::value,
    "Pass in JSWeakCollection as second template parameter for TorqueGeneratedJSWeakMap.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSWeakMapVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSWeakMap() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSWeakMap, 
      DAlias>::value,
      "class TorqueGeneratedJSWeakMap should be used as direct base for JSWeakMap.");
  }
protected:
  inline explicit TorqueGeneratedJSWeakMap(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSGeneratorObject : public P {
  static_assert(std::is_same<JSGeneratorObject, D>::value,
    "Use this class as direct base for JSGeneratorObject.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSGeneratorObject.");
 public: 
  using Super = P;
  inline JSFunction function() const;
  inline JSFunction function(const Isolate* isolate) const;
  inline void set_function(JSFunction value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Context context() const;
  inline Context context(const Isolate* isolate) const;
  inline void set_context(Context value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: JSAny
  inline Object receiver() const;
  inline Object receiver(const Isolate* isolate) const;
  inline void set_receiver(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object input_or_debug_pos() const;
  inline Object input_or_debug_pos(const Isolate* isolate) const;
  inline void set_input_or_debug_pos(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi resume_mode() const;
  inline void set_resume_mode(Smi value);

  inline Smi continuation() const;
  inline void set_continuation(Smi value);

  inline FixedArray parameters_and_registers() const;
  inline FixedArray parameters_and_registers(const Isolate* isolate) const;
  inline void set_parameters_and_registers(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSGeneratorObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kFunctionOffset = P::kHeaderSize;
  static constexpr int kFunctionOffsetEnd = kFunctionOffset + kTaggedSize - 1;
  static constexpr int kContextOffset = kFunctionOffsetEnd + 1;
  static constexpr int kContextOffsetEnd = kContextOffset + kTaggedSize - 1;
  static constexpr int kReceiverOffset = kContextOffsetEnd + 1;
  static constexpr int kReceiverOffsetEnd = kReceiverOffset + kTaggedSize - 1;
  static constexpr int kInputOrDebugPosOffset = kReceiverOffsetEnd + 1;
  static constexpr int kInputOrDebugPosOffsetEnd = kInputOrDebugPosOffset + kTaggedSize - 1;
  static constexpr int kResumeModeOffset = kInputOrDebugPosOffsetEnd + 1;
  static constexpr int kResumeModeOffsetEnd = kResumeModeOffset + kTaggedSize - 1;
  static constexpr int kContinuationOffset = kResumeModeOffsetEnd + 1;
  static constexpr int kContinuationOffsetEnd = kContinuationOffset + kTaggedSize - 1;
  static constexpr int kParametersAndRegistersOffset = kContinuationOffsetEnd + 1;
  static constexpr int kParametersAndRegistersOffsetEnd = kParametersAndRegistersOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kParametersAndRegistersOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kParametersAndRegistersOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kParametersAndRegistersOffsetEnd + 1;
  static constexpr int kHeaderSize = kParametersAndRegistersOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSGeneratorObject() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSGeneratorObject, 
      DAlias>::value,
      "class TorqueGeneratedJSGeneratorObject should be used as direct base for JSGeneratorObject.");
  }
protected:
  inline explicit TorqueGeneratedJSGeneratorObject(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSAsyncFunctionObject : public P {
  static_assert(std::is_same<JSAsyncFunctionObject, D>::value,
    "Use this class as direct base for JSAsyncFunctionObject.");
  static_assert(std::is_same<JSGeneratorObject, P>::value,
    "Pass in JSGeneratorObject as second template parameter for TorqueGeneratedJSAsyncFunctionObject.");
 public: 
  using Super = P;
  inline JSPromise promise() const;
  inline JSPromise promise(const Isolate* isolate) const;
  inline void set_promise(JSPromise value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSAsyncFunctionObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kPromiseOffset = P::kHeaderSize;
  static constexpr int kPromiseOffsetEnd = kPromiseOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPromiseOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPromiseOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPromiseOffsetEnd + 1;
  static constexpr int kHeaderSize = kPromiseOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSAsyncFunctionObject() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSAsyncFunctionObject, 
      DAlias>::value,
      "class TorqueGeneratedJSAsyncFunctionObject should be used as direct base for JSAsyncFunctionObject.");
  }
protected:
  inline explicit TorqueGeneratedJSAsyncFunctionObject(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSAsyncGeneratorObject : public P {
  static_assert(std::is_same<JSAsyncGeneratorObject, D>::value,
    "Use this class as direct base for JSAsyncGeneratorObject.");
  static_assert(std::is_same<JSGeneratorObject, P>::value,
    "Pass in JSGeneratorObject as second template parameter for TorqueGeneratedJSAsyncGeneratorObject.");
 public: 
  using Super = P;
  inline HeapObject queue() const;
  inline HeapObject queue(const Isolate* isolate) const;
  inline void set_queue(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi is_awaiting() const;
  inline void set_is_awaiting(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSAsyncGeneratorObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kQueueOffset = P::kHeaderSize;
  static constexpr int kQueueOffsetEnd = kQueueOffset + kTaggedSize - 1;
  static constexpr int kIsAwaitingOffset = kQueueOffsetEnd + 1;
  static constexpr int kIsAwaitingOffsetEnd = kIsAwaitingOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIsAwaitingOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIsAwaitingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIsAwaitingOffsetEnd + 1;
  static constexpr int kHeaderSize = kIsAwaitingOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSAsyncGeneratorObject() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSAsyncGeneratorObject, 
      DAlias>::value,
      "class TorqueGeneratedJSAsyncGeneratorObject should be used as direct base for JSAsyncGeneratorObject.");
  }
protected:
  inline explicit TorqueGeneratedJSAsyncGeneratorObject(Address ptr);
};

template <class D, class P>
class TorqueGeneratedAsyncGeneratorRequest : public P {
  static_assert(std::is_same<AsyncGeneratorRequest, D>::value,
    "Use this class as direct base for AsyncGeneratorRequest.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedAsyncGeneratorRequest.");
 public: 
  using Super = P;
  inline HeapObject next() const;
  inline HeapObject next(const Isolate* isolate) const;
  inline void set_next(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi resume_mode() const;
  inline void set_resume_mode(Smi value);

  inline Object value() const;
  inline Object value(const Isolate* isolate) const;
  inline void set_value(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline JSPromise promise() const;
  inline JSPromise promise(const Isolate* isolate) const;
  inline void set_promise(JSPromise value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void AsyncGeneratorRequestVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kNextOffset = P::kHeaderSize;
  static constexpr int kNextOffsetEnd = kNextOffset + kTaggedSize - 1;
  static constexpr int kResumeModeOffset = kNextOffsetEnd + 1;
  static constexpr int kResumeModeOffsetEnd = kResumeModeOffset + kTaggedSize - 1;
  static constexpr int kValueOffset = kResumeModeOffsetEnd + 1;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  static constexpr int kPromiseOffset = kValueOffsetEnd + 1;
  static constexpr int kPromiseOffsetEnd = kPromiseOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPromiseOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPromiseOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPromiseOffsetEnd + 1;
  static constexpr int kHeaderSize = kPromiseOffsetEnd + 1;
  static constexpr int kSize = kPromiseOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedAsyncGeneratorRequest() : P() {
    static_assert(std::is_base_of<TorqueGeneratedAsyncGeneratorRequest, 
      DAlias>::value,
      "class TorqueGeneratedAsyncGeneratorRequest should be used as direct base for AsyncGeneratorRequest.");
  }
protected:
  inline explicit TorqueGeneratedAsyncGeneratorRequest(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSGlobalProxy : public P {
  static_assert(std::is_same<JSGlobalProxy, D>::value,
    "Use this class as direct base for JSGlobalProxy.");
  static_assert(std::is_same<JSSpecialObject, P>::value,
    "Pass in JSSpecialObject as second template parameter for TorqueGeneratedJSGlobalProxy.");
 public: 
  using Super = P;
  inline Object native_context() const;
  inline Object native_context(const Isolate* isolate) const;
  inline void set_native_context(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSGlobalProxyVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kNativeContextOffset = P::kHeaderSize;
  static constexpr int kNativeContextOffsetEnd = kNativeContextOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kNativeContextOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kNativeContextOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kNativeContextOffsetEnd + 1;
  static constexpr int kHeaderSize = kNativeContextOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSGlobalProxy() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSGlobalProxy, 
      DAlias>::value,
      "class TorqueGeneratedJSGlobalProxy should be used as direct base for JSGlobalProxy.");
  }
protected:
  inline explicit TorqueGeneratedJSGlobalProxy(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSPrimitiveWrapper : public P {
  static_assert(std::is_same<JSPrimitiveWrapper, D>::value,
    "Use this class as direct base for JSPrimitiveWrapper.");
  static_assert(std::is_same<JSCustomElementsObject, P>::value,
    "Pass in JSCustomElementsObject as second template parameter for TorqueGeneratedJSPrimitiveWrapper.");
 public: 
  using Super = P;
  // Torque type: JSAny
  inline Object value() const;
  inline Object value(const Isolate* isolate) const;
  inline void set_value(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSPrimitiveWrapperVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kHeaderSize = kValueOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSPrimitiveWrapper() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSPrimitiveWrapper, 
      DAlias>::value,
      "class TorqueGeneratedJSPrimitiveWrapper should be used as direct base for JSPrimitiveWrapper.");
  }
protected:
  inline explicit TorqueGeneratedJSPrimitiveWrapper(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSDate : public P {
  static_assert(std::is_same<JSDate, D>::value,
    "Use this class as direct base for JSDate.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSDate.");
 public: 
  using Super = P;
  // Torque type: NumberOrUndefined
  inline Object value() const;
  inline Object value(const Isolate* isolate) const;
  inline void set_value(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined | NaN)
  inline Object year() const;
  inline Object year(const Isolate* isolate) const;
  inline void set_year(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined | NaN)
  inline Object month() const;
  inline Object month(const Isolate* isolate) const;
  inline void set_month(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined | NaN)
  inline Object day() const;
  inline Object day(const Isolate* isolate) const;
  inline void set_day(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined | NaN)
  inline Object weekday() const;
  inline Object weekday(const Isolate* isolate) const;
  inline void set_weekday(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined | NaN)
  inline Object hour() const;
  inline Object hour(const Isolate* isolate) const;
  inline void set_hour(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined | NaN)
  inline Object min() const;
  inline Object min(const Isolate* isolate) const;
  inline void set_min(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined | NaN)
  inline Object sec() const;
  inline Object sec(const Isolate* isolate) const;
  inline void set_sec(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined | NaN)
  inline Object cache_stamp() const;
  inline Object cache_stamp(const Isolate* isolate) const;
  inline void set_cache_stamp(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSDateVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  static constexpr int kYearOffset = kValueOffsetEnd + 1;
  static constexpr int kYearOffsetEnd = kYearOffset + kTaggedSize - 1;
  static constexpr int kMonthOffset = kYearOffsetEnd + 1;
  static constexpr int kMonthOffsetEnd = kMonthOffset + kTaggedSize - 1;
  static constexpr int kDayOffset = kMonthOffsetEnd + 1;
  static constexpr int kDayOffsetEnd = kDayOffset + kTaggedSize - 1;
  static constexpr int kWeekdayOffset = kDayOffsetEnd + 1;
  static constexpr int kWeekdayOffsetEnd = kWeekdayOffset + kTaggedSize - 1;
  static constexpr int kHourOffset = kWeekdayOffsetEnd + 1;
  static constexpr int kHourOffsetEnd = kHourOffset + kTaggedSize - 1;
  static constexpr int kMinOffset = kHourOffsetEnd + 1;
  static constexpr int kMinOffsetEnd = kMinOffset + kTaggedSize - 1;
  static constexpr int kSecOffset = kMinOffsetEnd + 1;
  static constexpr int kSecOffsetEnd = kSecOffset + kTaggedSize - 1;
  static constexpr int kCacheStampOffset = kSecOffsetEnd + 1;
  static constexpr int kCacheStampOffsetEnd = kCacheStampOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCacheStampOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCacheStampOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCacheStampOffsetEnd + 1;
  static constexpr int kHeaderSize = kCacheStampOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSDate() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSDate, 
      DAlias>::value,
      "class TorqueGeneratedJSDate should be used as direct base for JSDate.");
  }
protected:
  inline explicit TorqueGeneratedJSDate(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSAsyncFromSyncIterator : public P {
  static_assert(std::is_same<JSAsyncFromSyncIterator, D>::value,
    "Use this class as direct base for JSAsyncFromSyncIterator.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSAsyncFromSyncIterator.");
 public: 
  using Super = P;
  inline JSReceiver sync_iterator() const;
  inline JSReceiver sync_iterator(const Isolate* isolate) const;
  inline void set_sync_iterator(JSReceiver value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object next() const;
  inline Object next(const Isolate* isolate) const;
  inline void set_next(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSAsyncFromSyncIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kSyncIteratorOffset = P::kHeaderSize;
  static constexpr int kSyncIteratorOffsetEnd = kSyncIteratorOffset + kTaggedSize - 1;
  static constexpr int kNextOffset = kSyncIteratorOffsetEnd + 1;
  static constexpr int kNextOffsetEnd = kNextOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kNextOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kNextOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kNextOffsetEnd + 1;
  static constexpr int kHeaderSize = kNextOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSAsyncFromSyncIterator() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSAsyncFromSyncIterator, 
      DAlias>::value,
      "class TorqueGeneratedJSAsyncFromSyncIterator should be used as direct base for JSAsyncFromSyncIterator.");
  }
protected:
  inline explicit TorqueGeneratedJSAsyncFromSyncIterator(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSStringIterator : public P {
  static_assert(std::is_same<JSStringIterator, D>::value,
    "Use this class as direct base for JSStringIterator.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSStringIterator.");
 public: 
  using Super = P;
  inline String string() const;
  inline String string(const Isolate* isolate) const;
  inline void set_string(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi index() const;
  inline void set_index(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSStringIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kStringOffset = P::kHeaderSize;
  static constexpr int kStringOffsetEnd = kStringOffset + kTaggedSize - 1;
  static constexpr int kIndexOffset = kStringOffsetEnd + 1;
  static constexpr int kIndexOffsetEnd = kIndexOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kHeaderSize = kIndexOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSStringIterator() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSStringIterator, 
      DAlias>::value,
      "class TorqueGeneratedJSStringIterator should be used as direct base for JSStringIterator.");
  }
protected:
  inline explicit TorqueGeneratedJSStringIterator(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSPromise : public P {
  static_assert(std::is_same<JSPromise, D>::value,
    "Use this class as direct base for JSPromise.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSPromise.");
 public: 
  using Super = P;
  // Torque type: (class JSReceiver | Smi | class HeapNumber | BigInt | class String | class Symbol | True | False | Null | Undefined | class PromiseReaction)
  inline Object reactions_or_result() const;
  inline Object reactions_or_result(const Isolate* isolate) const;
  inline void set_reactions_or_result(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi flags() const;
  inline void set_flags(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSPromiseVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kReactionsOrResultOffset = P::kHeaderSize;
  static constexpr int kReactionsOrResultOffsetEnd = kReactionsOrResultOffset + kTaggedSize - 1;
  static constexpr int kFlagsOffset = kReactionsOrResultOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSPromise() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSPromise, 
      DAlias>::value,
      "class TorqueGeneratedJSPromise should be used as direct base for JSPromise.");
  }
protected:
  inline explicit TorqueGeneratedJSPromise(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSRegExpStringIterator : public P {
  static_assert(std::is_same<JSRegExpStringIterator, D>::value,
    "Use this class as direct base for JSRegExpStringIterator.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSRegExpStringIterator.");
 public: 
  using Super = P;
  inline JSReceiver iterating_reg_exp() const;
  inline JSReceiver iterating_reg_exp(const Isolate* isolate) const;
  inline void set_iterating_reg_exp(JSReceiver value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline String iterated_string() const;
  inline String iterated_string(const Isolate* isolate) const;
  inline void set_iterated_string(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi flags() const;
  inline void set_flags(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSRegExpStringIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kIteratingRegExpOffset = P::kHeaderSize;
  static constexpr int kIteratingRegExpOffsetEnd = kIteratingRegExpOffset + kTaggedSize - 1;
  static constexpr int kIteratedStringOffset = kIteratingRegExpOffsetEnd + 1;
  static constexpr int kIteratedStringOffsetEnd = kIteratedStringOffset + kTaggedSize - 1;
  static constexpr int kFlagsOffset = kIteratedStringOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSRegExpStringIterator() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSRegExpStringIterator, 
      DAlias>::value,
      "class TorqueGeneratedJSRegExpStringIterator should be used as direct base for JSRegExpStringIterator.");
  }
protected:
  inline explicit TorqueGeneratedJSRegExpStringIterator(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSRegExp : public P {
  static_assert(std::is_same<JSRegExp, D>::value,
    "Use this class as direct base for JSRegExp.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSRegExp.");
 public: 
  using Super = P;
  inline HeapObject data() const;
  inline HeapObject data(const Isolate* isolate) const;
  inline void set_data(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline PrimitiveHeapObject source() const;
  inline PrimitiveHeapObject source(const Isolate* isolate) const;
  inline void set_source(PrimitiveHeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | Undefined)
  inline Object flags() const;
  inline Object flags(const Isolate* isolate) const;
  inline void set_flags(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSRegExpVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kDataOffset = P::kHeaderSize;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kSourceOffset = kDataOffsetEnd + 1;
  static constexpr int kSourceOffsetEnd = kSourceOffset + kTaggedSize - 1;
  static constexpr int kFlagsOffset = kSourceOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSRegExp() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSRegExp, 
      DAlias>::value,
      "class TorqueGeneratedJSRegExp should be used as direct base for JSRegExp.");
  }
protected:
  inline explicit TorqueGeneratedJSRegExp(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSFinalizationGroupCleanupIterator : public P {
  static_assert(std::is_same<JSFinalizationGroupCleanupIterator, D>::value,
    "Use this class as direct base for JSFinalizationGroupCleanupIterator.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSFinalizationGroupCleanupIterator.");
 public: 
  using Super = P;
  inline JSFinalizationGroup finalization_group() const;
  inline JSFinalizationGroup finalization_group(const Isolate* isolate) const;
  inline void set_finalization_group(JSFinalizationGroup value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSFinalizationGroupCleanupIteratorVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kFinalizationGroupOffset = P::kHeaderSize;
  static constexpr int kFinalizationGroupOffsetEnd = kFinalizationGroupOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFinalizationGroupOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFinalizationGroupOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFinalizationGroupOffsetEnd + 1;
  static constexpr int kHeaderSize = kFinalizationGroupOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSFinalizationGroupCleanupIterator() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSFinalizationGroupCleanupIterator, 
      DAlias>::value,
      "class TorqueGeneratedJSFinalizationGroupCleanupIterator should be used as direct base for JSFinalizationGroupCleanupIterator.");
  }
protected:
  inline explicit TorqueGeneratedJSFinalizationGroupCleanupIterator(Address ptr);
};

template <class D, class P>
class TorqueGeneratedWeakCell : public P {
  static_assert(std::is_same<WeakCell, D>::value,
    "Use this class as direct base for WeakCell.");
  static_assert(std::is_same<HeapObject, P>::value,
    "Pass in HeapObject as second template parameter for TorqueGeneratedWeakCell.");
 public: 
  using Super = P;
  inline HeapObject finalization_group() const;
  inline HeapObject finalization_group(const Isolate* isolate) const;
  inline void set_finalization_group(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject target() const;
  inline HeapObject target(const Isolate* isolate) const;
  inline void set_target(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object holdings() const;
  inline Object holdings(const Isolate* isolate) const;
  inline void set_holdings(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject prev() const;
  inline HeapObject prev(const Isolate* isolate) const;
  inline void set_prev(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject next() const;
  inline HeapObject next(const Isolate* isolate) const;
  inline void set_next(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object key() const;
  inline Object key(const Isolate* isolate) const;
  inline void set_key(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject key_list_prev() const;
  inline HeapObject key_list_prev(const Isolate* isolate) const;
  inline void set_key_list_prev(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject key_list_next() const;
  inline HeapObject key_list_next(const Isolate* isolate) const;
  inline void set_key_list_next(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void WeakCellVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kFinalizationGroupOffset = P::kHeaderSize;
  static constexpr int kFinalizationGroupOffsetEnd = kFinalizationGroupOffset + kTaggedSize - 1;
  static constexpr int kTargetOffset = kFinalizationGroupOffsetEnd + 1;
  static constexpr int kTargetOffsetEnd = kTargetOffset + kTaggedSize - 1;
  static constexpr int kHoldingsOffset = kTargetOffsetEnd + 1;
  static constexpr int kHoldingsOffsetEnd = kHoldingsOffset + kTaggedSize - 1;
  static constexpr int kPrevOffset = kHoldingsOffsetEnd + 1;
  static constexpr int kPrevOffsetEnd = kPrevOffset + kTaggedSize - 1;
  static constexpr int kNextOffset = kPrevOffsetEnd + 1;
  static constexpr int kNextOffsetEnd = kNextOffset + kTaggedSize - 1;
  static constexpr int kKeyOffset = kNextOffsetEnd + 1;
  static constexpr int kKeyOffsetEnd = kKeyOffset + kTaggedSize - 1;
  static constexpr int kKeyListPrevOffset = kKeyOffsetEnd + 1;
  static constexpr int kKeyListPrevOffsetEnd = kKeyListPrevOffset + kTaggedSize - 1;
  static constexpr int kKeyListNextOffset = kKeyListPrevOffsetEnd + 1;
  static constexpr int kKeyListNextOffsetEnd = kKeyListNextOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kKeyListNextOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kKeyListNextOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kKeyListNextOffsetEnd + 1;
  static constexpr int kHeaderSize = kKeyListNextOffsetEnd + 1;
  static constexpr int kSize = kKeyListNextOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedWeakCell() : P() {
    static_assert(std::is_base_of<TorqueGeneratedWeakCell, 
      DAlias>::value,
      "class TorqueGeneratedWeakCell should be used as direct base for WeakCell.");
  }
protected:
  inline explicit TorqueGeneratedWeakCell(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSWeakRef : public P {
  static_assert(std::is_same<JSWeakRef, D>::value,
    "Use this class as direct base for JSWeakRef.");
  static_assert(std::is_same<JSObject, P>::value,
    "Pass in JSObject as second template parameter for TorqueGeneratedJSWeakRef.");
 public: 
  using Super = P;
  inline HeapObject target() const;
  inline HeapObject target(const Isolate* isolate) const;
  inline void set_target(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSWeakRefVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kTargetOffset = P::kHeaderSize;
  static constexpr int kTargetOffsetEnd = kTargetOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kTargetOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kTargetOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kTargetOffsetEnd + 1;
  static constexpr int kHeaderSize = kTargetOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSWeakRef() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSWeakRef, 
      DAlias>::value,
      "class TorqueGeneratedJSWeakRef should be used as direct base for JSWeakRef.");
  }
protected:
  inline explicit TorqueGeneratedJSWeakRef(Address ptr);
};

template <class D, class P>
class TorqueGeneratedArrayBoilerplateDescription : public P {
  static_assert(std::is_same<ArrayBoilerplateDescription, D>::value,
    "Use this class as direct base for ArrayBoilerplateDescription.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedArrayBoilerplateDescription.");
 public: 
  using Super = P;
  inline Smi flags() const;
  inline void set_flags(Smi value);

  inline FixedArrayBase constant_elements() const;
  inline FixedArrayBase constant_elements(const Isolate* isolate) const;
  inline void set_constant_elements(FixedArrayBase value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void ArrayBoilerplateDescriptionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kFlagsOffset = P::kHeaderSize;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kConstantElementsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kConstantElementsOffsetEnd = kConstantElementsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kConstantElementsOffsetEnd + 1;
  static constexpr int kHeaderSize = kConstantElementsOffsetEnd + 1;
  static constexpr int kSize = kConstantElementsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedArrayBoilerplateDescription() : P() {
    static_assert(std::is_base_of<TorqueGeneratedArrayBoilerplateDescription, 
      DAlias>::value,
      "class TorqueGeneratedArrayBoilerplateDescription should be used as direct base for ArrayBoilerplateDescription.");
  }
protected:
  inline explicit TorqueGeneratedArrayBoilerplateDescription(Address ptr);
};

template <class D, class P>
class TorqueGeneratedMicrotask : public P {
  static_assert(std::is_same<Microtask, D>::value,
    "Use this class as direct base for Microtask.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedMicrotask.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void MicrotaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedMicrotask() : P() {
    static_assert(std::is_base_of<TorqueGeneratedMicrotask, 
      DAlias>::value,
      "class TorqueGeneratedMicrotask should be used as direct base for Microtask.");
  }
protected:
  inline explicit TorqueGeneratedMicrotask(Address ptr);
};

template <class D, class P>
class TorqueGeneratedCallbackTask : public P {
  static_assert(std::is_same<CallbackTask, D>::value,
    "Use this class as direct base for CallbackTask.");
  static_assert(std::is_same<Microtask, P>::value,
    "Pass in Microtask as second template parameter for TorqueGeneratedCallbackTask.");
 public: 
  using Super = P;
  inline Foreign callback() const;
  inline Foreign callback(const Isolate* isolate) const;
  inline void set_callback(Foreign value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Foreign data() const;
  inline Foreign data(const Isolate* isolate) const;
  inline void set_data(Foreign value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void CallbackTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kCallbackOffset = P::kHeaderSize;
  static constexpr int kCallbackOffsetEnd = kCallbackOffset + kTaggedSize - 1;
  static constexpr int kDataOffset = kCallbackOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kDataOffsetEnd + 1;
  static constexpr int kSize = kDataOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedCallbackTask() : P() {
    static_assert(std::is_base_of<TorqueGeneratedCallbackTask, 
      DAlias>::value,
      "class TorqueGeneratedCallbackTask should be used as direct base for CallbackTask.");
  }
protected:
  inline explicit TorqueGeneratedCallbackTask(Address ptr);
};

template <class D, class P>
class TorqueGeneratedCallableTask : public P {
  static_assert(std::is_same<CallableTask, D>::value,
    "Use this class as direct base for CallableTask.");
  static_assert(std::is_same<Microtask, P>::value,
    "Pass in Microtask as second template parameter for TorqueGeneratedCallableTask.");
 public: 
  using Super = P;
  inline JSReceiver callable() const;
  inline JSReceiver callable(const Isolate* isolate) const;
  inline void set_callable(JSReceiver value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Context context() const;
  inline Context context(const Isolate* isolate) const;
  inline void set_context(Context value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void CallableTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kCallableOffset = P::kHeaderSize;
  static constexpr int kCallableOffsetEnd = kCallableOffset + kTaggedSize - 1;
  static constexpr int kContextOffset = kCallableOffsetEnd + 1;
  static constexpr int kContextOffsetEnd = kContextOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kContextOffsetEnd + 1;
  static constexpr int kHeaderSize = kContextOffsetEnd + 1;
  static constexpr int kSize = kContextOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedCallableTask() : P() {
    static_assert(std::is_base_of<TorqueGeneratedCallableTask, 
      DAlias>::value,
      "class TorqueGeneratedCallableTask should be used as direct base for CallableTask.");
  }
protected:
  inline explicit TorqueGeneratedCallableTask(Address ptr);
};

template <class D, class P>
class TorqueGeneratedJSModuleNamespace : public P {
  static_assert(std::is_same<JSModuleNamespace, D>::value,
    "Use this class as direct base for JSModuleNamespace.");
  static_assert(std::is_same<JSSpecialObject, P>::value,
    "Pass in JSSpecialObject as second template parameter for TorqueGeneratedJSModuleNamespace.");
 public: 
  using Super = P;
  inline Module module() const;
  inline Module module(const Isolate* isolate) const;
  inline void set_module(Module value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void JSModuleNamespaceVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kModuleOffset = P::kHeaderSize;
  static constexpr int kModuleOffsetEnd = kModuleOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kModuleOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kModuleOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kModuleOffsetEnd + 1;
  static constexpr int kHeaderSize = kModuleOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedJSModuleNamespace() : P() {
    static_assert(std::is_base_of<TorqueGeneratedJSModuleNamespace, 
      DAlias>::value,
      "class TorqueGeneratedJSModuleNamespace should be used as direct base for JSModuleNamespace.");
  }
protected:
  inline explicit TorqueGeneratedJSModuleNamespace(Address ptr);
};

template <class D, class P>
class TorqueGeneratedPromiseCapability : public P {
  static_assert(std::is_same<PromiseCapability, D>::value,
    "Use this class as direct base for PromiseCapability.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedPromiseCapability.");
 public: 
  using Super = P;
  inline HeapObject promise() const;
  inline HeapObject promise(const Isolate* isolate) const;
  inline void set_promise(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object resolve() const;
  inline Object resolve(const Isolate* isolate) const;
  inline void set_resolve(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object reject() const;
  inline Object reject(const Isolate* isolate) const;
  inline void set_reject(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void PromiseCapabilityVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kPromiseOffset = P::kHeaderSize;
  static constexpr int kPromiseOffsetEnd = kPromiseOffset + kTaggedSize - 1;
  static constexpr int kResolveOffset = kPromiseOffsetEnd + 1;
  static constexpr int kResolveOffsetEnd = kResolveOffset + kTaggedSize - 1;
  static constexpr int kRejectOffset = kResolveOffsetEnd + 1;
  static constexpr int kRejectOffsetEnd = kRejectOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kRejectOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kRejectOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kRejectOffsetEnd + 1;
  static constexpr int kHeaderSize = kRejectOffsetEnd + 1;
  static constexpr int kSize = kRejectOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseCapability() : P() {
    static_assert(std::is_base_of<TorqueGeneratedPromiseCapability, 
      DAlias>::value,
      "class TorqueGeneratedPromiseCapability should be used as direct base for PromiseCapability.");
  }
protected:
  inline explicit TorqueGeneratedPromiseCapability(Address ptr);
};

template <class D, class P>
class TorqueGeneratedPromiseReaction : public P {
  static_assert(std::is_same<PromiseReaction, D>::value,
    "Use this class as direct base for PromiseReaction.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedPromiseReaction.");
 public: 
  using Super = P;
  // Torque type: (Zero | class PromiseReaction)
  inline Object next() const;
  inline Object next(const Isolate* isolate) const;
  inline void set_next(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject reject_handler() const;
  inline HeapObject reject_handler(const Isolate* isolate) const;
  inline void set_reject_handler(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject fulfill_handler() const;
  inline HeapObject fulfill_handler(const Isolate* isolate) const;
  inline void set_fulfill_handler(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject promise_or_capability() const;
  inline HeapObject promise_or_capability(const Isolate* isolate) const;
  inline void set_promise_or_capability(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void PromiseReactionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kNextOffset = P::kHeaderSize;
  static constexpr int kNextOffsetEnd = kNextOffset + kTaggedSize - 1;
  static constexpr int kRejectHandlerOffset = kNextOffsetEnd + 1;
  static constexpr int kRejectHandlerOffsetEnd = kRejectHandlerOffset + kTaggedSize - 1;
  static constexpr int kFulfillHandlerOffset = kRejectHandlerOffsetEnd + 1;
  static constexpr int kFulfillHandlerOffsetEnd = kFulfillHandlerOffset + kTaggedSize - 1;
  static constexpr int kPromiseOrCapabilityOffset = kFulfillHandlerOffsetEnd + 1;
  static constexpr int kPromiseOrCapabilityOffsetEnd = kPromiseOrCapabilityOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kHeaderSize = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kSize = kPromiseOrCapabilityOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseReaction() : P() {
    static_assert(std::is_base_of<TorqueGeneratedPromiseReaction, 
      DAlias>::value,
      "class TorqueGeneratedPromiseReaction should be used as direct base for PromiseReaction.");
  }
protected:
  inline explicit TorqueGeneratedPromiseReaction(Address ptr);
};

template <class D, class P>
class TorqueGeneratedPromiseReactionJobTask : public P {
  static_assert(std::is_same<PromiseReactionJobTask, D>::value,
    "Use this class as direct base for PromiseReactionJobTask.");
  static_assert(std::is_same<Microtask, P>::value,
    "Pass in Microtask as second template parameter for TorqueGeneratedPromiseReactionJobTask.");
 public: 
  using Super = P;
  inline Object argument() const;
  inline Object argument(const Isolate* isolate) const;
  inline void set_argument(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Context context() const;
  inline Context context(const Isolate* isolate) const;
  inline void set_context(Context value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject handler() const;
  inline HeapObject handler(const Isolate* isolate) const;
  inline void set_handler(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject promise_or_capability() const;
  inline HeapObject promise_or_capability(const Isolate* isolate) const;
  inline void set_promise_or_capability(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void PromiseReactionJobTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kArgumentOffset = P::kHeaderSize;
  static constexpr int kArgumentOffsetEnd = kArgumentOffset + kTaggedSize - 1;
  static constexpr int kContextOffset = kArgumentOffsetEnd + 1;
  static constexpr int kContextOffsetEnd = kContextOffset + kTaggedSize - 1;
  static constexpr int kHandlerOffset = kContextOffsetEnd + 1;
  static constexpr int kHandlerOffsetEnd = kHandlerOffset + kTaggedSize - 1;
  static constexpr int kPromiseOrCapabilityOffset = kHandlerOffsetEnd + 1;
  static constexpr int kPromiseOrCapabilityOffsetEnd = kPromiseOrCapabilityOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPromiseOrCapabilityOffsetEnd + 1;
  static constexpr int kHeaderSize = kPromiseOrCapabilityOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseReactionJobTask() : P() {
    static_assert(std::is_base_of<TorqueGeneratedPromiseReactionJobTask, 
      DAlias>::value,
      "class TorqueGeneratedPromiseReactionJobTask should be used as direct base for PromiseReactionJobTask.");
  }
protected:
  inline explicit TorqueGeneratedPromiseReactionJobTask(Address ptr);
};

template <class D, class P>
class TorqueGeneratedPromiseFulfillReactionJobTask : public P {
  static_assert(std::is_same<PromiseFulfillReactionJobTask, D>::value,
    "Use this class as direct base for PromiseFulfillReactionJobTask.");
  static_assert(std::is_same<PromiseReactionJobTask, P>::value,
    "Pass in PromiseReactionJobTask as second template parameter for TorqueGeneratedPromiseFulfillReactionJobTask.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void PromiseFulfillReactionJobTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseFulfillReactionJobTask() : P() {
    static_assert(std::is_base_of<TorqueGeneratedPromiseFulfillReactionJobTask, 
      DAlias>::value,
      "class TorqueGeneratedPromiseFulfillReactionJobTask should be used as direct base for PromiseFulfillReactionJobTask.");
  }
protected:
  inline explicit TorqueGeneratedPromiseFulfillReactionJobTask(Address ptr);
};

template <class D, class P>
class TorqueGeneratedPromiseRejectReactionJobTask : public P {
  static_assert(std::is_same<PromiseRejectReactionJobTask, D>::value,
    "Use this class as direct base for PromiseRejectReactionJobTask.");
  static_assert(std::is_same<PromiseReactionJobTask, P>::value,
    "Pass in PromiseReactionJobTask as second template parameter for TorqueGeneratedPromiseRejectReactionJobTask.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void PromiseRejectReactionJobTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseRejectReactionJobTask() : P() {
    static_assert(std::is_base_of<TorqueGeneratedPromiseRejectReactionJobTask, 
      DAlias>::value,
      "class TorqueGeneratedPromiseRejectReactionJobTask should be used as direct base for PromiseRejectReactionJobTask.");
  }
protected:
  inline explicit TorqueGeneratedPromiseRejectReactionJobTask(Address ptr);
};

template <class D, class P>
class TorqueGeneratedPromiseResolveThenableJobTask : public P {
  static_assert(std::is_same<PromiseResolveThenableJobTask, D>::value,
    "Use this class as direct base for PromiseResolveThenableJobTask.");
  static_assert(std::is_same<Microtask, P>::value,
    "Pass in Microtask as second template parameter for TorqueGeneratedPromiseResolveThenableJobTask.");
 public: 
  using Super = P;
  inline Context context() const;
  inline Context context(const Isolate* isolate) const;
  inline void set_context(Context value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline JSPromise promise_to_resolve() const;
  inline JSPromise promise_to_resolve(const Isolate* isolate) const;
  inline void set_promise_to_resolve(JSPromise value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline JSReceiver then() const;
  inline JSReceiver then(const Isolate* isolate) const;
  inline void set_then(JSReceiver value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline JSReceiver thenable() const;
  inline JSReceiver thenable(const Isolate* isolate) const;
  inline void set_thenable(JSReceiver value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void PromiseResolveThenableJobTaskVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kContextOffset = P::kHeaderSize;
  static constexpr int kContextOffsetEnd = kContextOffset + kTaggedSize - 1;
  static constexpr int kPromiseToResolveOffset = kContextOffsetEnd + 1;
  static constexpr int kPromiseToResolveOffsetEnd = kPromiseToResolveOffset + kTaggedSize - 1;
  static constexpr int kThenOffset = kPromiseToResolveOffsetEnd + 1;
  static constexpr int kThenOffsetEnd = kThenOffset + kTaggedSize - 1;
  static constexpr int kThenableOffset = kThenOffsetEnd + 1;
  static constexpr int kThenableOffsetEnd = kThenableOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kThenableOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kThenableOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kThenableOffsetEnd + 1;
  static constexpr int kHeaderSize = kThenableOffsetEnd + 1;
  static constexpr int kSize = kThenableOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedPromiseResolveThenableJobTask() : P() {
    static_assert(std::is_base_of<TorqueGeneratedPromiseResolveThenableJobTask, 
      DAlias>::value,
      "class TorqueGeneratedPromiseResolveThenableJobTask should be used as direct base for PromiseResolveThenableJobTask.");
  }
protected:
  inline explicit TorqueGeneratedPromiseResolveThenableJobTask(Address ptr);
};

template <class D, class P>
class TorqueGeneratedPreparseData : public P {
  static_assert(std::is_same<PreparseData, D>::value,
    "Use this class as direct base for PreparseData.");
  static_assert(std::is_same<HeapObject, P>::value,
    "Pass in HeapObject as second template parameter for TorqueGeneratedPreparseData.");
 public: 
  using Super = P;
  inline int32_t data_length() const;
  inline void set_data_length(int32_t value);

  inline int32_t children_length() const;
  inline void set_children_length(int32_t value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void PreparseDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kDataLengthOffset = P::kHeaderSize;
  static constexpr int kDataLengthOffsetEnd = kDataLengthOffset + kInt32Size - 1;
  static constexpr int kChildrenLengthOffset = kDataLengthOffsetEnd + 1;
  static constexpr int kChildrenLengthOffsetEnd = kChildrenLengthOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kChildrenLengthOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kChildrenLengthOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kChildrenLengthOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kChildrenLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kChildrenLengthOffsetEnd + 1;
  static constexpr int kSize = kChildrenLengthOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedPreparseData() : P() {
    static_assert(std::is_base_of<TorqueGeneratedPreparseData, 
      DAlias>::value,
      "class TorqueGeneratedPreparseData should be used as direct base for PreparseData.");
  }
protected:
  inline explicit TorqueGeneratedPreparseData(Address ptr);
};

template <class D, class P>
class TorqueGeneratedUncompiledData : public P {
  static_assert(std::is_same<UncompiledData, D>::value,
    "Use this class as direct base for UncompiledData.");
  static_assert(std::is_same<HeapObject, P>::value,
    "Pass in HeapObject as second template parameter for TorqueGeneratedUncompiledData.");
 public: 
  using Super = P;
  inline String inferred_name() const;
  inline String inferred_name(const Isolate* isolate) const;
  inline void set_inferred_name(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline int32_t start_position() const;
  inline void set_start_position(int32_t value);

  inline int32_t end_position() const;
  inline void set_end_position(int32_t value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void UncompiledDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kInferredNameOffset = P::kHeaderSize;
  static constexpr int kInferredNameOffsetEnd = kInferredNameOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kInferredNameOffsetEnd + 1;
  static constexpr int kStartPositionOffset = kInferredNameOffsetEnd + 1;
  static constexpr int kStartPositionOffsetEnd = kStartPositionOffset + kInt32Size - 1;
  static constexpr int kEndPositionOffset = kStartPositionOffsetEnd + 1;
  static constexpr int kEndPositionOffsetEnd = kEndPositionOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kEndPositionOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kEndPositionOffsetEnd + 1;
  static constexpr int kHeaderSize = kEndPositionOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedUncompiledData() : P() {
    static_assert(std::is_base_of<TorqueGeneratedUncompiledData, 
      DAlias>::value,
      "class TorqueGeneratedUncompiledData should be used as direct base for UncompiledData.");
  }
protected:
  inline explicit TorqueGeneratedUncompiledData(Address ptr);
};

template <class D, class P>
class TorqueGeneratedUncompiledDataWithoutPreparseData : public P {
  static_assert(std::is_same<UncompiledDataWithoutPreparseData, D>::value,
    "Use this class as direct base for UncompiledDataWithoutPreparseData.");
  static_assert(std::is_same<UncompiledData, P>::value,
    "Pass in UncompiledData as second template parameter for TorqueGeneratedUncompiledDataWithoutPreparseData.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void UncompiledDataWithoutPreparseDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedUncompiledDataWithoutPreparseData() : P() {
    static_assert(std::is_base_of<TorqueGeneratedUncompiledDataWithoutPreparseData, 
      DAlias>::value,
      "class TorqueGeneratedUncompiledDataWithoutPreparseData should be used as direct base for UncompiledDataWithoutPreparseData.");
  }
protected:
  inline explicit TorqueGeneratedUncompiledDataWithoutPreparseData(Address ptr);
};

template <class D, class P>
class TorqueGeneratedUncompiledDataWithPreparseData : public P {
  static_assert(std::is_same<UncompiledDataWithPreparseData, D>::value,
    "Use this class as direct base for UncompiledDataWithPreparseData.");
  static_assert(std::is_same<UncompiledData, P>::value,
    "Pass in UncompiledData as second template parameter for TorqueGeneratedUncompiledDataWithPreparseData.");
 public: 
  using Super = P;
  inline PreparseData preparse_data() const;
  inline PreparseData preparse_data(const Isolate* isolate) const;
  inline void set_preparse_data(PreparseData value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void UncompiledDataWithPreparseDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kPreparseDataOffset = P::kHeaderSize;
  static constexpr int kPreparseDataOffsetEnd = kPreparseDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPreparseDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPreparseDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPreparseDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kPreparseDataOffsetEnd + 1;
  static constexpr int kSize = kPreparseDataOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedUncompiledDataWithPreparseData() : P() {
    static_assert(std::is_base_of<TorqueGeneratedUncompiledDataWithPreparseData, 
      DAlias>::value,
      "class TorqueGeneratedUncompiledDataWithPreparseData should be used as direct base for UncompiledDataWithPreparseData.");
  }
protected:
  inline explicit TorqueGeneratedUncompiledDataWithPreparseData(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSourceTextModule : public P {
  static_assert(std::is_same<SourceTextModule, D>::value,
    "Use this class as direct base for SourceTextModule.");
  static_assert(std::is_same<Module, P>::value,
    "Pass in Module as second template parameter for TorqueGeneratedSourceTextModule.");
 public: 
  using Super = P;
  inline HeapObject code() const;
  inline HeapObject code(const Isolate* isolate) const;
  inline void set_code(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray regular_exports() const;
  inline FixedArray regular_exports(const Isolate* isolate) const;
  inline void set_regular_exports(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray regular_imports() const;
  inline FixedArray regular_imports(const Isolate* isolate) const;
  inline void set_regular_imports(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray requested_modules() const;
  inline FixedArray requested_modules(const Isolate* isolate) const;
  inline void set_requested_modules(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Script script() const;
  inline Script script(const Isolate* isolate) const;
  inline void set_script(Script value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject import_meta() const;
  inline HeapObject import_meta(const Isolate* isolate) const;
  inline void set_import_meta(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline ArrayList async_parent_modules() const;
  inline ArrayList async_parent_modules(const Isolate* isolate) const;
  inline void set_async_parent_modules(ArrayList value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject top_level_capability() const;
  inline HeapObject top_level_capability(const Isolate* isolate) const;
  inline void set_top_level_capability(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi dfs_index() const;
  inline void set_dfs_index(Smi value);

  inline Smi dfs_ancestor_index() const;
  inline void set_dfs_ancestor_index(Smi value);

  inline Smi pending_async_dependencies() const;
  inline void set_pending_async_dependencies(Smi value);

  inline Smi flags() const;
  inline void set_flags(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SourceTextModuleVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kCodeOffset = P::kHeaderSize;
  static constexpr int kCodeOffsetEnd = kCodeOffset + kTaggedSize - 1;
  static constexpr int kRegularExportsOffset = kCodeOffsetEnd + 1;
  static constexpr int kRegularExportsOffsetEnd = kRegularExportsOffset + kTaggedSize - 1;
  static constexpr int kRegularImportsOffset = kRegularExportsOffsetEnd + 1;
  static constexpr int kRegularImportsOffsetEnd = kRegularImportsOffset + kTaggedSize - 1;
  static constexpr int kRequestedModulesOffset = kRegularImportsOffsetEnd + 1;
  static constexpr int kRequestedModulesOffsetEnd = kRequestedModulesOffset + kTaggedSize - 1;
  static constexpr int kScriptOffset = kRequestedModulesOffsetEnd + 1;
  static constexpr int kScriptOffsetEnd = kScriptOffset + kTaggedSize - 1;
  static constexpr int kImportMetaOffset = kScriptOffsetEnd + 1;
  static constexpr int kImportMetaOffsetEnd = kImportMetaOffset + kTaggedSize - 1;
  static constexpr int kAsyncParentModulesOffset = kImportMetaOffsetEnd + 1;
  static constexpr int kAsyncParentModulesOffsetEnd = kAsyncParentModulesOffset + kTaggedSize - 1;
  static constexpr int kTopLevelCapabilityOffset = kAsyncParentModulesOffsetEnd + 1;
  static constexpr int kTopLevelCapabilityOffsetEnd = kTopLevelCapabilityOffset + kTaggedSize - 1;
  static constexpr int kDfsIndexOffset = kTopLevelCapabilityOffsetEnd + 1;
  static constexpr int kDfsIndexOffsetEnd = kDfsIndexOffset + kTaggedSize - 1;
  static constexpr int kDfsAncestorIndexOffset = kDfsIndexOffsetEnd + 1;
  static constexpr int kDfsAncestorIndexOffsetEnd = kDfsAncestorIndexOffset + kTaggedSize - 1;
  static constexpr int kPendingAsyncDependenciesOffset = kDfsAncestorIndexOffsetEnd + 1;
  static constexpr int kPendingAsyncDependenciesOffsetEnd = kPendingAsyncDependenciesOffset + kTaggedSize - 1;
  static constexpr int kFlagsOffset = kPendingAsyncDependenciesOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kFlagsOffsetEnd + 1;
  static constexpr int kHeaderSize = kFlagsOffsetEnd + 1;
  static constexpr int kSize = kFlagsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSourceTextModule() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSourceTextModule, 
      DAlias>::value,
      "class TorqueGeneratedSourceTextModule should be used as direct base for SourceTextModule.");
  }
protected:
  inline explicit TorqueGeneratedSourceTextModule(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSourceTextModuleInfoEntry : public P {
  static_assert(std::is_same<SourceTextModuleInfoEntry, D>::value,
    "Use this class as direct base for SourceTextModuleInfoEntry.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedSourceTextModuleInfoEntry.");
 public: 
  using Super = P;
  inline PrimitiveHeapObject export_name() const;
  inline PrimitiveHeapObject export_name(const Isolate* isolate) const;
  inline void set_export_name(PrimitiveHeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline PrimitiveHeapObject local_name() const;
  inline PrimitiveHeapObject local_name(const Isolate* isolate) const;
  inline void set_local_name(PrimitiveHeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline PrimitiveHeapObject import_name() const;
  inline PrimitiveHeapObject import_name(const Isolate* isolate) const;
  inline void set_import_name(PrimitiveHeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi module_request() const;
  inline void set_module_request(Smi value);

  inline Smi cell_index() const;
  inline void set_cell_index(Smi value);

  inline Smi beg_pos() const;
  inline void set_beg_pos(Smi value);

  inline Smi end_pos() const;
  inline void set_end_pos(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SourceTextModuleInfoEntryVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kExportNameOffset = P::kHeaderSize;
  static constexpr int kExportNameOffsetEnd = kExportNameOffset + kTaggedSize - 1;
  static constexpr int kLocalNameOffset = kExportNameOffsetEnd + 1;
  static constexpr int kLocalNameOffsetEnd = kLocalNameOffset + kTaggedSize - 1;
  static constexpr int kImportNameOffset = kLocalNameOffsetEnd + 1;
  static constexpr int kImportNameOffsetEnd = kImportNameOffset + kTaggedSize - 1;
  static constexpr int kModuleRequestOffset = kImportNameOffsetEnd + 1;
  static constexpr int kModuleRequestOffsetEnd = kModuleRequestOffset + kTaggedSize - 1;
  static constexpr int kCellIndexOffset = kModuleRequestOffsetEnd + 1;
  static constexpr int kCellIndexOffsetEnd = kCellIndexOffset + kTaggedSize - 1;
  static constexpr int kBegPosOffset = kCellIndexOffsetEnd + 1;
  static constexpr int kBegPosOffsetEnd = kBegPosOffset + kTaggedSize - 1;
  static constexpr int kEndPosOffset = kBegPosOffsetEnd + 1;
  static constexpr int kEndPosOffsetEnd = kEndPosOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kEndPosOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kEndPosOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kEndPosOffsetEnd + 1;
  static constexpr int kHeaderSize = kEndPosOffsetEnd + 1;
  static constexpr int kSize = kEndPosOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSourceTextModuleInfoEntry() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSourceTextModuleInfoEntry, 
      DAlias>::value,
      "class TorqueGeneratedSourceTextModuleInfoEntry should be used as direct base for SourceTextModuleInfoEntry.");
  }
protected:
  inline explicit TorqueGeneratedSourceTextModuleInfoEntry(Address ptr);
};

template <class D, class P>
class TorqueGeneratedStackTraceFrame : public P {
  static_assert(std::is_same<StackTraceFrame, D>::value,
    "Use this class as direct base for StackTraceFrame.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedStackTraceFrame.");
 public: 
  using Super = P;
  inline HeapObject frame_array() const;
  inline HeapObject frame_array(const Isolate* isolate) const;
  inline void set_frame_array(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi frame_index() const;
  inline void set_frame_index(Smi value);

  inline HeapObject frame_info() const;
  inline HeapObject frame_info(const Isolate* isolate) const;
  inline void set_frame_info(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi id() const;
  inline void set_id(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void StackTraceFrameVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kFrameArrayOffset = P::kHeaderSize;
  static constexpr int kFrameArrayOffsetEnd = kFrameArrayOffset + kTaggedSize - 1;
  static constexpr int kFrameIndexOffset = kFrameArrayOffsetEnd + 1;
  static constexpr int kFrameIndexOffsetEnd = kFrameIndexOffset + kTaggedSize - 1;
  static constexpr int kFrameInfoOffset = kFrameIndexOffsetEnd + 1;
  static constexpr int kFrameInfoOffsetEnd = kFrameInfoOffset + kTaggedSize - 1;
  static constexpr int kIdOffset = kFrameInfoOffsetEnd + 1;
  static constexpr int kIdOffsetEnd = kIdOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIdOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIdOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIdOffsetEnd + 1;
  static constexpr int kHeaderSize = kIdOffsetEnd + 1;
  static constexpr int kSize = kIdOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedStackTraceFrame() : P() {
    static_assert(std::is_base_of<TorqueGeneratedStackTraceFrame, 
      DAlias>::value,
      "class TorqueGeneratedStackTraceFrame should be used as direct base for StackTraceFrame.");
  }
protected:
  inline explicit TorqueGeneratedStackTraceFrame(Address ptr);
};

template <class D, class P>
class TorqueGeneratedConsString : public P {
  static_assert(std::is_same<ConsString, D>::value,
    "Use this class as direct base for ConsString.");
  static_assert(std::is_same<String, P>::value,
    "Pass in String as second template parameter for TorqueGeneratedConsString.");
 public: 
  using Super = P;
  inline String first() const;
  inline String first(const Isolate* isolate) const;
  inline void set_first(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline String second() const;
  inline String second(const Isolate* isolate) const;
  inline void set_second(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void ConsStringVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kFirstOffset = P::kHeaderSize;
  static constexpr int kFirstOffsetEnd = kFirstOffset + kTaggedSize - 1;
  static constexpr int kSecondOffset = kFirstOffsetEnd + 1;
  static constexpr int kSecondOffsetEnd = kSecondOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSecondOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSecondOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSecondOffsetEnd + 1;
  static constexpr int kHeaderSize = kSecondOffsetEnd + 1;
  static constexpr int kSize = kSecondOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedConsString() : P() {
    static_assert(std::is_base_of<TorqueGeneratedConsString, 
      DAlias>::value,
      "class TorqueGeneratedConsString should be used as direct base for ConsString.");
  }
protected:
  inline explicit TorqueGeneratedConsString(Address ptr);
};

template <class D, class P>
class TorqueGeneratedInternalizedString : public P {
  static_assert(std::is_same<InternalizedString, D>::value,
    "Use this class as direct base for InternalizedString.");
  static_assert(std::is_same<String, P>::value,
    "Pass in String as second template parameter for TorqueGeneratedInternalizedString.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void InternalizedStringVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedInternalizedString() : P() {
    static_assert(std::is_base_of<TorqueGeneratedInternalizedString, 
      DAlias>::value,
      "class TorqueGeneratedInternalizedString should be used as direct base for InternalizedString.");
  }
protected:
  inline explicit TorqueGeneratedInternalizedString(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSeqString : public P {
  static_assert(std::is_same<SeqString, D>::value,
    "Use this class as direct base for SeqString.");
  static_assert(std::is_same<String, P>::value,
    "Pass in String as second template parameter for TorqueGeneratedSeqString.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SeqStringVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSeqString() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSeqString, 
      DAlias>::value,
      "class TorqueGeneratedSeqString should be used as direct base for SeqString.");
  }
protected:
  inline explicit TorqueGeneratedSeqString(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSeqOneByteString : public P {
  static_assert(std::is_same<SeqOneByteString, D>::value,
    "Use this class as direct base for SeqOneByteString.");
  static_assert(std::is_same<SeqString, P>::value,
    "Pass in SeqString as second template parameter for TorqueGeneratedSeqOneByteString.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SeqOneByteStringVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kCharsOffset = P::kHeaderSize;
  static constexpr int kCharsOffsetEnd = kCharsOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kCharsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCharsOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kCharsOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kCharsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSeqOneByteString() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSeqOneByteString, 
      DAlias>::value,
      "class TorqueGeneratedSeqOneByteString should be used as direct base for SeqOneByteString.");
  }
protected:
  inline explicit TorqueGeneratedSeqOneByteString(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSeqTwoByteString : public P {
  static_assert(std::is_same<SeqTwoByteString, D>::value,
    "Use this class as direct base for SeqTwoByteString.");
  static_assert(std::is_same<SeqString, P>::value,
    "Pass in SeqString as second template parameter for TorqueGeneratedSeqTwoByteString.");
 public: 
  using Super = P;
  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SeqTwoByteStringVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kCharsOffset = P::kHeaderSize;
  static constexpr int kCharsOffsetEnd = kCharsOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kCharsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCharsOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kCharsOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kCharsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSeqTwoByteString() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSeqTwoByteString, 
      DAlias>::value,
      "class TorqueGeneratedSeqTwoByteString should be used as direct base for SeqTwoByteString.");
  }
protected:
  inline explicit TorqueGeneratedSeqTwoByteString(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSlicedString : public P {
  static_assert(std::is_same<SlicedString, D>::value,
    "Use this class as direct base for SlicedString.");
  static_assert(std::is_same<String, P>::value,
    "Pass in String as second template parameter for TorqueGeneratedSlicedString.");
 public: 
  using Super = P;
  inline String parent() const;
  inline String parent(const Isolate* isolate) const;
  inline void set_parent(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi offset() const;
  inline void set_offset(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SlicedStringVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kParentOffset = P::kHeaderSize;
  static constexpr int kParentOffsetEnd = kParentOffset + kTaggedSize - 1;
  static constexpr int kOffsetOffset = kParentOffsetEnd + 1;
  static constexpr int kOffsetOffsetEnd = kOffsetOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kOffsetOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kOffsetOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kOffsetOffsetEnd + 1;
  static constexpr int kHeaderSize = kOffsetOffsetEnd + 1;
  static constexpr int kSize = kOffsetOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSlicedString() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSlicedString, 
      DAlias>::value,
      "class TorqueGeneratedSlicedString should be used as direct base for SlicedString.");
  }
protected:
  inline explicit TorqueGeneratedSlicedString(Address ptr);
};

template <class D, class P>
class TorqueGeneratedThinString : public P {
  static_assert(std::is_same<ThinString, D>::value,
    "Use this class as direct base for ThinString.");
  static_assert(std::is_same<String, P>::value,
    "Pass in String as second template parameter for TorqueGeneratedThinString.");
 public: 
  using Super = P;
  inline String actual() const;
  inline String actual(const Isolate* isolate) const;
  inline void set_actual(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void ThinStringVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kActualOffset = P::kHeaderSize;
  static constexpr int kActualOffsetEnd = kActualOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kActualOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kActualOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kActualOffsetEnd + 1;
  static constexpr int kHeaderSize = kActualOffsetEnd + 1;
  static constexpr int kSize = kActualOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedThinString() : P() {
    static_assert(std::is_base_of<TorqueGeneratedThinString, 
      DAlias>::value,
      "class TorqueGeneratedThinString should be used as direct base for ThinString.");
  }
protected:
  inline explicit TorqueGeneratedThinString(Address ptr);
};

template <class D, class P>
class TorqueGeneratedTuple3 : public P {
  static_assert(std::is_same<Tuple3, D>::value,
    "Use this class as direct base for Tuple3.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedTuple3.");
 public: 
  using Super = P;
  inline Object value1() const;
  inline Object value1(const Isolate* isolate) const;
  inline void set_value1(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object value2() const;
  inline Object value2(const Isolate* isolate) const;
  inline void set_value2(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object value3() const;
  inline Object value3(const Isolate* isolate) const;
  inline void set_value3(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(Tuple3)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void Tuple3Verify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kValue1Offset = P::kHeaderSize;
  static constexpr int kValue1OffsetEnd = kValue1Offset + kTaggedSize - 1;
  static constexpr int kValue2Offset = kValue1OffsetEnd + 1;
  static constexpr int kValue2OffsetEnd = kValue2Offset + kTaggedSize - 1;
  static constexpr int kValue3Offset = kValue2OffsetEnd + 1;
  static constexpr int kValue3OffsetEnd = kValue3Offset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kValue3OffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kValue3OffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValue3OffsetEnd + 1;
  static constexpr int kHeaderSize = kValue3OffsetEnd + 1;
  static constexpr int kSize = kValue3OffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedTuple3() : P() {
    static_assert(std::is_base_of<TorqueGeneratedTuple3, 
      DAlias>::value,
      "class TorqueGeneratedTuple3 should be used as direct base for Tuple3.");
  }
protected:
  inline explicit TorqueGeneratedTuple3(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSyntheticModule : public P {
  static_assert(std::is_same<SyntheticModule, D>::value,
    "Use this class as direct base for SyntheticModule.");
  static_assert(std::is_same<Module, P>::value,
    "Pass in Module as second template parameter for TorqueGeneratedSyntheticModule.");
 public: 
  using Super = P;
  inline String name() const;
  inline String name(const Isolate* isolate) const;
  inline void set_name(String value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray export_names() const;
  inline FixedArray export_names(const Isolate* isolate) const;
  inline void set_export_names(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Foreign evaluation_steps() const;
  inline Foreign evaluation_steps(const Isolate* isolate) const;
  inline void set_evaluation_steps(Foreign value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SyntheticModuleVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kNameOffset = P::kHeaderSize;
  static constexpr int kNameOffsetEnd = kNameOffset + kTaggedSize - 1;
  static constexpr int kExportNamesOffset = kNameOffsetEnd + 1;
  static constexpr int kExportNamesOffsetEnd = kExportNamesOffset + kTaggedSize - 1;
  static constexpr int kEvaluationStepsOffset = kExportNamesOffsetEnd + 1;
  static constexpr int kEvaluationStepsOffsetEnd = kEvaluationStepsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kEvaluationStepsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kEvaluationStepsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kEvaluationStepsOffsetEnd + 1;
  static constexpr int kHeaderSize = kEvaluationStepsOffsetEnd + 1;
  static constexpr int kSize = kEvaluationStepsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSyntheticModule() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSyntheticModule, 
      DAlias>::value,
      "class TorqueGeneratedSyntheticModule should be used as direct base for SyntheticModule.");
  }
protected:
  inline explicit TorqueGeneratedSyntheticModule(Address ptr);
};

template <class D, class P>
class TorqueGeneratedTemplateObjectDescription : public P {
  static_assert(std::is_same<TemplateObjectDescription, D>::value,
    "Use this class as direct base for TemplateObjectDescription.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedTemplateObjectDescription.");
 public: 
  using Super = P;
  inline FixedArray raw_strings() const;
  inline FixedArray raw_strings(const Isolate* isolate) const;
  inline void set_raw_strings(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray cooked_strings() const;
  inline FixedArray cooked_strings(const Isolate* isolate) const;
  inline void set_cooked_strings(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(TemplateObjectDescription)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void TemplateObjectDescriptionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kRawStringsOffset = P::kHeaderSize;
  static constexpr int kRawStringsOffsetEnd = kRawStringsOffset + kTaggedSize - 1;
  static constexpr int kCookedStringsOffset = kRawStringsOffsetEnd + 1;
  static constexpr int kCookedStringsOffsetEnd = kCookedStringsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCookedStringsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCookedStringsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCookedStringsOffsetEnd + 1;
  static constexpr int kHeaderSize = kCookedStringsOffsetEnd + 1;
  static constexpr int kSize = kCookedStringsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedTemplateObjectDescription() : P() {
    static_assert(std::is_base_of<TorqueGeneratedTemplateObjectDescription, 
      DAlias>::value,
      "class TorqueGeneratedTemplateObjectDescription should be used as direct base for TemplateObjectDescription.");
  }
protected:
  inline explicit TorqueGeneratedTemplateObjectDescription(Address ptr);
};

template <class D, class P>
class TorqueGeneratedTemplateInfo : public P {
  static_assert(std::is_same<TemplateInfo, D>::value,
    "Use this class as direct base for TemplateInfo.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedTemplateInfo.");
 public: 
  using Super = P;
  inline Object tag() const;
  inline Object tag(const Isolate* isolate) const;
  inline void set_tag(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object serial_number() const;
  inline Object serial_number(const Isolate* isolate) const;
  inline void set_serial_number(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi number_of_properties() const;
  inline void set_number_of_properties(Smi value);

  inline Object property_list() const;
  inline Object property_list(const Isolate* isolate) const;
  inline void set_property_list(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object property_accessors() const;
  inline Object property_accessors(const Isolate* isolate) const;
  inline void set_property_accessors(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void TemplateInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kTagOffset = P::kHeaderSize;
  static constexpr int kTagOffsetEnd = kTagOffset + kTaggedSize - 1;
  static constexpr int kSerialNumberOffset = kTagOffsetEnd + 1;
  static constexpr int kSerialNumberOffsetEnd = kSerialNumberOffset + kTaggedSize - 1;
  static constexpr int kNumberOfPropertiesOffset = kSerialNumberOffsetEnd + 1;
  static constexpr int kNumberOfPropertiesOffsetEnd = kNumberOfPropertiesOffset + kTaggedSize - 1;
  static constexpr int kPropertyListOffset = kNumberOfPropertiesOffsetEnd + 1;
  static constexpr int kPropertyListOffsetEnd = kPropertyListOffset + kTaggedSize - 1;
  static constexpr int kPropertyAccessorsOffset = kPropertyListOffsetEnd + 1;
  static constexpr int kPropertyAccessorsOffsetEnd = kPropertyAccessorsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPropertyAccessorsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kPropertyAccessorsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPropertyAccessorsOffsetEnd + 1;
  static constexpr int kHeaderSize = kPropertyAccessorsOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedTemplateInfo() : P() {
    static_assert(std::is_base_of<TorqueGeneratedTemplateInfo, 
      DAlias>::value,
      "class TorqueGeneratedTemplateInfo should be used as direct base for TemplateInfo.");
  }
protected:
  inline explicit TorqueGeneratedTemplateInfo(Address ptr);
};

template <class D, class P>
class TorqueGeneratedFunctionTemplateRareData : public P {
  static_assert(std::is_same<FunctionTemplateRareData, D>::value,
    "Use this class as direct base for FunctionTemplateRareData.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedFunctionTemplateRareData.");
 public: 
  using Super = P;
  inline Object prototype_template() const;
  inline Object prototype_template(const Isolate* isolate) const;
  inline void set_prototype_template(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object prototype_provider_template() const;
  inline Object prototype_provider_template(const Isolate* isolate) const;
  inline void set_prototype_provider_template(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object parent_template() const;
  inline Object parent_template(const Isolate* isolate) const;
  inline void set_parent_template(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object named_property_handler() const;
  inline Object named_property_handler(const Isolate* isolate) const;
  inline void set_named_property_handler(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object indexed_property_handler() const;
  inline Object indexed_property_handler(const Isolate* isolate) const;
  inline void set_indexed_property_handler(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object instance_template() const;
  inline Object instance_template(const Isolate* isolate) const;
  inline void set_instance_template(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object instance_call_handler() const;
  inline Object instance_call_handler(const Isolate* isolate) const;
  inline void set_instance_call_handler(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object access_check_info() const;
  inline Object access_check_info(const Isolate* isolate) const;
  inline void set_access_check_info(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void FunctionTemplateRareDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kPrototypeTemplateOffset = P::kHeaderSize;
  static constexpr int kPrototypeTemplateOffsetEnd = kPrototypeTemplateOffset + kTaggedSize - 1;
  static constexpr int kPrototypeProviderTemplateOffset = kPrototypeTemplateOffsetEnd + 1;
  static constexpr int kPrototypeProviderTemplateOffsetEnd = kPrototypeProviderTemplateOffset + kTaggedSize - 1;
  static constexpr int kParentTemplateOffset = kPrototypeProviderTemplateOffsetEnd + 1;
  static constexpr int kParentTemplateOffsetEnd = kParentTemplateOffset + kTaggedSize - 1;
  static constexpr int kNamedPropertyHandlerOffset = kParentTemplateOffsetEnd + 1;
  static constexpr int kNamedPropertyHandlerOffsetEnd = kNamedPropertyHandlerOffset + kTaggedSize - 1;
  static constexpr int kIndexedPropertyHandlerOffset = kNamedPropertyHandlerOffsetEnd + 1;
  static constexpr int kIndexedPropertyHandlerOffsetEnd = kIndexedPropertyHandlerOffset + kTaggedSize - 1;
  static constexpr int kInstanceTemplateOffset = kIndexedPropertyHandlerOffsetEnd + 1;
  static constexpr int kInstanceTemplateOffsetEnd = kInstanceTemplateOffset + kTaggedSize - 1;
  static constexpr int kInstanceCallHandlerOffset = kInstanceTemplateOffsetEnd + 1;
  static constexpr int kInstanceCallHandlerOffsetEnd = kInstanceCallHandlerOffset + kTaggedSize - 1;
  static constexpr int kAccessCheckInfoOffset = kInstanceCallHandlerOffsetEnd + 1;
  static constexpr int kAccessCheckInfoOffsetEnd = kAccessCheckInfoOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kAccessCheckInfoOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kAccessCheckInfoOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kAccessCheckInfoOffsetEnd + 1;
  static constexpr int kHeaderSize = kAccessCheckInfoOffsetEnd + 1;
  static constexpr int kSize = kAccessCheckInfoOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedFunctionTemplateRareData() : P() {
    static_assert(std::is_base_of<TorqueGeneratedFunctionTemplateRareData, 
      DAlias>::value,
      "class TorqueGeneratedFunctionTemplateRareData should be used as direct base for FunctionTemplateRareData.");
  }
protected:
  inline explicit TorqueGeneratedFunctionTemplateRareData(Address ptr);
};

template <class D, class P>
class TorqueGeneratedFunctionTemplateInfo : public P {
  static_assert(std::is_same<FunctionTemplateInfo, D>::value,
    "Use this class as direct base for FunctionTemplateInfo.");
  static_assert(std::is_same<TemplateInfo, P>::value,
    "Pass in TemplateInfo as second template parameter for TorqueGeneratedFunctionTemplateInfo.");
 public: 
  using Super = P;
  inline Object call_code() const;
  inline Object call_code(const Isolate* isolate) const;
  inline void set_call_code(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object class_name() const;
  inline Object class_name(const Isolate* isolate) const;
  inline void set_class_name(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object signature() const;
  inline Object signature(const Isolate* isolate) const;
  inline void set_signature(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject rare_data() const;
  inline HeapObject rare_data(const Isolate* isolate) const;
  inline void set_rare_data(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object shared_function_info() const;
  inline Object shared_function_info(const Isolate* isolate) const;
  inline void set_shared_function_info(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi flag() const;
  inline void set_flag(Smi value);

  inline Smi length() const;
  inline void set_length(Smi value);

  inline Object cached_property_name() const;
  inline Object cached_property_name(const Isolate* isolate) const;
  inline void set_cached_property_name(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void FunctionTemplateInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kCallCodeOffset = P::kHeaderSize;
  static constexpr int kCallCodeOffsetEnd = kCallCodeOffset + kTaggedSize - 1;
  static constexpr int kClassNameOffset = kCallCodeOffsetEnd + 1;
  static constexpr int kClassNameOffsetEnd = kClassNameOffset + kTaggedSize - 1;
  static constexpr int kSignatureOffset = kClassNameOffsetEnd + 1;
  static constexpr int kSignatureOffsetEnd = kSignatureOffset + kTaggedSize - 1;
  static constexpr int kRareDataOffset = kSignatureOffsetEnd + 1;
  static constexpr int kRareDataOffsetEnd = kRareDataOffset + kTaggedSize - 1;
  static constexpr int kSharedFunctionInfoOffset = kRareDataOffsetEnd + 1;
  static constexpr int kSharedFunctionInfoOffsetEnd = kSharedFunctionInfoOffset + kTaggedSize - 1;
  static constexpr int kFlagOffset = kSharedFunctionInfoOffsetEnd + 1;
  static constexpr int kFlagOffsetEnd = kFlagOffset + kTaggedSize - 1;
  static constexpr int kLengthOffset = kFlagOffsetEnd + 1;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kCachedPropertyNameOffset = kLengthOffsetEnd + 1;
  static constexpr int kCachedPropertyNameOffsetEnd = kCachedPropertyNameOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCachedPropertyNameOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCachedPropertyNameOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCachedPropertyNameOffsetEnd + 1;
  static constexpr int kHeaderSize = kCachedPropertyNameOffsetEnd + 1;
  static constexpr int kSize = kCachedPropertyNameOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedFunctionTemplateInfo() : P() {
    static_assert(std::is_base_of<TorqueGeneratedFunctionTemplateInfo, 
      DAlias>::value,
      "class TorqueGeneratedFunctionTemplateInfo should be used as direct base for FunctionTemplateInfo.");
  }
protected:
  inline explicit TorqueGeneratedFunctionTemplateInfo(Address ptr);
};

template <class D, class P>
class TorqueGeneratedObjectTemplateInfo : public P {
  static_assert(std::is_same<ObjectTemplateInfo, D>::value,
    "Use this class as direct base for ObjectTemplateInfo.");
  static_assert(std::is_same<TemplateInfo, P>::value,
    "Pass in TemplateInfo as second template parameter for TorqueGeneratedObjectTemplateInfo.");
 public: 
  using Super = P;
  inline Object constructor() const;
  inline Object constructor(const Isolate* isolate) const;
  inline void set_constructor(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Object data() const;
  inline Object data(const Isolate* isolate) const;
  inline void set_data(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void ObjectTemplateInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kConstructorOffset = P::kHeaderSize;
  static constexpr int kConstructorOffsetEnd = kConstructorOffset + kTaggedSize - 1;
  static constexpr int kDataOffset = kConstructorOffsetEnd + 1;
  static constexpr int kDataOffsetEnd = kDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kDataOffsetEnd + 1;
  static constexpr int kSize = kDataOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedObjectTemplateInfo() : P() {
    static_assert(std::is_base_of<TorqueGeneratedObjectTemplateInfo, 
      DAlias>::value,
      "class TorqueGeneratedObjectTemplateInfo should be used as direct base for ObjectTemplateInfo.");
  }
protected:
  inline explicit TorqueGeneratedObjectTemplateInfo(Address ptr);
};

template <class D, class P>
class TorqueGeneratedWasmExceptionTag : public P {
  static_assert(std::is_same<WasmExceptionTag, D>::value,
    "Use this class as direct base for WasmExceptionTag.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedWasmExceptionTag.");
 public: 
  using Super = P;
  inline Smi index() const;
  inline void set_index(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void WasmExceptionTagVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kIndexOffset = P::kHeaderSize;
  static constexpr int kIndexOffsetEnd = kIndexOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kHeaderSize = kIndexOffsetEnd + 1;
  static constexpr int kSize = kIndexOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedWasmExceptionTag() : P() {
    static_assert(std::is_base_of<TorqueGeneratedWasmExceptionTag, 
      DAlias>::value,
      "class TorqueGeneratedWasmExceptionTag should be used as direct base for WasmExceptionTag.");
  }
protected:
  inline explicit TorqueGeneratedWasmExceptionTag(Address ptr);
};

template <class D, class P>
class TorqueGeneratedInternalClass : public P {
  static_assert(std::is_same<InternalClass, D>::value,
    "Use this class as direct base for InternalClass.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedInternalClass.");
 public: 
  using Super = P;
  inline Smi a() const;
  inline void set_a(Smi value);

  // Torque type: Number
  inline Object b() const;
  inline Object b(const Isolate* isolate) const;
  inline void set_b(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(InternalClass)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void InternalClassVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kAOffset = P::kHeaderSize;
  static constexpr int kAOffsetEnd = kAOffset + kTaggedSize - 1;
  static constexpr int kBOffset = kAOffsetEnd + 1;
  static constexpr int kBOffsetEnd = kBOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kHeaderSize = kBOffsetEnd + 1;
  static constexpr int kSize = kBOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedInternalClass() : P() {
    static_assert(std::is_base_of<TorqueGeneratedInternalClass, 
      DAlias>::value,
      "class TorqueGeneratedInternalClass should be used as direct base for InternalClass.");
  }
protected:
  inline explicit TorqueGeneratedInternalClass(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSmiPair : public P {
  static_assert(std::is_same<SmiPair, D>::value,
    "Use this class as direct base for SmiPair.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedSmiPair.");
 public: 
  using Super = P;
  inline Smi a() const;
  inline void set_a(Smi value);

  inline Smi b() const;
  inline void set_b(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(SmiPair)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SmiPairVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kAOffset = P::kHeaderSize;
  static constexpr int kAOffsetEnd = kAOffset + kTaggedSize - 1;
  static constexpr int kBOffset = kAOffsetEnd + 1;
  static constexpr int kBOffsetEnd = kBOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBOffsetEnd + 1;
  static constexpr int kHeaderSize = kBOffsetEnd + 1;
  static constexpr int kSize = kBOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSmiPair() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSmiPair, 
      DAlias>::value,
      "class TorqueGeneratedSmiPair should be used as direct base for SmiPair.");
  }
protected:
  inline explicit TorqueGeneratedSmiPair(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSmiBox : public P {
  static_assert(std::is_same<SmiBox, D>::value,
    "Use this class as direct base for SmiBox.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedSmiBox.");
 public: 
  using Super = P;
  inline Smi value() const;
  inline void set_value(Smi value);

  inline Smi unrelated() const;
  inline void set_unrelated(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(SmiBox)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SmiBoxVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kValueOffset = P::kHeaderSize;
  static constexpr int kValueOffsetEnd = kValueOffset + kTaggedSize - 1;
  static constexpr int kUnrelatedOffset = kValueOffsetEnd + 1;
  static constexpr int kUnrelatedOffsetEnd = kUnrelatedOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kUnrelatedOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kUnrelatedOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kUnrelatedOffsetEnd + 1;
  static constexpr int kHeaderSize = kUnrelatedOffsetEnd + 1;
  static constexpr int kSize = kUnrelatedOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSmiBox() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSmiBox, 
      DAlias>::value,
      "class TorqueGeneratedSmiBox should be used as direct base for SmiBox.");
  }
protected:
  inline explicit TorqueGeneratedSmiBox(Address ptr);
};

template <class D, class P>
class TorqueGeneratedSortState : public P {
  static_assert(std::is_same<SortState, D>::value,
    "Use this class as direct base for SortState.");
  static_assert(std::is_same<Struct, P>::value,
    "Pass in Struct as second template parameter for TorqueGeneratedSortState.");
 public: 
  using Super = P;
  inline JSReceiver receiver() const;
  inline JSReceiver receiver(const Isolate* isolate) const;
  inline void set_receiver(JSReceiver value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Map initialReceiverMap() const;
  inline Map initialReceiverMap(const Isolate* isolate) const;
  inline void set_initialReceiverMap(Map value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: Number
  inline Object initialReceiverLength() const;
  inline Object initialReceiverLength(const Isolate* isolate) const;
  inline void set_initialReceiverLength(Object value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline HeapObject userCmpFn() const;
  inline HeapObject userCmpFn(const Isolate* isolate) const;
  inline void set_userCmpFn(HeapObject value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi sortComparePtr() const;
  inline void set_sortComparePtr(Smi value);

  inline Smi loadFn() const;
  inline void set_loadFn(Smi value);

  inline Smi storeFn() const;
  inline void set_storeFn(Smi value);

  inline Smi deleteFn() const;
  inline void set_deleteFn(Smi value);

  inline Smi canUseSameAccessorFn() const;
  inline void set_canUseSameAccessorFn(Smi value);

  inline Smi minGallop() const;
  inline void set_minGallop(Smi value);

  inline Smi pendingRunsSize() const;
  inline void set_pendingRunsSize(Smi value);

  inline FixedArray pendingRuns() const;
  inline FixedArray pendingRuns(const Isolate* isolate) const;
  inline void set_pendingRuns(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray workArray() const;
  inline FixedArray workArray(const Isolate* isolate) const;
  inline void set_workArray(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline FixedArray tempArray() const;
  inline FixedArray tempArray(const Isolate* isolate) const;
  inline void set_tempArray(FixedArray value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  inline Smi sortLength() const;
  inline void set_sortLength(Smi value);

  inline Smi numberOfUndefined() const;
  inline void set_numberOfUndefined(Smi value);

  V8_INLINE static D cast(Object object) {
    return D(object.ptr());
  }
  V8_INLINE static D unchecked_cast(Object object) {
    return bit_cast<D>(object);
  }

  DECL_PRINTER(SortState)
#ifdef VERIFY_HEAP
  V8_EXPORT_PRIVATE void SortStateVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kReceiverOffset = P::kHeaderSize;
  static constexpr int kReceiverOffsetEnd = kReceiverOffset + kTaggedSize - 1;
  static constexpr int kInitialReceiverMapOffset = kReceiverOffsetEnd + 1;
  static constexpr int kInitialReceiverMapOffsetEnd = kInitialReceiverMapOffset + kTaggedSize - 1;
  static constexpr int kInitialReceiverLengthOffset = kInitialReceiverMapOffsetEnd + 1;
  static constexpr int kInitialReceiverLengthOffsetEnd = kInitialReceiverLengthOffset + kTaggedSize - 1;
  static constexpr int kUserCmpFnOffset = kInitialReceiverLengthOffsetEnd + 1;
  static constexpr int kUserCmpFnOffsetEnd = kUserCmpFnOffset + kTaggedSize - 1;
  static constexpr int kSortComparePtrOffset = kUserCmpFnOffsetEnd + 1;
  static constexpr int kSortComparePtrOffsetEnd = kSortComparePtrOffset + kTaggedSize - 1;
  static constexpr int kLoadFnOffset = kSortComparePtrOffsetEnd + 1;
  static constexpr int kLoadFnOffsetEnd = kLoadFnOffset + kTaggedSize - 1;
  static constexpr int kStoreFnOffset = kLoadFnOffsetEnd + 1;
  static constexpr int kStoreFnOffsetEnd = kStoreFnOffset + kTaggedSize - 1;
  static constexpr int kDeleteFnOffset = kStoreFnOffsetEnd + 1;
  static constexpr int kDeleteFnOffsetEnd = kDeleteFnOffset + kTaggedSize - 1;
  static constexpr int kCanUseSameAccessorFnOffset = kDeleteFnOffsetEnd + 1;
  static constexpr int kCanUseSameAccessorFnOffsetEnd = kCanUseSameAccessorFnOffset + kTaggedSize - 1;
  static constexpr int kMinGallopOffset = kCanUseSameAccessorFnOffsetEnd + 1;
  static constexpr int kMinGallopOffsetEnd = kMinGallopOffset + kTaggedSize - 1;
  static constexpr int kPendingRunsSizeOffset = kMinGallopOffsetEnd + 1;
  static constexpr int kPendingRunsSizeOffsetEnd = kPendingRunsSizeOffset + kTaggedSize - 1;
  static constexpr int kPendingRunsOffset = kPendingRunsSizeOffsetEnd + 1;
  static constexpr int kPendingRunsOffsetEnd = kPendingRunsOffset + kTaggedSize - 1;
  static constexpr int kWorkArrayOffset = kPendingRunsOffsetEnd + 1;
  static constexpr int kWorkArrayOffsetEnd = kWorkArrayOffset + kTaggedSize - 1;
  static constexpr int kTempArrayOffset = kWorkArrayOffsetEnd + 1;
  static constexpr int kTempArrayOffsetEnd = kTempArrayOffset + kTaggedSize - 1;
  static constexpr int kSortLengthOffset = kTempArrayOffsetEnd + 1;
  static constexpr int kSortLengthOffsetEnd = kSortLengthOffset + kTaggedSize - 1;
  static constexpr int kNumberOfUndefinedOffset = kSortLengthOffsetEnd + 1;
  static constexpr int kNumberOfUndefinedOffsetEnd = kNumberOfUndefinedOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kNumberOfUndefinedOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kNumberOfUndefinedOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kNumberOfUndefinedOffsetEnd + 1;
  static constexpr int kHeaderSize = kNumberOfUndefinedOffsetEnd + 1;
  static constexpr int kSize = kNumberOfUndefinedOffsetEnd + 1;

 public:
  template <class DAlias = D>
  constexpr TorqueGeneratedSortState() : P() {
    static_assert(std::is_base_of<TorqueGeneratedSortState, 
      DAlias>::value,
      "class TorqueGeneratedSortState should be used as direct base for SortState.");
  }
protected:
  inline explicit TorqueGeneratedSortState(Address ptr);
};

}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"
#endif  // V8_GEN_TORQUE_GENERATED_CLASS_DEFINITIONS_TQ_H_
