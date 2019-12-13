#ifndef V8_GEN_TORQUE_GENERATED_CSA_TYPES_TQ_H_
#define V8_GEN_TORQUE_GENERATED_CSA_TYPES_TQ_H_

#include "src/compiler/code-assembler.h"

namespace v8 {
namespace internal {
struct TorqueStructBuffer_0 {
  TNode<FixedArray> fixedArray;
  TNode<IntPtrT> index;
  TNode<IntPtrT> totalStringLength;
  TNode<BoolT> isOneByte;

  std::tuple<TNode<FixedArray>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<BoolT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(fixedArray), std::make_tuple(index), std::make_tuple(totalStringLength), std::make_tuple(isOneByte));
  }
};
struct TorqueStructVector_0 {
  TNode<FixedArray> fixedArray;
  TNode<BoolT> onlySmis;
  TNode<BoolT> onlyNumbers;
  TNode<BoolT> skippedElements;

  std::tuple<TNode<FixedArray>, TNode<BoolT>, TNode<BoolT>, TNode<BoolT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(fixedArray), std::make_tuple(onlySmis), std::make_tuple(onlyNumbers), std::make_tuple(skippedElements));
  }
};
struct TorqueStructKeyValuePair {
  TNode<Object> key;
  TNode<Object> value;

  std::tuple<TNode<Object>, TNode<Object>> Flatten() const {
    return std::tuple_cat(std::make_tuple(key), std::make_tuple(value));
  }
};
struct TorqueStructArguments {
  TNode<RawPtrT> frame;
  TNode<RawPtrT> base;
  TNode<IntPtrT> length;

  std::tuple<TNode<RawPtrT>, TNode<RawPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(frame), std::make_tuple(base), std::make_tuple(length));
  }
};
struct TorqueStructArgumentsInfo {
  TNode<RawPtrT> frame;
  TNode<BInt> argument_count;
  TNode<BInt> formal_parameter_count;

  std::tuple<TNode<RawPtrT>, TNode<BInt>, TNode<BInt>> Flatten() const {
    return std::tuple_cat(std::make_tuple(frame), std::make_tuple(argument_count), std::make_tuple(formal_parameter_count));
  }
};
struct TorqueStructGrowableFixedArray_0 {
  TNode<FixedArray> array;
  TNode<IntPtrT> capacity;
  TNode<IntPtrT> length;

  std::tuple<TNode<FixedArray>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(array), std::make_tuple(capacity), std::make_tuple(length));
  }
};
struct TorqueStructIteratorRecord {
  TNode<JSReceiver> object;
  TNode<Object> next;

  std::tuple<TNode<JSReceiver>, TNode<Object>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(next));
  }
};
struct TorqueStructPromiseResolvingFunctions {
  TNode<JSFunction> resolve;
  TNode<JSFunction> reject;

  std::tuple<TNode<JSFunction>, TNode<JSFunction>> Flatten() const {
    return std::tuple_cat(std::make_tuple(resolve), std::make_tuple(reject));
  }
};
struct TorqueStructUnsafe_0 {

  std::tuple<> Flatten() const {
    return std::tuple_cat();
  }
};
struct TorqueStructTypedArrayElementsInfo {
  TNode<UintPtrT> sizeLog2;
  TNode<Int32T> kind;

  std::tuple<TNode<UintPtrT>, TNode<Int32T>> Flatten() const {
    return std::tuple_cat(std::make_tuple(sizeLog2), std::make_tuple(kind));
  }
};
struct TorqueStructTypedArrayAccessor_0 {
  TNode<BuiltinPtr> loadNumericFn;
  TNode<BuiltinPtr> storeNumericFn;
  TNode<BuiltinPtr> storeJSAnyFn;

  std::tuple<TNode<BuiltinPtr>, TNode<BuiltinPtr>, TNode<BuiltinPtr>> Flatten() const {
    return std::tuple_cat(std::make_tuple(loadNumericFn), std::make_tuple(storeNumericFn), std::make_tuple(storeJSAnyFn));
  }
};
struct TorqueStructAttachedJSTypedArrayWitness_0 {
  TNode<JSTypedArray> stable;
  TNode<JSTypedArray> unstable;
  TNode<BuiltinPtr> loadfn;

