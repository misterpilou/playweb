#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_OBJECTS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_OBJECTS_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<JSObject> NewJSObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<Map> GetDerivedMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_target, TNode<JSReceiver> p_newTarget);
TNode<JSObject> AllocateFastOrSlowJSObjectFromMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map);
TNode<Object> LoadJSReceiverPropertiesOrHash_0(compiler::CodeAssemblerState* state_, TNode<JSReceiver> p_o);
void StoreJSReceiverPropertiesOrHash_0(compiler::CodeAssemblerState* state_, TNode<JSReceiver> p_o, TNode<Object> p_v);
TNode<FixedArrayBase> LoadJSObjectElements_0(compiler::CodeAssemblerState* state_, TNode<JSObject> p_o);
void StoreJSObjectElements_0(compiler::CodeAssemblerState* state_, TNode<JSObject> p_o, TNode<FixedArrayBase> p_v);
TNode<SharedFunctionInfo> LoadJSFunctionSharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o);
void StoreJSFunctionSharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o, TNode<SharedFunctionInfo> p_v);
TNode<Context> LoadJSFunctionContext_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o);
void StoreJSFunctionContext_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o, TNode<Context> p_v);
TNode<FeedbackCell> LoadJSFunctionFeedbackCell_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o);
void StoreJSFunctionFeedbackCell_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o, TNode<FeedbackCell> p_v);
TNode<Code> LoadJSFunctionCode_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o);
void StoreJSFunctionCode_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o, TNode<Code> p_v);
TNode<HeapObject> LoadJSFunctionPrototypeOrInitialMap_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o);
void StoreJSFunctionPrototypeOrInitialMap_0(compiler::CodeAssemblerState* state_, TNode<JSFunction> p_o, TNode<HeapObject> p_v);
TNode<JSReceiver> LoadJSBoundFunctionBoundTargetFunction_0(compiler::CodeAssemblerState* state_, TNode<JSBoundFunction> p_o);
void StoreJSBoundFunctionBoundTargetFunction_0(compiler::CodeAssemblerState* state_, TNode<JSBoundFunction> p_o, TNode<JSReceiver> p_v);
TNode<Object> LoadJSBoundFunctionBoundThis_0(compiler::CodeAssemblerState* state_, TNode<JSBoundFunction> p_o);
void StoreJSBoundFunctionBoundThis_0(compiler::CodeAssemblerState* state_, TNode<JSBoundFunction> p_o, TNode<Object> p_v);
TNode<FixedArray> LoadJSBoundFunctionBoundArguments_0(compiler::CodeAssemblerState* state_, TNode<JSBoundFunction> p_o);
void StoreJSBoundFunctionBoundArguments_0(compiler::CodeAssemblerState* state_, TNode<JSBoundFunction> p_o, TNode<FixedArray> p_v);
TNode<Object> LoadJSGlobalProxyNativeContext_0(compiler::CodeAssemblerState* state_, TNode<JSGlobalProxy> p_o);
void StoreJSGlobalProxyNativeContext_0(compiler::CodeAssemblerState* state_, TNode<JSGlobalProxy> p_o, TNode<Object> p_v);
TNode<NativeContext> LoadJSGlobalObjectNativeContext_0(compiler::CodeAssemblerState* state_, TNode<JSGlobalObject> p_o);
void StoreJSGlobalObjectNativeContext_0(compiler::CodeAssemblerState* state_, TNode<JSGlobalObject> p_o, TNode<NativeContext> p_v);
TNode<JSGlobalProxy> LoadJSGlobalObjectGlobalProxy_0(compiler::CodeAssemblerState* state_, TNode<JSGlobalObject> p_o);
void StoreJSGlobalObjectGlobalProxy_0(compiler::CodeAssemblerState* state_, TNode<JSGlobalObject> p_o, TNode<JSGlobalProxy> p_v);
TNode<Object> LoadJSPrimitiveWrapperValue_0(compiler::CodeAssemblerState* state_, TNode<JSPrimitiveWrapper> p_o);
void StoreJSPrimitiveWrapperValue_0(compiler::CodeAssemblerState* state_, TNode<JSPrimitiveWrapper> p_o, TNode<Object> p_v);
TNode<Smi> LoadJSMessageObjectMessageType_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectMessageType_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<Smi> p_v);
TNode<Object> LoadJSMessageObjectArguments_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectArguments_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<Object> p_v);
TNode<Script> LoadJSMessageObjectScript_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectScript_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<Script> p_v);
TNode<Object> LoadJSMessageObjectStackFrames_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectStackFrames_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<Object> p_v);
TNode<HeapObject> LoadJSMessageObjectSharedInfo_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectSharedInfo_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadJSMessageObjectBytecodeOffset_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectBytecodeOffset_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<Smi> p_v);
TNode<Smi> LoadJSMessageObjectStartPosition_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectStartPosition_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<Smi> p_v);
TNode<Smi> LoadJSMessageObjectEndPosition_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectEndPosition_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<Smi> p_v);
TNode<Smi> LoadJSMessageObjectErrorLevel_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o);
void StoreJSMessageObjectErrorLevel_0(compiler::CodeAssemblerState* state_, TNode<JSMessageObject> p_o, TNode<Smi> p_v);
TNode<Object> LoadJSDateValue_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateValue_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<Object> LoadJSDateYear_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateYear_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<Object> LoadJSDateMonth_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateMonth_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<Object> LoadJSDateDay_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateDay_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<Object> LoadJSDateWeekday_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateWeekday_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<Object> LoadJSDateHour_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateHour_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<Object> LoadJSDateMin_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateMin_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<Object> LoadJSDateSec_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateSec_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<Object> LoadJSDateCacheStamp_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o);
void StoreJSDateCacheStamp_0(compiler::CodeAssemblerState* state_, TNode<JSDate> p_o, TNode<Object> p_v);
TNode<JSReceiver> LoadJSAsyncFromSyncIteratorSyncIterator_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncFromSyncIterator> p_o);
void StoreJSAsyncFromSyncIteratorSyncIterator_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncFromSyncIterator> p_o, TNode<JSReceiver> p_v);
TNode<Object> LoadJSAsyncFromSyncIteratorNext_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncFromSyncIterator> p_o);
void StoreJSAsyncFromSyncIteratorNext_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncFromSyncIterator> p_o, TNode<Object> p_v);
TNode<String> LoadJSStringIteratorString_0(compiler::CodeAssemblerState* state_, TNode<JSStringIterator> p_o);
void StoreJSStringIteratorString_0(compiler::CodeAssemblerState* state_, TNode<JSStringIterator> p_o, TNode<String> p_v);
TNode<Smi> LoadJSStringIteratorIndex_0(compiler::CodeAssemblerState* state_, TNode<JSStringIterator> p_o);
void StoreJSStringIteratorIndex_0(compiler::CodeAssemblerState* state_, TNode<JSStringIterator> p_o, TNode<Smi> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_OBJECTS_TQ_H_
