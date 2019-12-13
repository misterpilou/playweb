#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_CAST_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_CAST_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Oddball> Cast_Undefined_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Smi> Cast_Smi_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Smi> Cast_PositiveSmi_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Smi> Cast_Zero_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Number> Cast_Number_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_Undefined_1(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Numeric> Cast_Numeric_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_TheHole_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_True_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_True_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_False_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_False_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_Boolean_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_Boolean_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> Cast_JSPrimitive_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> Cast_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> Cast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> Cast_Smi_OR_HeapNumber_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<HeapObject> Cast_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label__CastError);
TNode<Oddball> Cast_Null_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_Undefined_2(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<FixedArray> Cast_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<FixedDoubleArray> Cast_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<FixedArray> Cast_SloppyArgumentsElements_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSDataView> Cast_JSDataView_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSProxy> Cast_JSProxy_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSStringIterator> Cast_JSStringIterator_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSRegExpStringIterator> Cast_JSRegExpStringIterator_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSTypedArray> Cast_JSTypedArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSTypedArray> Cast_JSTypedArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSReceiver> Cast_Callable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<HeapObject> Cast_Undefined_OR_CallableApiObject_OR_CallableJSProxy_OR_JSFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArray> Cast_JSArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArrayBuffer> Cast_JSArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Context> Cast_Context_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<NativeContext> Cast_NativeContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSObject> Cast_JSObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<NumberDictionary> Cast_NumberDictionary_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<String> Cast_String_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Oddball> Cast_Oddball_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Symbol> Cast_Symbol_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Symbol> Cast_PublicSymbol_0(compiler::CodeAssemblerState* state_, TNode<Symbol> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Symbol> Cast_PrivateSymbol_0(compiler::CodeAssemblerState* state_, TNode<Symbol> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Symbol> Cast_PublicSymbol_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Symbol> Cast_PrivateSymbol_1(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<String> Cast_DirectString_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSReceiver> Cast_Constructor_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSFunction> Cast_JSFunctionWithPrototypeSlot_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<HeapNumber> Cast_HeapNumber_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<BigInt> Cast_BigInt_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSRegExp> Cast_JSRegExp_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArray> Cast_JSRegExpResult_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Map> Cast_Map_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<FeedbackVector> Cast_FeedbackVector_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSPrimitiveWrapper> Cast_JSPrimitiveWrapper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArgumentsObject> Cast_JSSloppyArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArgumentsObject> Cast_JSStrictArgumentsObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArgumentsObject> Cast_JSArgumentsObjectWithLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSRegExp> Cast_FastJSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArray> Cast_FastJSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArray> Cast_FastJSArrayForRead_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArray> Cast_FastJSArrayForCopy_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArray> Cast_FastJSArrayWithNoCustomIteration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArray> Cast_FastJSArrayForReadWithNoCustomIteration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSReceiver> Cast_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSFunction> Cast_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<DebugInfo> Cast_DebugInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<FixedArray> Cast_CoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<HeapObject> Cast_JSReceiver_OR_Null_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<PromiseFulfillReactionJobTask> Cast_PromiseFulfillReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<PromiseRejectReactionJobTask> Cast_PromiseRejectReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<PromiseReaction> Cast_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> Cast_Smi_OR_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<HeapObject> Cast_String_OR_CallableApiObject_OR_CallableJSProxy_OR_JSFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> Cast_Zero_OR_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSBoundFunction> Cast_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<PromiseCapability> Cast_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<SharedFunctionInfo> Cast_SharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSPromise> Cast_JSPromise_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<RegExpMatchInfo> UnsafeCast_RegExpMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<HeapObject> Cast_HeapObject_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<PromiseReaction> Cast_PromiseReaction_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<BoolT> Is_FixedArray_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_CAST_TQ_H_