  std::tuple<TNode<JSTypedArray>, TNode<JSTypedArray>, TNode<BuiltinPtr>> Flatten() const {
    return std::tuple_cat(std::make_tuple(stable), std::make_tuple(unstable), std::make_tuple(loadfn));
  }
};
struct TorqueStructDescriptorEntry {
  TNode<PrimitiveHeapObject> key;
  TNode<Object> details;
  TNode<MaybeObject> value;

  std::tuple<TNode<PrimitiveHeapObject>, TNode<Object>, TNode<MaybeObject>> Flatten() const {
    return std::tuple_cat(std::make_tuple(key), std::make_tuple(details), std::make_tuple(value));
  }
};
struct TorqueStructFastJSArrayWitness_0 {
  TNode<JSArray> stable;
  TNode<JSArray> unstable;
  TNode<Map> map;
  TNode<BoolT> hasDoubles;
  TNode<BoolT> hasSmis;
  TNode<BoolT> arrayIsPushable;

  std::tuple<TNode<JSArray>, TNode<JSArray>, TNode<Map>, TNode<BoolT>, TNode<BoolT>, TNode<BoolT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(stable), std::make_tuple(unstable), std::make_tuple(map), std::make_tuple(hasDoubles), std::make_tuple(hasSmis), std::make_tuple(arrayIsPushable));
  }
};
struct TorqueStructFastJSArrayForReadWitness_0 {
  TNode<JSArray> stable;
  TNode<JSArray> unstable;
  TNode<Map> map;
  TNode<BoolT> hasDoubles;

  std::tuple<TNode<JSArray>, TNode<JSArray>, TNode<Map>, TNode<BoolT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(stable), std::make_tuple(unstable), std::make_tuple(map), std::make_tuple(hasDoubles));
  }
};
struct TorqueStructTestStructA_0 {
  TNode<FixedArray> indexes;
  TNode<Smi> i;
  TNode<Number> k;

  std::tuple<TNode<FixedArray>, TNode<Smi>, TNode<Number>> Flatten() const {
    return std::tuple_cat(std::make_tuple(indexes), std::make_tuple(i), std::make_tuple(k));
  }
};
struct TorqueStructTestStructB_0 {
  TorqueStructTestStructA_0 x;
  TNode<Smi> y;

  std::tuple<TNode<FixedArray>, TNode<Smi>, TNode<Number>, TNode<Smi>> Flatten() const {
    return std::tuple_cat(x.Flatten(), std::make_tuple(y));
  }
};
struct TorqueStructTestStructC_0 {
  TorqueStructTestStructA_0 x;
  TorqueStructTestStructA_0 y;

  std::tuple<TNode<FixedArray>, TNode<Smi>, TNode<Number>, TNode<FixedArray>, TNode<Smi>, TNode<Number>> Flatten() const {
    return std::tuple_cat(x.Flatten(), y.Flatten());
  }
};
struct TorqueStructTestInner_0 {
  TNode<Int32T> x;
  TNode<Int32T> y;

  std::tuple<TNode<Int32T>, TNode<Int32T>> Flatten() const {
    return std::tuple_cat(std::make_tuple(x), std::make_tuple(y));
  }
};
struct TorqueStructTestOuter_0 {
  TNode<Int32T> a;
  TorqueStructTestInner_0 b;
  TNode<Int32T> c;

  std::tuple<TNode<Int32T>, TNode<Int32T>, TNode<Int32T>, TNode<Int32T>> Flatten() const {
    return std::tuple_cat(std::make_tuple(a), b.Flatten(), std::make_tuple(c));
  }
};
struct TorqueStructStructWithConst_0 {
  TNode<Object> a;
  TNode<Int32T> b;

  std::tuple<TNode<Object>, TNode<Int32T>> Flatten() const {
    return std::tuple_cat(std::make_tuple(a), std::make_tuple(b));
  }
};
struct TorqueStructTestIterator_0 {
  TNode<Smi> count;

  std::tuple<TNode<Smi>> Flatten() const {
    return std::tuple_cat(std::make_tuple(count));
  }
};
struct TorqueStructTestTuple_intptr_Smi_0 {
  TNode<IntPtrT> fst;
  TNode<Smi> snd;

  std::tuple<TNode<IntPtrT>, TNode<Smi>> Flatten() const {
    return std::tuple_cat(std::make_tuple(fst), std::make_tuple(snd));
  }
};
struct TorqueStructTestTuple_Smi_intptr_0 {
  TNode<Smi> fst;
  TNode<IntPtrT> snd;

  std::tuple<TNode<Smi>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(fst), std::make_tuple(snd));
  }
};
struct TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0 {
  TorqueStructTestTuple_intptr_Smi_0 fst;
  TorqueStructTestTuple_Smi_intptr_0 snd;

  std::tuple<TNode<IntPtrT>, TNode<Smi>, TNode<Smi>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(fst.Flatten(), snd.Flatten());
  }
};
struct TorqueStructReference_Smi_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Map_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_FixedArrayBase_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructSlice_Object_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), std::make_tuple(length), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Object_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructSliceIterator_Object_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(start), std::make_tuple(end), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Number_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSArrayBuffer_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_uintptr_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructSlice_float64_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), std::make_tuple(length), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_float64_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructSliceIterator_float64_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(start), std::make_tuple(end), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_DescriptorArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_DescriptorEntry_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_uint16_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructSlice_DescriptorEntry_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), std::make_tuple(length), unsafeMarker.Flatten());
  }
};
struct TorqueStructSliceIterator_DescriptorEntry_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(start), std::make_tuple(end), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Name_OR_Undefined_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_Undefined_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSAny_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_String_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_RawPtr_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_SharedFunctionInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_DebugInfo_OR_Script_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_CoverageInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSReceiver_OR_Map_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSReceiver_OR_Null_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_Weak_Map_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Callable_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Context_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_CallableApiObject_OR_CallableJSProxy_OR_JSFunction_OR_JSBoundFunction_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Zero_OR_PromiseReaction_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_PromiseReaction_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_String_OR_Undefined_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSReceiver_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_FixedArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_FixedArrayBase_OR_PropertyArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructSBox_intptr_0 {
  TNode<IntPtrT> value;

  std::tuple<TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(value));
  }
};
struct TorqueStructSBox_SBox_intptr_0 {
  TorqueStructSBox_intptr_0 value;

  std::tuple<TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(value.Flatten());
  }
};
struct TorqueStructReference_CompareBuiltinFn_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_LoadFn_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_StoreFn_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_DeleteFn_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_CanUseSameAccessorFn_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_FixedArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_ScopeInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_uint32_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_int32_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_FeedbackCell_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Code_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_SourceTextModule_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_uint8_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_InstanceType_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_DependentCode_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_Cell_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_TransitionArray_OR_Map_OR_Weak_Map_OR_PrototypeInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_ByteArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_Code_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_MaybeObject_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_AllocationSite_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_Zero_OR_NonNullForeign_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_Zero_OR_Foreign_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_Zero_OR_InterceptorInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Zero_OR_NonNullForeign_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_ByteArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_ByteArray_OR_SourcePositionTableWithFrameCache_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_int8_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_Script_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_BytecodeArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_EnumCache_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_FixedArray_OR_FeedbackVector_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_Weak_Code_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Uninitialized_OR_FreeSpace_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Foreign_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_JSFunction_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSFunction_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSPromise_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_HeapObject_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_AsyncGeneratorRequest_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_NativeContext_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSGlobalProxy_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Script_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_SharedFunctionInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_NumberOrUndefined_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_Undefined_OR_NaN_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSRegExp_OR_JSRegExpResultIndices_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_WeakCell_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_JSFinalizationGroup_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSFinalizationGroup_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_ObjectHashTable_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_JSModuleNamespace_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Module_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_JSPromise_OR_PromiseCapability_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_AnyName_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Zero_OR_WeakArrayList_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Smi_OR_Foreign_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_BytecodeArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_String_OR_NoSharedNameSentinel_OR_ScopeInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_int16_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_PreparseData_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSFunction_OR_JSGeneratorObject_OR_SharedFunctionInfo_OR_SourceTextModuleInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_JSObject_OR_TheHole_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_ArrayList_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_JSPromise_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_String_OR_Null_OR_Undefined_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Null_OR_Undefined_OR_WasmInstanceObject_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_FrameArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_StackFrameInfo_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_WasmInstanceObject_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_Foreign_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Cell_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_ByteArray_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_WeakArrayList_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_Undefined_OR_JSArrayBuffer_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
struct TorqueStructReference_HeapNumber_0 {
  TNode<HeapObject> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<HeapObject>, TNode<IntPtrT>> Flatten() const {
    return std::tuple_cat(std::make_tuple(object), std::make_tuple(offset), unsafeMarker.Flatten());
  }
};
}  // namespace internal
}  // namespace v8
#endif  // V8_GEN_TORQUE_GENERATED_CSA_TYPES_TQ_H_
